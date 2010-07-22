/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativeexpression.h"
#include "private/qdeclarativeexpression_p.h"

#include "private/qdeclarativeengine_p.h"
#include "private/qdeclarativecontext_p.h"
#include "private/qdeclarativerewrite_p.h"
#include "private/qdeclarativecompiler_p.h"
#include "private/qdeclarativeglobalscriptclass_p.h"

#include <QtCore/qdebug.h>
#include <QtScript/qscriptprogram.h>

#include <private/qscriptdeclarativeclass_p.h>

QT_BEGIN_NAMESPACE

bool QDeclarativeDelayedError::addError(QDeclarativeEnginePrivate *e)
{
    if (!e) return false;

    if (e->inProgressCreations == 0) return false; // Not in construction

    if (prevError) return true; // Already in error chain

    prevError = &e->erroredBindings;
    nextError = e->erroredBindings;
    e->erroredBindings = this;
    if (nextError) nextError->prevError = &nextError;

    return true;
}

QDeclarativeExpressionData::QDeclarativeExpressionData()
: q(0), dataRef(0), expressionFunctionValid(false), expressionRewritten(false), me(0), 
  trackChange(false), isShared(false), line(-1), guardList(0), guardListLength(0)
{
}

QDeclarativeExpressionData::~QDeclarativeExpressionData()
{
    if (guardList) { delete [] guardList; guardList = 0; }
    if (dataRef) dataRef->release();
}

QDeclarativeExpressionPrivate::QDeclarativeExpressionPrivate()
: data(new QDeclarativeExpressionData)
{
    data->q = this;
}

QDeclarativeExpressionPrivate::QDeclarativeExpressionPrivate(QDeclarativeExpressionData *d)
: data(d)
{
    data->q = this;
}

QDeclarativeExpressionPrivate::~QDeclarativeExpressionPrivate()
{
    if (data) { 
        delete [] data->guardList; 
        data->guardList = 0; 
        data->guardListLength = 0; 
        data->q = 0; 
        data->release(); 
        data = 0; 
    }
}

void QDeclarativeExpressionPrivate::init(QDeclarativeContextData *ctxt, const QString &expr, 
                                         QObject *me)
{
    data->expression = expr;

    data->QDeclarativeAbstractExpression::setContext(ctxt);
    data->me = me;
}

void QDeclarativeExpressionPrivate::init(QDeclarativeContextData *ctxt, void *expr, QDeclarativeRefCount *rc, 
                                         QObject *me, const QString &url, int lineNumber)
{
    data->url = url;
    data->line = lineNumber;

    if (data->dataRef) data->dataRef->release();
    data->dataRef = rc;
    if (data->dataRef) data->dataRef->addref();

    quint32 *exprData = (quint32 *)expr;
    QDeclarativeCompiledData *dd = (QDeclarativeCompiledData *)rc;

    data->expressionRewritten = true;
    data->expression = QString::fromRawData((QChar *)(exprData + 2), exprData[1]);

    int progIdx = *(exprData);
    bool isShared = progIdx & 0x80000000;
    progIdx &= 0x7FFFFFFF;

    QDeclarativeEngine *engine = ctxt->engine;
    QDeclarativeEnginePrivate *ep = QDeclarativeEnginePrivate::get(engine);
    QScriptEngine *scriptEngine = QDeclarativeEnginePrivate::getScriptEngine(engine);

    if (isShared) {

        if (!dd->cachedClosures.at(progIdx)) {
            QScriptContext *scriptContext = QScriptDeclarativeClass::pushCleanContext(scriptEngine);
            scriptContext->pushScope(ep->contextClass->newSharedContext());
            scriptContext->pushScope(ep->globalClass->globalObject());
            dd->cachedClosures[progIdx] = new QScriptValue(scriptEngine->evaluate(data->expression, data->url, data->line));
            scriptEngine->popContext();
        }

        data->expressionFunction = *dd->cachedClosures.at(progIdx);
        data->isShared = true;
        data->expressionFunctionValid = true;

    } else {

#if !defined(Q_OS_SYMBIAN) //XXX Why doesn't this work?
        if (!dd->cachedPrograms.at(progIdx)) {
            dd->cachedPrograms[progIdx] =
                new QScriptProgram(data->expression, data->url, data->line);
        }

        data->expressionFunction = evalInObjectScope(ctxt, me, *dd->cachedPrograms.at(progIdx), 
                                                     &data->expressionContext);
#else
        data->expressionFunction = evalInObjectScope(ctxt, me, data->expression, 
                                                     &data->expressionContext);
#endif

        data->expressionFunctionValid = true;
    }

    data->QDeclarativeAbstractExpression::setContext(ctxt);
    data->me = me;
}

QScriptValue QDeclarativeExpressionPrivate::evalInObjectScope(QDeclarativeContextData *context, QObject *object, 
                                                              const QString &program, const QString &fileName,
                                                              int lineNumber, QScriptValue *contextObject)
{
    QDeclarativeEnginePrivate *ep = QDeclarativeEnginePrivate::get(context->engine);
    QScriptContext *scriptContext = QScriptDeclarativeClass::pushCleanContext(&ep->scriptEngine);
    if (contextObject) {
        *contextObject = ep->contextClass->newContext(context, object);
        scriptContext->pushScope(*contextObject);
    } else {
        scriptContext->pushScope(ep->contextClass->newContext(context, object));
    }
    scriptContext->pushScope(ep->globalClass->globalObject());
    QScriptValue rv = ep->scriptEngine.evaluate(program, fileName, lineNumber);
    ep->scriptEngine.popContext();
    return rv;
}

QScriptValue QDeclarativeExpressionPrivate::evalInObjectScope(QDeclarativeContextData *context, QObject *object, 
                                                              const QScriptProgram &program, 
                                                              QScriptValue *contextObject)
{
    QDeclarativeEnginePrivate *ep = QDeclarativeEnginePrivate::get(context->engine);
    QScriptContext *scriptContext = QScriptDeclarativeClass::pushCleanContext(&ep->scriptEngine);
    if (contextObject) {
        *contextObject = ep->contextClass->newContext(context, object);
        scriptContext->pushScope(*contextObject);
    } else {
        scriptContext->pushScope(ep->contextClass->newContext(context, object));
    }
    scriptContext->pushScope(ep->globalClass->globalObject());
    QScriptValue rv = ep->scriptEngine.evaluate(program);
    ep->scriptEngine.popContext();
    return rv;
}

/*!
    \class QDeclarativeExpression
  \since 4.7
    \brief The QDeclarativeExpression class evaluates JavaScript in a QML context.
*/

/*!
    Create an invalid QDeclarativeExpression.

    As the expression will not have an associated QDeclarativeContext, this will be a
    null expression object and its value will always be an invalid QVariant.
 */
QDeclarativeExpression::QDeclarativeExpression()
: QObject(*new QDeclarativeExpressionPrivate, 0)
{
}

/*!  \internal */
QDeclarativeExpression::QDeclarativeExpression(QDeclarativeContextData *ctxt, void *expr,
                                               QDeclarativeRefCount *rc, QObject *me, 
                                               const QString &url, int lineNumber,
                                               QDeclarativeExpressionPrivate &dd)
: QObject(dd, 0)
{
    Q_D(QDeclarativeExpression);
    d->init(ctxt, expr, rc, me, url, lineNumber);
}

/*!
    Create a QDeclarativeExpression object that is a child of \a parent.

    The \a expression JavaScript will be executed in the \a ctxt QDeclarativeContext.
    If specified, the \a scope object's properties will also be in scope during
    the expression's execution.
*/
QDeclarativeExpression::QDeclarativeExpression(QDeclarativeContext *ctxt,
                                               QObject *scope,
                                               const QString &expression,
                                               QObject *parent)
: QObject(*new QDeclarativeExpressionPrivate, parent)
{
    Q_D(QDeclarativeExpression);
    d->init(QDeclarativeContextData::get(ctxt), expression, scope);
}

/*! 
    \internal
*/
QDeclarativeExpression::QDeclarativeExpression(QDeclarativeContextData *ctxt, QObject *scope,
                                               const QString &expression)
: QObject(*new QDeclarativeExpressionPrivate, 0)
{
    Q_D(QDeclarativeExpression);
    d->init(ctxt, expression, scope);
}

/*!  \internal */
QDeclarativeExpression::QDeclarativeExpression(QDeclarativeContextData *ctxt, QObject *scope,
                                               const QString &expression, QDeclarativeExpressionPrivate &dd)
: QObject(dd, 0)
{
    Q_D(QDeclarativeExpression);
    d->init(ctxt, expression, scope);
}

/*!
    Destroy the QDeclarativeExpression instance.
*/
QDeclarativeExpression::~QDeclarativeExpression()
{
}

/*!
    Returns the QDeclarativeEngine this expression is associated with, or 0 if there
    is no association or the QDeclarativeEngine has been destroyed.
*/
QDeclarativeEngine *QDeclarativeExpression::engine() const
{
    Q_D(const QDeclarativeExpression);
    return d->data->context()?d->data->context()->engine:0;
}

/*!
    Returns the QDeclarativeContext this expression is associated with, or 0 if there
    is no association or the QDeclarativeContext has been destroyed.
*/
QDeclarativeContext *QDeclarativeExpression::context() const
{
    Q_D(const QDeclarativeExpression);
    QDeclarativeContextData *data = d->data->context();
    return data?data->asQDeclarativeContext():0;
}

/*!
    Returns the expression string.
*/
QString QDeclarativeExpression::expression() const
{
    Q_D(const QDeclarativeExpression);
    return d->data->expression;
}

/*!
    Set the expression to \a expression.
*/
void QDeclarativeExpression::setExpression(const QString &expression)
{
    Q_D(QDeclarativeExpression);

    d->clearGuards();

    d->data->expression = expression;
    d->data->expressionFunctionValid = false;
    d->data->expressionRewritten = false;
    d->data->expressionFunction = QScriptValue();
}

void QDeclarativeExpressionPrivate::exceptionToError(QScriptEngine *scriptEngine, 
                                            QDeclarativeError &error)
{
    if (scriptEngine->hasUncaughtException() && 
        scriptEngine->uncaughtException().isError()) {

        QString fileName;
        int lineNumber = scriptEngine->uncaughtExceptionLineNumber();

        QScriptValue exception = scriptEngine->uncaughtException();
        QLatin1String fileNameProp("fileName");

        if (!exception.property(fileNameProp).toString().isEmpty()){
            fileName = exception.property(fileNameProp).toString();
        } else {
            fileName = QLatin1String("<Unknown File>");
        }

        error.setUrl(QUrl(fileName));
        error.setLine(lineNumber);
        error.setColumn(-1);
        error.setDescription(exception.toString());
    } else {
        error = QDeclarativeError();
    }
}

QScriptValue QDeclarativeExpressionPrivate::eval(QObject *secondaryScope, bool *isUndefined)
{
    QDeclarativeExpressionData *data = this->data;
    QDeclarativeEngine *engine = data->context()->engine;
    QDeclarativeEnginePrivate *ep = QDeclarativeEnginePrivate::get(engine);

    QScriptEngine *scriptEngine = QDeclarativeEnginePrivate::getScriptEngine(engine);

    if (!data->expressionFunctionValid) {

        QScriptContext *scriptContext = QScriptDeclarativeClass::pushCleanContext(scriptEngine);
        data->expressionContext = ep->contextClass->newContext(data->context(), data->me);
        scriptContext->pushScope(data->expressionContext);
        scriptContext->pushScope(ep->globalClass->globalObject());

        if (data->expressionRewritten) {
            data->expressionFunction = scriptEngine->evaluate(data->expression, 
                                                              data->url, data->line);
        } else {
            QDeclarativeRewrite::RewriteBinding rewriteBinding;

            bool ok = true;
            const QString code = rewriteBinding(data->expression, &ok);
            if (!ok) {
                scriptEngine->popContext();
                return QScriptValue();
            }
            data->expressionFunction = scriptEngine->evaluate(code, data->url, data->line);
        }

        scriptEngine->popContext();
        data->expressionFunctionValid = true;
    }

    QDeclarativeContextData *oldSharedContext = 0;
    QObject *oldSharedScope = 0;
    QObject *oldOverride = 0;
    if (data->isShared) {
        oldSharedContext = ep->sharedContext;
        oldSharedScope = ep->sharedScope;
        ep->sharedContext = data->context();
        ep->sharedScope = data->me;
    } else {
        oldOverride = ep->contextClass->setOverrideObject(data->expressionContext, secondaryScope);
    }

    QScriptValue svalue = data->expressionFunction.call();

    if (data->isShared) {
        ep->sharedContext = oldSharedContext;
        ep->sharedScope = oldSharedScope;
    } else {
        ep->contextClass->setOverrideObject(data->expressionContext, oldOverride);
    }

    if (isUndefined)
        *isUndefined = svalue.isUndefined() || scriptEngine->hasUncaughtException();

    // Handle exception
    if (scriptEngine->hasUncaughtException()) {
       exceptionToError(scriptEngine, data->error);
       scriptEngine->clearExceptions();
       return QScriptValue();
    } else {
        data->error = QDeclarativeError();
        return svalue;
    }
}

QScriptValue QDeclarativeExpressionPrivate::scriptValue(QObject *secondaryScope, bool *isUndefined)
{
    Q_Q(QDeclarativeExpression);
    Q_ASSERT(q->engine());

    if (data->expression.isEmpty())
        return QScriptValue();

    QDeclarativeEnginePrivate *ep = QDeclarativeEnginePrivate::get(q->engine());

    QDeclarativeExpression *lastCurrentExpression = ep->currentExpression;
    bool lastCaptureProperties = ep->captureProperties;
    QPODVector<QDeclarativeEnginePrivate::CapturedProperty> lastCapturedProperties;
    ep->capturedProperties.copyAndClear(lastCapturedProperties);

    ep->currentExpression = q;
    ep->captureProperties = data->trackChange;

    // This object might be deleted during the eval
    QDeclarativeExpressionData *localData = data;
    localData->addref();

    QScriptValue value = eval(secondaryScope, isUndefined);

    ep->currentExpression = lastCurrentExpression;
    ep->captureProperties = lastCaptureProperties;

    // Check if we were deleted
    if (localData->q) {
        if ((!data->trackChange || !ep->capturedProperties.count()) && data->guardList) {
            clearGuards();
        } else if(data->trackChange) {
            updateGuards(ep->capturedProperties);
        }
    }

    localData->release();

    lastCapturedProperties.copyAndClear(ep->capturedProperties);

    return value;
}

QVariant QDeclarativeExpressionPrivate::value(QObject *secondaryScope, bool *isUndefined)
{
    Q_Q(QDeclarativeExpression);

    if (!data || !data->context() || !data->context()->isValid()) {
        qWarning("QDeclarativeExpression: Attempted to evaluate an expression in an invalid context");
        return QVariant();
    }

    QDeclarativeEnginePrivate *ep = QDeclarativeEnginePrivate::get(q->engine());

    return ep->scriptValueToVariant(scriptValue(secondaryScope, isUndefined), qMetaTypeId<QList<QObject*> >());
}

/*!
    Evaulates the expression, returning the result of the evaluation,
    or an invalid QVariant if the expression is invalid or has an error.

    \a valueIsUndefined is set to true if the expression resulted in an
    undefined value.

    \sa hasError(), error()
*/
QVariant QDeclarativeExpression::evaluate(bool *valueIsUndefined)
{
    Q_D(QDeclarativeExpression);
    return d->value(0, valueIsUndefined);
}

/*!
Returns true if the valueChanged() signal is emitted when the expression's evaluated
value changes.
*/
bool QDeclarativeExpression::notifyOnValueChanged() const
{
    Q_D(const QDeclarativeExpression);
    return d->data->trackChange;
}

/*!
  Sets whether the valueChanged() signal is emitted when the
  expression's evaluated value changes.

  If \a notifyOnChange is true, the QDeclarativeExpression will
  monitor properties involved in the expression's evaluation, and emit
  QDeclarativeExpression::valueChanged() if they have changed.  This
  allows an application to ensure that any value associated with the
  result of the expression remains up to date.

  If \a notifyOnChange is false (default), the QDeclarativeExpression
  will not montitor properties involved in the expression's
  evaluation, and QDeclarativeExpression::valueChanged() will never be
  emitted.  This is more efficient if an application wants a "one off"
  evaluation of the expression.
*/
void QDeclarativeExpression::setNotifyOnValueChanged(bool notifyOnChange)
{
    Q_D(QDeclarativeExpression);
    d->data->trackChange = notifyOnChange;
}

/*!
    Returns the source file URL for this expression.  The source location must
    have been previously set by calling setSourceLocation().
*/
QString QDeclarativeExpression::sourceFile() const
{
    Q_D(const QDeclarativeExpression);
    return d->data->url;
}

/*!
    Returns the source file line number for this expression.  The source location 
    must have been previously set by calling setSourceLocation().
*/
int QDeclarativeExpression::lineNumber() const
{
    Q_D(const QDeclarativeExpression);
    return d->data->line;
}

/*!
    Set the location of this expression to \a line of \a url. This information
    is used by the script engine.
*/
void QDeclarativeExpression::setSourceLocation(const QString &url, int line)
{
    Q_D(QDeclarativeExpression);
    d->data->url = url;
    d->data->line = line;
}

/*!
    Returns the expression's scope object, if provided, otherwise 0.

    In addition to data provided by the expression's QDeclarativeContext, the scope
    object's properties are also in scope during the expression's evaluation.
*/
QObject *QDeclarativeExpression::scopeObject() const
{
    Q_D(const QDeclarativeExpression);
    return d->data->me;
}

/*!
    Returns true if the last call to evaluate() resulted in an error,
    otherwise false.
    
    \sa error(), clearError()
*/
bool QDeclarativeExpression::hasError() const
{
    Q_D(const QDeclarativeExpression);
    return d->data->error.isValid();
}

/*!
    Clear any expression errors.  Calls to hasError() following this will
    return false.

    \sa hasError(), error()
*/
void QDeclarativeExpression::clearError()
{
    Q_D(QDeclarativeExpression);
    d->data->error = QDeclarativeError();
}

/*!
    Return any error from the last call to evaluate().  If there was no error,
    this returns an invalid QDeclarativeError instance.

    \sa hasError(), clearError()
*/

QDeclarativeError QDeclarativeExpression::error() const
{
    Q_D(const QDeclarativeExpression);
    return d->data->error;
}

/*! \internal */
void QDeclarativeExpressionPrivate::_q_notify()
{
    emitValueChanged();
}

void QDeclarativeExpressionPrivate::clearGuards()
{
    delete [] data->guardList; 
    data->guardList = 0; 
    data->guardListLength = 0;
}

void QDeclarativeExpressionPrivate::updateGuards(const QPODVector<QDeclarativeEnginePrivate::CapturedProperty> &properties)
{
    Q_Q(QDeclarativeExpression);

    static int notifyIdx = -1;
    if (notifyIdx == -1) 
        notifyIdx = QDeclarativeExpression::staticMetaObject.indexOfMethod("_q_notify()");

    if (properties.count() != data->guardListLength) {
        QDeclarativeNotifierEndpoint *newGuardList = 
            new QDeclarativeNotifierEndpoint[properties.count()];

        for (int ii = 0; ii < qMin(data->guardListLength, properties.count()); ++ii) 
           data->guardList[ii].copyAndClear(newGuardList[ii]);

        delete [] data->guardList;
        data->guardList = newGuardList;
        data->guardListLength = properties.count();
    }

    bool outputWarningHeader = false;
    bool noChanges = true;
    for (int ii = 0; ii < properties.count(); ++ii) {
        QDeclarativeNotifierEndpoint &guard = data->guardList[ii];
        const QDeclarativeEnginePrivate::CapturedProperty &property = properties.at(ii);

        guard.target = q;
        guard.targetMethod = notifyIdx;

        if (property.notifier != 0) {

            if (!noChanges && guard.isConnected(property.notifier)) {
                // Nothing to do

            } else {
                noChanges = false;

                bool existing = false;
                for (int jj = 0; !existing && jj < ii; ++jj) 
                    if (data->guardList[jj].isConnected(property.notifier)) 
                        existing = true;

                if (existing) {
                    // duplicate
                    guard.disconnect();
                } else {
                    guard.connect(property.notifier);
                }
            }


        } else if (property.notifyIndex != -1) {

            if (!noChanges && guard.isConnected(property.object, property.notifyIndex)) {
                // Nothing to do

            } else {
                noChanges = false;

                bool existing = false;
                for (int jj = 0; !existing && jj < ii; ++jj) 
                    if (data->guardList[jj].isConnected(property.object, property.notifyIndex)) 
                        existing = true;

                if (existing) {
                    // duplicate
                    guard.disconnect();
                } else {
                    guard.connect(property.object, property.notifyIndex);
                }
            }

        } else {
            if (!outputWarningHeader) {
                outputWarningHeader = true;
                qWarning() << "QDeclarativeExpression: Expression" << q->expression()
                           << "depends on non-NOTIFYable properties:";
            }

            const QMetaObject *metaObj = property.object->metaObject();
            QMetaProperty metaProp = metaObj->property(property.coreIndex);

            qWarning().nospace() << "    " << metaObj->className() << "::" << metaProp.name();
        }
    }
}

/*!
    \fn void QDeclarativeExpression::valueChanged()

    Emitted each time the expression value changes from the last time it was
    evaluated.  The expression must have been evaluated at least once (by
    calling QDeclarativeExpression::evaluate()) before this signal will be emitted.
*/

void QDeclarativeExpressionPrivate::emitValueChanged()
{
    Q_Q(QDeclarativeExpression);
    emit q->valueChanged();
}

QDeclarativeAbstractExpression::QDeclarativeAbstractExpression()
: m_context(0), m_prevExpression(0), m_nextExpression(0)
{
}

QDeclarativeAbstractExpression::~QDeclarativeAbstractExpression()
{
    if (m_prevExpression) {
        *m_prevExpression = m_nextExpression;
        if (m_nextExpression) 
            m_nextExpression->m_prevExpression = m_prevExpression;
    }
}

QDeclarativeContextData *QDeclarativeAbstractExpression::context() const
{
    return m_context;
}

void QDeclarativeAbstractExpression::setContext(QDeclarativeContextData *context)
{
    if (m_prevExpression) {
        *m_prevExpression = m_nextExpression;
        if (m_nextExpression) 
            m_nextExpression->m_prevExpression = m_prevExpression;
        m_prevExpression = 0;
        m_nextExpression = 0;
    }

    m_context = context;

    if (m_context) {
        m_nextExpression = m_context->expressions;
        if (m_nextExpression) 
            m_nextExpression->m_prevExpression = &m_nextExpression;
        m_prevExpression = &context->expressions;
        m_context->expressions = this;
    }
}

void QDeclarativeAbstractExpression::refresh()
{
}

bool QDeclarativeAbstractExpression::isValid() const
{
    return m_context != 0;
}

QT_END_NAMESPACE

#include <moc_qdeclarativeexpression.cpp>
