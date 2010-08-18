/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite of the Qt Toolkit.
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
#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include <QtGui/QImage>

#include <qstatictext.h>
#include <qpaintengine.h>

#include <private/qstatictext_p.h>
#include <private/qapplication_p.h>

// #define DEBUG_SAVE_IMAGE

class tst_QStaticText: public QObject
{
    Q_OBJECT

private:
    bool supportsTransformations() const;

private slots:
    void init();
    void cleanup();

    void constructionAndDestruction();
    void drawToPoint_data();
    void drawToPoint();
    void drawToRect_data();
    void drawToRect();
    void setFont();
    void setTextWidth();
    void prepareToCorrectData();
    void prepareToWrongData();

    void translatedPainter();
    void rotatedPainter();
    void scaledPainter();
    void projectedPainter();
    void rotatedScaledAndTranslatedPainter();
    void transformationChanged();    

    void plainTextVsRichText();

    void setPenPlainText();
    void setPenRichText();
    void richTextOverridesPen();
};

void tst_QStaticText::init()
{
}

void tst_QStaticText::cleanup()
{
}

void tst_QStaticText::constructionAndDestruction()
{
    QStaticText text("My text");
}

Q_DECLARE_METATYPE(QStaticText::PerformanceHint)
void tst_QStaticText::drawToPoint_data()
{
    QTest::addColumn<QStaticText::PerformanceHint>("performanceHint");

    QTest::newRow("Moderate caching") << QStaticText::ModerateCaching;
    QTest::newRow("Aggressive caching") << QStaticText::AggressiveCaching;
}

void tst_QStaticText::drawToPoint()
{
    QFETCH(QStaticText::PerformanceHint, performanceHint);

    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.drawText(11, 12, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextFormat(Qt::PlainText);
        text.setPerformanceHint(performanceHint);
        p.drawStaticText(QPointF(11, 12 - QFontMetricsF(p.font()).ascent()), text);
    }

    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::drawToRect_data()
{
    QTest::addColumn<QStaticText::PerformanceHint>("performanceHint");

    QTest::newRow("Moderate caching") << QStaticText::ModerateCaching;
    QTest::newRow("Aggressive caching") << QStaticText::AggressiveCaching;
}

void tst_QStaticText::drawToRect()
{
    QFETCH(QStaticText::PerformanceHint, performanceHint);

    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.drawText(QRectF(11, 12, 10, 500), "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextWidth(10),
        p.setClipRect(QRectF(11, 12, 10, 500));
        text.setPerformanceHint(performanceHint);
        text.setTextFormat(Qt::PlainText);
        p.drawStaticText(QPointF(11, 12), text);
    }

#if defined(DEBUG_SAVE_IMAGE)
    imageDrawText.save("drawToRect_imageDrawText.png");
    imageDrawStaticText.save("drawToRect_imageDrawStaticText.png");
#endif

    QCOMPARE(imageDrawStaticText, imageDrawText);   
}

void tst_QStaticText::prepareToCorrectData()
{
    QTransform transform;
    transform.scale(2.0, 2.0);
    transform.rotate(90, Qt::ZAxis);

    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.setTransform(transform);
        p.drawText(11, 12, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        p.setTransform(transform);
        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.prepare(transform, p.font());
        text.setTextFormat(Qt::PlainText);
        p.drawStaticText(QPointF(11, 12  - QFontMetricsF(p.font()).ascent()), text);
    }

    if (!supportsTransformations())
      QEXPECT_FAIL("", "Graphics system does not support transformed text on this platform", Abort);
    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::prepareToWrongData()
{
    QTransform transform;
    transform.scale(2.0, 2.0);
    transform.rotate(90, Qt::ZAxis);

    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.drawText(11, 12, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.prepare(transform, p.font());
        text.setTextFormat(Qt::PlainText);
        p.drawStaticText(QPointF(11, 12  - QFontMetricsF(p.font()).ascent()), text);
    }

    QCOMPARE(imageDrawStaticText, imageDrawText);
}


void tst_QStaticText::setFont()
{
    QFont font = QApplication::font();
    font.setBold(true);
    font.setPointSize(28);

    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.drawText(QRectF(0, 0, 1000, 1000), 0, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");

        p.setFont(font);
        p.drawText(QRectF(11, 120, 1000, 1000), 0, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);

        QStaticText text;
        text.setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextFormat(Qt::PlainText);

        p.drawStaticText(0, 0, text);

        p.setFont(font);
        p.drawStaticText(11, 120, text);
    }

#if defined(DEBUG_SAVE_IMAGE)
    imageDrawText.save("setFont_imageDrawText.png");
    imageDrawStaticText.save("setFont_imageDrawStaticText.png");
#endif

    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::setTextWidth()
{
    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.drawText(QRectF(11, 12, 10, 500), "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextWidth(10);
        p.setClipRect(QRectF(11, 12, 10, 500));
        p.drawStaticText(QPointF(11, 12), text);
    }

    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::translatedPainter()
{
    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.translate(100, 200);

        p.drawText(11, 12, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        p.translate(100, 200);

        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextFormat(Qt::PlainText);

        p.drawStaticText(QPointF(11, 12 - QFontMetricsF(p.font()).ascent()), text);
    }

    QCOMPARE(imageDrawStaticText, imageDrawText);
}

bool tst_QStaticText::supportsTransformations() const
{
    QPixmap pm(10, 10);
    QPainter p(&pm);
    QPaintEngine *engine = p.paintEngine();

    QPaintEngine::Type type = engine->type();

    if (type == QPaintEngine::OpenGL
#if !defined Q_WS_WIN
        || type == QPaintEngine::Raster
#endif
        )
        return false;

    return true;
}

void tst_QStaticText::rotatedPainter()
{
    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.rotate(30.0);
        p.drawText(QRectF(0, 0, 1000, 100), 0, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextFormat(Qt::PlainText);

        QPainter p(&imageDrawStaticText);
        p.rotate(30.0);
        p.drawStaticText(QPoint(0, 0), text);
    }

#if defined(DEBUG_SAVE_IMAGE)
    imageDrawText.save("rotatedPainter_imageDrawText.png");
    imageDrawStaticText.save("rotatedPainter_imageDrawStaticText.png");
#endif

    if (!supportsTransformations())
      QEXPECT_FAIL("", "Graphics system does not support transformed text on this platform", Abort);
    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::scaledPainter()
{
    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.scale(2.0, 0.2);

        p.drawText(11, 12, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        p.scale(2.0, 0.2);

        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextFormat(Qt::PlainText);

        p.drawStaticText(QPointF(11, 12 - QFontMetricsF(p.font()).ascent()), text);
    }

    if (!supportsTransformations())
      QEXPECT_FAIL("", "Graphics system does not support transformed text on this platform", Abort);
    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::projectedPainter()
{
    QTransform transform;
    transform.rotate(90, Qt::XAxis);

    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.setTransform(transform);

        p.drawText(11, 12, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        p.setTransform(transform);

        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextFormat(Qt::PlainText);

        p.drawStaticText(QPointF(11, 12 - QFontMetricsF(p.font()).ascent()), text);
    }

    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::rotatedScaledAndTranslatedPainter()
{
    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.rotate(45.0);
        p.scale(2.0, 2.0);
        p.translate(100, 200);

        p.drawText(11, 12, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        p.rotate(45.0);
        p.scale(2.0, 2.0);
        p.translate(100, 200);

        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextFormat(Qt::PlainText);

        p.drawStaticText(QPointF(11, 12 - QFontMetricsF(p.font()).ascent()), text);
    }

#if defined(DEBUG_SAVE_IMAGE)
    imageDrawText.save("rotatedScaledAndPainter_imageDrawText.png");
    imageDrawStaticText.save("rotatedScaledAndPainter_imageDrawStaticText.png");
#endif

    if (!supportsTransformations())
      QEXPECT_FAIL("", "Graphics system does not support transformed text on this platform", Abort);
    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::transformationChanged()
{
    QPixmap imageDrawText(1000, 1000);
    imageDrawText.fill(Qt::white);
    {
        QPainter p(&imageDrawText);
        p.rotate(33.0);
        p.scale(0.5, 0.7);

        p.drawText(QRectF(0, 0, 1000, 1000), 0, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");

        p.scale(2.0, 2.5);
        p.drawText(QRectF(0, 0, 1000, 1000), 0, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    }

    QPixmap imageDrawStaticText(1000, 1000);
    imageDrawStaticText.fill(Qt::white);
    {
        QPainter p(&imageDrawStaticText);
        p.rotate(33.0);
        p.scale(0.5, 0.7);

        QStaticText text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        text.setTextFormat(Qt::PlainText);

        p.drawStaticText(QPointF(0, 0), text);

        p.scale(2.0, 2.5);
        p.drawStaticText(QPointF(0, 0), text);
    }

#if defined(DEBUG_SAVE_IMAGE)
    imageDrawText.save("transformationChanged_imageDrawText.png");
    imageDrawStaticText.save("transformationChanged_imageDrawStaticText.png");
#endif

    if (!supportsTransformations())
      QEXPECT_FAIL("", "Graphics system does not support transformed text on this platform", Abort);
    QCOMPARE(imageDrawStaticText, imageDrawText);
}

void tst_QStaticText::plainTextVsRichText()
{
    QPixmap imagePlainText(1000, 1000);
    imagePlainText.fill(Qt::white);
    {
        QPainter p(&imagePlainText);

        QStaticText staticText;
        staticText.setText("FOObar");
        staticText.setTextFormat(Qt::PlainText);

        p.drawStaticText(10, 10, staticText);
    }

    QPixmap imageRichText(1000, 1000);
    imageRichText.fill(Qt::white);
    {
        QPainter p(&imageRichText);

        QStaticText staticText;
        staticText.setText("<html><body>FOObar</body></html>");
        staticText.setTextFormat(Qt::RichText);

        p.drawStaticText(10, 10, staticText);
    }

#if defined(DEBUG_SAVE_IMAGE)
    imagePlainText.save("plainTextVsRichText_imagePlainText.png");
    imageRichText.save("plainTextVsRichText_imageRichText.png");
#endif

    QCOMPARE(imagePlainText, imageRichText);
}

void tst_QStaticText::setPenPlainText()
{
    QFont font = QApplication::font();
    font.setStyleStrategy(QFont::NoAntialias);

    QFontMetricsF fm(font);
    QPixmap image(qCeil(fm.width("XXXXX")), qCeil(fm.height()));
    image.fill(Qt::white);
    {
        QPainter p(&image);
        p.setFont(font);
        p.setPen(Qt::green);

        QStaticText staticText("XXXXX");
        staticText.setTextFormat(Qt::PlainText);
        p.drawStaticText(0, fm.ascent(), staticText);
    }

    QImage img = image.toImage();
    for (int x=0; x<img.width(); ++x) {
        for (int y=0; y<img.height(); ++y) {
            QRgb pixel = img.pixel(x, y);
            QVERIFY(pixel == QColor(Qt::white).rgba()
                    || pixel == QColor(Qt::green).rgba());
        }
    }
}

void tst_QStaticText::setPenRichText()
{
    QFont font = QApplication::font();
    font.setStyleStrategy(QFont::NoAntialias);

    QFontMetricsF fm(font);
    QPixmap image(qCeil(fm.width("XXXXX")), qCeil(fm.height()));
    image.fill(Qt::white);
    {
        QPainter p(&image);
        p.setFont(font);
        p.setPen(Qt::green);

        QStaticText staticText;
        staticText.setText("<html><body>XXXXX</body></html>");
        staticText.setTextFormat(Qt::RichText);
        p.drawStaticText(0, 0, staticText);
    }

    QImage img = image.toImage();
    for (int x=0; x<img.width(); ++x) {
        for (int y=0; y<img.height(); ++y) {
            QRgb pixel = img.pixel(x, y);
            QVERIFY(pixel == QColor(Qt::white).rgba()
                    || pixel == QColor(Qt::green).rgba());
        }
    }
}

void tst_QStaticText::richTextOverridesPen()
{
    QFont font = QApplication::font();
    font.setStyleStrategy(QFont::NoAntialias);

    QFontMetricsF fm(font);
    QPixmap image(qCeil(fm.width("XXXXX")), qCeil(fm.height()));
    image.fill(Qt::white);
    {
        QPainter p(&image);
        p.setFont(font);
        p.setPen(Qt::green);

        QStaticText staticText;
        staticText.setText("<html><body><font color=\"#ff0000\">XXXXX</font></body></html>");
        staticText.setTextFormat(Qt::RichText);
        p.drawStaticText(0, 0, staticText);
    }

    QImage img = image.toImage();
    for (int x=0; x<img.width(); ++x) {
        for (int y=0; y<img.height(); ++y) {
            QRgb pixel = img.pixel(x, y);
            QVERIFY(pixel == QColor(Qt::white).rgba()
                    || pixel == QColor(Qt::red).rgba());
        }
    }
}

QTEST_MAIN(tst_QStaticText)
#include "tst_qstatictext.moc"
