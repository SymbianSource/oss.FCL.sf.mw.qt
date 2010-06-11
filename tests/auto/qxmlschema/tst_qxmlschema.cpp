/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite module of the Qt Toolkit.
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

#include <QtTest/QtTest>

#ifdef QTEST_XMLPATTERNS

#include <QAbstractMessageHandler>
#include <QAbstractUriResolver>
#include <QtNetwork/QNetworkAccessManager>
#include <QXmlName>
#include <QXmlSchema>

#include "../qabstracturiresolver/TestURIResolver.h"
#include "../qxmlquery/MessageSilencer.h"

/*!
 \class tst_QXmlSchema
 \internal
 \brief Tests class QXmlSchema.

 This test is not intended for testing the engine, but the functionality specific
 to the QXmlSchema class.
 */
class tst_QXmlSchema : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void defaultConstructor() const;
    void copyConstructor() const;
    void constructorQXmlNamePool() const;
    void copyMutationTest() const;

    void isValid() const;
    void documentUri() const;

    void loadSchemaUrlSuccess() const;
    void loadSchemaUrlFail() const;
    void loadSchemaDeviceSuccess() const;
    void loadSchemaDeviceFail() const;
    void loadSchemaDataSuccess() const;
    void loadSchemaDataFail() const;

    void networkAccessManagerSignature() const;
    void networkAccessManagerDefaultValue() const;
    void networkAccessManager() const;

    void messageHandlerSignature() const;
    void messageHandlerDefaultValue() const;
    void messageHandler() const;

    void uriResolverSignature() const;
    void uriResolverDefaultValue() const;
    void uriResolver() const;
};

void tst_QXmlSchema::defaultConstructor() const
{
    /* Allocate instance in different orders. */
    {
        QXmlSchema schema;
    }

    {
        QXmlSchema schema1;
        QXmlSchema schema2;
    }

    {
        QXmlSchema schema1;
        QXmlSchema schema2;
        QXmlSchema schema3;
    }
}

void tst_QXmlSchema::copyConstructor() const
{
    /* Verify that we can take a const reference, and simply do a copy of a default constructed object. */
    {
        const QXmlSchema schema1;
        QXmlSchema schema2(schema1);
    }

    /* Copy twice. */
    {
        const QXmlSchema schema1;
        QXmlSchema schema2(schema1);
        QXmlSchema schema3(schema2);
    }

    /* Verify that copying default values works. */
    {
        const QXmlSchema schema1;
        const QXmlSchema schema2(schema1);
        QCOMPARE(schema2.messageHandler(), schema1.messageHandler());
        QCOMPARE(schema2.uriResolver(), schema1.uriResolver());
        QCOMPARE(schema2.networkAccessManager(), schema1.networkAccessManager());
        QCOMPARE(schema2.isValid(), schema1.isValid());
    }
}

void tst_QXmlSchema::constructorQXmlNamePool() const
{
    QXmlSchema schema;

    QXmlNamePool np = schema.namePool();

    const QXmlName name(np, QLatin1String("localName"),
                            QLatin1String("http://example.com/"),
                            QLatin1String("prefix"));

    QXmlNamePool np2(schema.namePool());
    QCOMPARE(name.namespaceUri(np2), QString::fromLatin1("http://example.com/"));
    QCOMPARE(name.localName(np2), QString::fromLatin1("localName"));
    QCOMPARE(name.prefix(np2), QString::fromLatin1("prefix"));

    // make sure namePool() is const
    const QXmlSchema constSchema;
    np = constSchema.namePool();
}

void tst_QXmlSchema::copyMutationTest() const
{
    QXmlSchema schema1;
    QXmlSchema schema2(schema1);

    // check that everything is equal
    QVERIFY(schema2.messageHandler() == schema1.messageHandler());
    QVERIFY(schema2.uriResolver() == schema1.uriResolver());
    QVERIFY(schema2.networkAccessManager() == schema1.networkAccessManager());

    MessageSilencer handler;
    const TestURIResolver resolver;
    QNetworkAccessManager manager;

    // modify schema1
    schema1.setMessageHandler(&handler);
    schema1.setUriResolver(&resolver);
    schema1.setNetworkAccessManager(&manager);

    // check that schema2 is not effected by the modifications of schema1
    QVERIFY(schema2.messageHandler() != schema1.messageHandler());
    QVERIFY(schema2.uriResolver() != schema1.uriResolver());
    QVERIFY(schema2.networkAccessManager() != schema1.networkAccessManager());

    // modify schema1 further
    const QByteArray data( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                           "<xsd:schema"
                           "        xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\""
                           "        xmlns=\"http://qt.nokia.com/xmlschematest\""
                           "        targetNamespace=\"http://qt.nokia.com/xmlschematest\""
                           "        version=\"1.0\""
                           "        elementFormDefault=\"qualified\">"
                           "</xsd:schema>" );

    const QUrl documentUri("http://qt.nokia.com/xmlschematest");
    schema1.load(data, documentUri);

    QVERIFY(schema2.isValid() != schema1.isValid());
}

void tst_QXmlSchema::isValid() const
{
    /* Check default value. */
    QXmlSchema schema;
    QVERIFY(!schema.isValid());
}

void tst_QXmlSchema::documentUri() const
{
    const QByteArray data( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                           "<xsd:schema"
                           "        xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\""
                           "        xmlns=\"http://qt.nokia.com/xmlschematest\""
                           "        targetNamespace=\"http://qt.nokia.com/xmlschematest\""
                           "        version=\"1.0\""
                           "        elementFormDefault=\"qualified\">"
                           "</xsd:schema>" );

    const QUrl documentUri("http://qt.nokia.com/xmlschematest");
    QXmlSchema schema;
    schema.load(data, documentUri);

    QCOMPARE(documentUri, schema.documentUri());
}

void tst_QXmlSchema::loadSchemaUrlSuccess() const
{
/**
    TODO: put valid schema file on given url and enable test
    const QUrl url("http://notavailable/");

    QXmlSchema schema;
    QVERIFY(!schema.load(url));
*/
}

void tst_QXmlSchema::loadSchemaUrlFail() const
{
    const QUrl url("http://notavailable/");

    QXmlSchema schema;
    QVERIFY(!schema.load(url));
}

void tst_QXmlSchema::loadSchemaDeviceSuccess() const
{
    QByteArray data( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                     "<xsd:schema"
                     "        xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\""
                     "        xmlns=\"http://qt.nokia.com/xmlschematest\""
                     "        targetNamespace=\"http://qt.nokia.com/xmlschematest\""
                     "        version=\"1.0\""
                     "        elementFormDefault=\"qualified\">"
                     "</xsd:schema>" );

    QBuffer buffer(&data);
    buffer.open(QIODevice::ReadOnly);

    QXmlSchema schema;
    QVERIFY(schema.load(&buffer));
}

void tst_QXmlSchema::loadSchemaDeviceFail() const
{
    QByteArray data( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                     "<xsd:schema"
                     "        xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\""
                     "        xmlns=\"http://qt.nokia.com/xmlschematest\""
                     "        targetNamespace=\"http://qt.nokia.com/xmlschematest\""
                     "        version=\"1.0\""
                     "        elementFormDefault=\"qualified\">"
                     "</xsd:schema>" );

    QBuffer buffer(&data);
    // a closed device can not be loaded

    QXmlSchema schema;
    QVERIFY(!schema.load(&buffer));
}

void tst_QXmlSchema::loadSchemaDataSuccess() const
{
    const QByteArray data( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                           "<xsd:schema"
                           "        xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\""
                           "        xmlns=\"http://qt.nokia.com/xmlschematest\""
                           "        targetNamespace=\"http://qt.nokia.com/xmlschematest\""
                           "        version=\"1.0\""
                           "        elementFormDefault=\"qualified\">"
                           "</xsd:schema>" );
    QXmlSchema schema;
    QVERIFY(schema.load(data));
}

void tst_QXmlSchema::loadSchemaDataFail() const
{
    // empty schema can not be loaded
    const QByteArray data;

    QXmlSchema schema;
    QVERIFY(!schema.load(data));
}


void tst_QXmlSchema::networkAccessManagerSignature() const
{
    /* Const object. */
    const QXmlSchema schema;

    /* The function should be const. */
    schema.networkAccessManager();
}

void tst_QXmlSchema::networkAccessManagerDefaultValue() const
{
    /* Test that the default value of network access manager is not empty. */
    {
        QXmlSchema schema;
        QVERIFY(schema.networkAccessManager() != static_cast<QNetworkAccessManager*>(0));
    }
}

void tst_QXmlSchema::networkAccessManager() const
{
    /* Test that we return the network manager that was set. */
    {
        QNetworkAccessManager manager;
        QXmlSchema schema;
        schema.setNetworkAccessManager(&manager);
        QCOMPARE(schema.networkAccessManager(), &manager);
    }
}

void tst_QXmlSchema::messageHandlerSignature() const
{
    /* Const object. */
    const QXmlSchema schema;

    /* The function should be const. */
    schema.messageHandler();
}

void tst_QXmlSchema::messageHandlerDefaultValue() const
{
    /* Test that the default value of message handler is not empty. */
    {
        QXmlSchema schema;
        QVERIFY(schema.messageHandler() != static_cast<QAbstractMessageHandler*>(0));
    }
}

void tst_QXmlSchema::messageHandler() const
{
    /* Test that we return the message handler that was set. */
    {
        MessageSilencer handler;

        QXmlSchema schema;
        schema.setMessageHandler(&handler);
        QCOMPARE(schema.messageHandler(), static_cast<QAbstractMessageHandler *>(&handler));
    }
}

void tst_QXmlSchema::uriResolverSignature() const
{
    /* Const object. */
    const QXmlSchema schema;

    /* The function should be const. */
    schema.uriResolver();

    /* Const object. */
    const TestURIResolver resolver;

    /* This should compile */
    QXmlSchema schema2;
    schema2.setUriResolver(&resolver);
}

void tst_QXmlSchema::uriResolverDefaultValue() const
{
    /* Test that the default value of uri resolver is empty. */
    {
        QXmlSchema schema;
        QVERIFY(schema.uriResolver() == static_cast<QAbstractUriResolver*>(0));
    }
}

void tst_QXmlSchema::uriResolver() const
{
    /* Test that we return the uri resolver that was set. */
    {
        TestURIResolver resolver;

        QXmlSchema schema;
        schema.setUriResolver(&resolver);
        QCOMPARE(schema.uriResolver(), static_cast<const QAbstractUriResolver *>(&resolver));
    }
}

QTEST_MAIN(tst_QXmlSchema)

#include "tst_qxmlschema.moc"
#else //QTEST_PATTERNIST
QTEST_NOOP_MAIN
#endif
