/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_MaintainingReader_H
#define Patternist_MaintainingReader_H

#include <QSet>
#include <QSourceLocation>
#include <QStack>
#include <QStringList>
#include <QXmlStreamReader>

#include "qxpathhelper_p.h"
#include "qxslttokenlookup_p.h"

class QUrl;

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A structure that lists the optional and required
     * attributes of an element. Used with MaintainingReader.
     *
     * A constant source to misunderstandings is mixing up the order of
     * arguments for functions that takes a local name and a namespace. Be wary
     * of this.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @since 4.5
     */
    template<typename TokenLookupClass,
             typename LookupKey = typename TokenLookupClass::NodeName>
    class ElementDescription
    {
    public:
        typedef QHash<LookupKey, ElementDescription<TokenLookupClass, LookupKey> > Hash;
        QSet<typename TokenLookupClass::NodeName> requiredAttributes;
        QSet<typename TokenLookupClass::NodeName> optionalAttributes;
    };

    /**
     * @short Base class for tokenizers that reads XML formats. This is
     * XSLTTokenizer, and the W3C XML Schema parser.
     *
     * MaintainingReader is intended for sub-classing.
     *
     * @tparam TokenLookupClass The name of the class that is generated by
     * QTokenAutomaton and which supplies tokenizing tokens. For XSLTTokenizer,
     * this is XSLTTokenLookup, for instance.
     *
     * @tparam LookupKey The type that is passed to validateElement() and is
     * the key in ElementDescription. For the schema code, where elements have
     * different interpretations depending on context, the lookup key is hence
     * not equal element name.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @since 4.5
     */
    template<typename TokenLookupClass,
             typename LookupKey = typename TokenLookupClass::NodeName>
    class MaintainingReader : public QXmlStreamReader
                            , protected TokenLookupClass
    {
    protected:

        MaintainingReader(const typename ElementDescription<TokenLookupClass, LookupKey>::Hash &elementDescriptions,
                          const QSet<typename TokenLookupClass::NodeName> &standardAttributes,
                          const ReportContext::Ptr &context,
                          QIODevice *const queryDevice);

        virtual ~MaintainingReader();

        TokenType readNext();

        /**
         * Returns the name of the current element.
         */
        inline typename TokenLookupClass::NodeName currentElementName() const;

        /**
         * @short Convenience function for calling ReportContext::error().
         */
        void error(const QString &message,
                   const ReportContext::ErrorCode code) const;

        /**
         * @short Convenience function for calling ReportContext::warning().
         */
        void warning(const QString &message) const;

        /**
         * @short Returns the location of the document that MaintainingReader
         * is parsing. Used for error reporting
         */
        virtual QUrl documentURI() const = 0;

        /**
         * @short Returns @c true, if any attribute is allowed on the
         * element currently being validated.
         */
        virtual bool isAnyAttributeAllowed() const = 0;

        /**
         * QXmlStreamReader::isWhitespace() returns true for whitespace that is
         * not expressed as character references, while XSL-T operatates ontop
         * of the XDM, which means we needs to return true for those too.
         *
         * @see <a href="http://www.w3.org/TR/xslt20/#data-model">4 Data Model</a>
         */
        bool isWhitespace() const;

        /**
         * This function is not merged with handleStandardAttributes() because
         * handleStandardAttributes() needs to be called for all elements,
         * while validateElement() only applies to XSL-T elements.
         *
         * @see handleStandardAttributes()
         */
        void validateElement(const LookupKey name) const;

        QXmlStreamAttributes                                                    m_currentAttributes;

        bool                                                                    m_hasHandledStandardAttributes;

        /**
         * This stack mirrors the depth of elements in the parsed document. If
         * no @c xml:space is present on the current element, MaintainingReader
         * simply pushes the current top(). However, it never sets the value
         * depending on @c xml:space's value.
         */
        QStack<bool>                                                            m_stripWhitespace;

        /**
         * @short Returns the value for attribute by name \a name.
         *
         * If it doesn't exist, an error is raised.
         *
         * It is assumed that m_reader's current state is
         * QXmlStreamReader::StartElement.
         */
        QString readAttribute(const QString &localName,
                              const QString &namespaceURI = QString()) const;

        /**
         * @short Returns @c true if the current element has an attribute whose
         * name is @p namespaceURI and local name is @p localName.
         */
        bool hasAttribute(const QString &namespaceURI, const QString &localName) const;

        /**
         * @short Returns @c true if the current element has an attribute whose
         * local name is @p localName and namespace URI is null.
         */
        inline bool hasAttribute(const QString &localName) const;

    private:
        typename TokenLookupClass::NodeName                                     m_currentElementName;

        /**
         * This member is private, see the error() and warning() functions in
         * this class.
         */
        const ReportContext::Ptr                                                m_context;

        /**
         * Returns the current location that QXmlStreamReader has.
         */
        inline QSourceLocation currentLocation() const;

        const typename ElementDescription<TokenLookupClass, LookupKey>::Hash    m_elementDescriptions;
        const QSet<typename TokenLookupClass::NodeName>                         m_standardAttributes;
        Q_DISABLE_COPY(MaintainingReader)
    };

#include "qmaintainingreader.cpp"

}

QT_END_NAMESPACE
QT_END_HEADER

#endif

