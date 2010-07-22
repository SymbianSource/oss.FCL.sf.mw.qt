/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
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

#include "waveform.h"
#include "utils.h"
#include <QPainter>
#include <QResizeEvent>
#include <QDebug>


Waveform::Waveform(const QByteArray &buffer, QWidget *parent)
    :   QWidget(parent)
    ,   m_buffer(buffer)
    ,   m_dataLength(0)
    ,   m_position(0)
    ,   m_active(false)
    ,   m_tileLength(0)
    ,   m_tileArrayStart(0)
    ,   m_windowPosition(0)
    ,   m_windowLength(0)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    setMinimumHeight(50);
}

Waveform::~Waveform()
{
    deletePixmaps();
}

void Waveform::paintEvent(QPaintEvent * /*event*/)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::black);

    if (m_active) {
        WAVEFORM_DEBUG << "Waveform::paintEvent"
                       << "windowPosition" << m_windowPosition
                       << "windowLength" << m_windowLength;
        qint64 pos = m_windowPosition;
        const qint64 windowEnd = m_windowPosition + m_windowLength;
        int destLeft = 0;
        int destRight = 0;
        while (pos < windowEnd) {
            const TilePoint point = tilePoint(pos);
            WAVEFORM_DEBUG << "Waveform::paintEvent" << "pos" << pos
                           << "tileIndex" << point.index
                           << "positionOffset" << point.positionOffset
                           << "pixelOffset" << point.pixelOffset;

            if (point.index != NullIndex) {
                const Tile &tile = m_tiles[point.index];
                if (tile.painted) {
                    const qint64 sectionLength = qMin((m_tileLength - point.positionOffset),
                                                     (windowEnd - pos));
                    Q_ASSERT(sectionLength > 0);

                    const int sourceRight = tilePixelOffset(point.positionOffset + sectionLength);
                    destRight = windowPixelOffset(pos - m_windowPosition + sectionLength);

                    QRect destRect = rect();
                    destRect.setLeft(destLeft);
                    destRect.setRight(destRight);

                    QRect sourceRect(QPoint(), m_pixmapSize);
                    sourceRect.setLeft(point.pixelOffset);
                    sourceRect.setRight(sourceRight);

                    WAVEFORM_DEBUG << "Waveform::paintEvent" << "tileIndex" << point.index
                                   << "source" << point.pixelOffset << sourceRight
                                   << "dest" << destLeft << destRight;

                    painter.drawPixmap(destRect, *tile.pixmap, sourceRect);

                    destLeft = destRight;

                    if (point.index < m_tiles.count()) {
                        pos = tilePosition(point.index + 1);
                        WAVEFORM_DEBUG << "Waveform::paintEvent" << "pos ->" << pos;
                    } else {
                        // Reached end of tile array
                        WAVEFORM_DEBUG << "Waveform::paintEvent" << "reached end of tile array";
                        break;
                    }
                } else {
                    // Passed last tile which is painted
                    WAVEFORM_DEBUG << "Waveform::paintEvent" << "tile" << point.index << "not painted";
                    break;
                }
            } else {
                // pos is past end of tile array
                WAVEFORM_DEBUG << "Waveform::paintEvent" << "pos" << pos << "past end of tile array";
                break;
            }
        }

        WAVEFORM_DEBUG << "Waveform::paintEvent" << "final pos" << pos << "final x" << destRight;
    }
}

void Waveform::resizeEvent(QResizeEvent *event)
{
    if (event->size() != event->oldSize())
        createPixmaps(event->size());
}

void Waveform::initialize(const QAudioFormat &format, qint64 audioBufferSize, qint64 windowDurationUs)
{
    WAVEFORM_DEBUG << "Waveform::initialize"
                   << "audioBufferSize" << audioBufferSize
                   << "m_buffer.size()" << m_buffer.size()
                   << "windowDurationUs" << windowDurationUs;

    reset();

    m_format = format;

    // Calculate tile size
    m_tileLength = audioBufferSize;

    // Calculate window size
    m_windowLength = audioLength(m_format, windowDurationUs);

    // Calculate number of tiles required
    int nTiles;
    if (m_tileLength > m_windowLength) {
        nTiles = 2;
    } else {
        nTiles = m_windowLength / m_tileLength + 1;
        if (m_windowLength % m_tileLength)
            ++nTiles;
    }

    WAVEFORM_DEBUG << "Waveform::initialize"
                   << "tileLength" << m_tileLength
                   << "windowLength" << m_windowLength
                   << "nTiles" << nTiles;

    m_pixmaps.fill(0, nTiles);
    m_tiles.resize(nTiles);

    createPixmaps(rect().size());

    m_active = true;
}

void Waveform::reset()
{
    WAVEFORM_DEBUG << "Waveform::reset";

    m_dataLength = 0;
    m_position = 0;
    m_format = QAudioFormat();
    m_active = false;
    deletePixmaps();
    m_tiles.clear();
    m_tileLength = 0;
    m_tileArrayStart = 0;
    m_windowPosition = 0;
    m_windowLength = 0;
}

void Waveform::dataLengthChanged(qint64 length)
{
    WAVEFORM_DEBUG << "Waveform::dataLengthChanged" << length;
    const qint64 oldLength = m_dataLength;
    m_dataLength = length;

    if (m_active) {
        if (m_dataLength < oldLength)
            positionChanged(m_dataLength);
        else
            paintTiles();
    }
}

void Waveform::positionChanged(qint64 position)
{
    WAVEFORM_DEBUG << "Waveform::positionChanged" << position;

    if (position + m_windowLength > m_dataLength)
        position = m_dataLength - m_windowLength;

    m_position = position;

    setWindowPosition(position);
}

void Waveform::deletePixmaps()
{
    QPixmap *pixmap;
    foreach (pixmap, m_pixmaps)
        delete pixmap;
    m_pixmaps.clear();
}

void Waveform::createPixmaps(const QSize &widgetSize)
{
    m_pixmapSize = widgetSize;
    m_pixmapSize.setWidth(qreal(widgetSize.width()) * m_tileLength / m_windowLength);

    WAVEFORM_DEBUG << "Waveform::createPixmaps"
                   << "widgetSize" << widgetSize
                   << "pixmapSize" << m_pixmapSize;

    Q_ASSERT(m_tiles.count() == m_pixmaps.count());

    // (Re)create pixmaps
    for (int i=0; i<m_pixmaps.size(); ++i) {
        delete m_pixmaps[i];
        m_pixmaps[i] = 0;
        m_pixmaps[i] = new QPixmap(m_pixmapSize);
    }

    // Update tile pixmap pointers, and mark for repainting
    for (int i=0; i<m_tiles.count(); ++i) {
        m_tiles[i].pixmap = m_pixmaps[i];
        m_tiles[i].painted = false;
    }

    paintTiles();
}

void Waveform::setWindowPosition(qint64 position)
{
    WAVEFORM_DEBUG << "Waveform::setWindowPosition"
                   << "old" << m_windowPosition << "new" << position
                   << "tileArrayStart" << m_tileArrayStart;

    const qint64 oldPosition = m_windowPosition;
    m_windowPosition = position;

    if((m_windowPosition >= oldPosition) &&
        (m_windowPosition - m_tileArrayStart < (m_tiles.count() * m_tileLength))) {
        // Work out how many tiles need to be shuffled
        const qint64 offset = m_windowPosition - m_tileArrayStart;
        const int nTiles = offset / m_tileLength;
        shuffleTiles(nTiles);
    } else {
        resetTiles(m_windowPosition);
    }

    if(!paintTiles() && m_windowPosition != oldPosition)
        update();
}

qint64 Waveform::tilePosition(int index) const
{
    return m_tileArrayStart + index * m_tileLength;
}

Waveform::TilePoint Waveform::tilePoint(qint64 position) const
{
    TilePoint result;
    if (position >= m_tileArrayStart) {
        const qint64 tileArrayEnd = m_tileArrayStart + m_tiles.count() * m_tileLength;
        if (position < tileArrayEnd) {
            const qint64 offsetIntoTileArray = position - m_tileArrayStart;
            result.index = offsetIntoTileArray / m_tileLength;
            Q_ASSERT(result.index >= 0 && result.index <= m_tiles.count());
            result.positionOffset = offsetIntoTileArray % m_tileLength;
            result.pixelOffset = tilePixelOffset(result.positionOffset);
            Q_ASSERT(result.pixelOffset >= 0 && result.pixelOffset <= m_pixmapSize.width());
        }
    }

    return result;
}

int Waveform::tilePixelOffset(qint64 positionOffset) const
{
    Q_ASSERT(positionOffset >= 0 && positionOffset <= m_tileLength);
    const int result = (qreal(positionOffset) / m_tileLength) * m_pixmapSize.width();
    return result;
}

int Waveform::windowPixelOffset(qint64 positionOffset) const
{
    Q_ASSERT(positionOffset >= 0 && positionOffset <= m_windowLength);
    const int result = (qreal(positionOffset) / m_windowLength) * rect().width();
    return result;
}

bool Waveform::paintTiles()
{
    WAVEFORM_DEBUG << "Waveform::paintTiles";
    bool updateRequired = false;

    for (int i=0; i<m_tiles.count(); ++i) {
        const Tile &tile = m_tiles[i];
        if (!tile.painted) {
            const qint64 tileEnd = m_tileArrayStart + (i + 1) * m_tileLength;
            if (m_dataLength >= tileEnd) {
                paintTile(i);
                updateRequired = true;
            }
        }
    }

    if (updateRequired)
        update();

    return updateRequired;
}

void Waveform::paintTile(int index)
{
    WAVEFORM_DEBUG << "Waveform::paintTile" << "index" << index;

    const qint64 tileStart = m_tileArrayStart + index * m_tileLength;
    Q_ASSERT(m_dataLength >= tileStart + m_tileLength);

    Tile &tile = m_tiles[index];
    Q_ASSERT(!tile.painted);

    const qint16* base = reinterpret_cast<const qint16*>(m_buffer.constData());
    const qint16* buffer = base + (tileStart / 2);
    const int numSamples = m_tileLength / (2 * m_format.channels());

    QPainter painter(tile.pixmap);

    painter.fillRect(tile.pixmap->rect(), Qt::black);

    QPen pen(Qt::white);
    painter.setPen(pen);

    // Calculate initial PCM value
    qint16 previousPcmValue = 0;
    if (buffer > base)
        previousPcmValue = *(buffer - m_format.channels());

    // Calculate initial point
    const qreal previousRealValue = pcmToReal(previousPcmValue);
    const int originY = ((previousRealValue + 1.0) / 2) * m_pixmapSize.height();
    const QPoint origin(0, originY);

    QLine line(origin, origin);

    for (int i=0; i<numSamples; ++i) {
        const qint16* ptr = buffer + i * m_format.channels();
        const qint16 pcmValue = *ptr;
        const qreal realValue = pcmToReal(pcmValue);

        const int x = tilePixelOffset(i * 2 * m_format.channels());
        const int y = ((realValue + 1.0) / 2) * m_pixmapSize.height();

        line.setP2(QPoint(x, y));
        painter.drawLine(line);
        line.setP1(line.p2());
    }

    tile.painted = true;
}

void Waveform::shuffleTiles(int n)
{
    WAVEFORM_DEBUG << "Waveform::shuffleTiles" << "n" << n;

    while (n--) {
        Tile tile = m_tiles.first();
        tile.painted = false;
        m_tiles.erase(m_tiles.begin());
        m_tiles += tile;
        m_tileArrayStart += m_tileLength;
    }

    WAVEFORM_DEBUG << "Waveform::shuffleTiles" << "tileArrayStart" << m_tileArrayStart;
}

void Waveform::resetTiles(qint64 newStartPos)
{
    WAVEFORM_DEBUG << "Waveform::resetTiles" << "newStartPos" << newStartPos;

    QVector<Tile>::iterator i = m_tiles.begin();
    for ( ; i != m_tiles.end(); ++i)
        i->painted = false;

    m_tileArrayStart = newStartPos;
}

