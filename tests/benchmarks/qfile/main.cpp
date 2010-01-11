/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
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

#include <QDebug>
#include <QTemporaryFile>
#include <QFSFileEngine>
#include <QString>
#include <QDirIterator>

#include <qtest.h>

#include <stdio.h>

#ifdef Q_OS_WIN
# include <windows.h>
# include <atlbase.h>
#endif

#define BUFSIZE 1024*512
#define FACTOR 1024*512
#define TF_SIZE FACTOR*81

// 10 predefined (but random() seek positions
// hardcoded to be comparable over several runs
const int seekpos[] = {TF_SIZE*0.52,
                       TF_SIZE*0.23,
                       TF_SIZE*0.73,
                       TF_SIZE*0.77,
                       TF_SIZE*0.80,
                       TF_SIZE*0.12,
                       TF_SIZE*0.53,
                       TF_SIZE*0.21,
                       TF_SIZE*0.27,
                       TF_SIZE*0.78};

const int sp_size = sizeof(seekpos)/sizeof(int);

class tst_qfile: public QObject
{
Q_ENUMS(BenchmarkType)
Q_OBJECT
public:
    enum BenchmarkType {
        QFileBenchmark = 1,
        QFSFileEngineBenchmark,
        Win32Benchmark,
        PosixBenchmark,
        QFileFromPosixBenchmark
    };
private slots:
    void initTestCase();
    void cleanupTestCase();

    void open_data();
    void open();
    void seek_data();
    void seek();

    void readSmallFiles_QFile();
    void readSmallFiles_QFSFileEngine();
    void readSmallFiles_posix();
    void readSmallFiles_Win32();

    void readSmallFiles_QFile_data();
    void readSmallFiles_QFSFileEngine_data();
    void readSmallFiles_posix_data();
    void readSmallFiles_Win32_data();

    void readBigFile_QFile_data();
    void readBigFile_QFSFileEngine_data();
    void readBigFile_posix_data();
    void readBigFile_Win32_data();

    void readBigFile_QFile();
    void readBigFile_QFSFileEngine();
    void readBigFile_posix();
    void readBigFile_Win32();

private:
    void readBigFile_data(BenchmarkType type, QIODevice::OpenModeFlag t, QIODevice::OpenModeFlag b);
    void readBigFile();
    void readSmallFiles_data(BenchmarkType type, QIODevice::OpenModeFlag t, QIODevice::OpenModeFlag b);
    void readSmallFiles();
    void createFile();
    void fillFile(int factor=FACTOR);
    void removeFile();
    void createSmallFiles();
    void removeSmallFiles();
    QString filename;
    QString tmpDirName;
};

void tst_qfile::createFile()
{
    QTemporaryFile tmpFile;
    tmpFile.setAutoRemove(false);
    if (!tmpFile.open())
        ::_exit(1);
    filename = tmpFile.fileName();
    tmpFile.close();
}

void tst_qfile::removeFile()
{
    if (!filename.isEmpty())
        QFile::remove(filename);
}

void tst_qfile::fillFile(int factor)
{
    QFile tmpFile(filename);
    tmpFile.open(QIODevice::WriteOnly);
    //for (int row=0; row<factor; ++row) {
    //    tmpFile.write(QByteArray().fill('0'+row%('0'-'z'), 80));
    //    tmpFile.write("\n");
    //}
    tmpFile.seek(factor*80);
    tmpFile.putChar('\n');
    tmpFile.close();
    // let IO settle
    QTest::qSleep(2000);
}

void tst_qfile::initTestCase()
{
}

void tst_qfile::cleanupTestCase()
{
}

void tst_qfile::readBigFile_QFile() { readBigFile(); }
void tst_qfile::readBigFile_QFSFileEngine() { readBigFile(); }
void tst_qfile::readBigFile_posix() { readBigFile(); }
void tst_qfile::readBigFile_Win32() { readBigFile(); }

void tst_qfile::readBigFile_QFile_data()
{
    readBigFile_data(QFileBenchmark, QIODevice::NotOpen, QIODevice::NotOpen);
    readBigFile_data(QFileBenchmark, QIODevice::NotOpen, QIODevice::Unbuffered);
    readBigFile_data(QFileBenchmark, QIODevice::Text, QIODevice::NotOpen);
    readBigFile_data(QFileBenchmark, QIODevice::Text, QIODevice::Unbuffered);

}

void tst_qfile::readBigFile_QFSFileEngine_data()
{
    readBigFile_data(QFSFileEngineBenchmark, QIODevice::NotOpen, QIODevice::NotOpen);
    readBigFile_data(QFSFileEngineBenchmark, QIODevice::NotOpen, QIODevice::Unbuffered);
    readBigFile_data(QFSFileEngineBenchmark, QIODevice::Text, QIODevice::NotOpen);
    readBigFile_data(QFSFileEngineBenchmark, QIODevice::Text, QIODevice::Unbuffered);
}

void tst_qfile::readBigFile_posix_data()
{
    readBigFile_data(PosixBenchmark, QIODevice::NotOpen, QIODevice::NotOpen);
}

void tst_qfile::readBigFile_Win32_data()
{
    readBigFile_data(Win32Benchmark, QIODevice::NotOpen, QIODevice::NotOpen);
}


void tst_qfile::readBigFile_data(BenchmarkType type, QIODevice::OpenModeFlag t, QIODevice::OpenModeFlag b)
{
    QTest::addColumn<tst_qfile::BenchmarkType>("testType");
    QTest::addColumn<int>("blockSize");
    QTest::addColumn<QFile::OpenModeFlag>("textMode");
    QTest::addColumn<QFile::OpenModeFlag>("bufferedMode");

    const int bs[] = {1024, 1024*2, 1024*8, 1024*16, 1024*32,1024*512};
    int bs_entries = sizeof(bs)/sizeof(const int);

    QString flagstring;
    if (t & QIODevice::Text)       flagstring += "textMode ";
    if (b & QIODevice::Unbuffered) flagstring += "unbuffered ";
    if (flagstring.isEmpty())      flagstring = "none";

    for (int i=0; i<bs_entries; ++i)
        QTest::newRow((QString("BS: %1, Flags: %2" )).arg(bs[i]).arg(flagstring).toLatin1().constData()) << type << bs[i] << t << b;
  
}

void tst_qfile::readBigFile()
{
    QFETCH(tst_qfile::BenchmarkType, testType);
    QFETCH(int, blockSize);
    QFETCH(QFile::OpenModeFlag, textMode);
    QFETCH(QFile::OpenModeFlag, bufferedMode);

    char buffer[BUFSIZE]; // we can't allocate buffers nice and dynamically in c++
    removeFile();
    createFile();
    fillFile();

    switch (testType) {
        case(QFileBenchmark): {
            QFile file(filename);
            file.open(QIODevice::ReadOnly|textMode|bufferedMode);
            QBENCHMARK {
                while(!file.atEnd())
                    file.read(blockSize);
                file.reset();
            }
            file.close();
        }
        break;
        case(QFSFileEngineBenchmark): {
            QFSFileEngine fse(filename);
            fse.open(QIODevice::ReadOnly|textMode|bufferedMode);
            QBENCHMARK {
               //qWarning() << fse.supportsExtension(QAbstractFileEngine::AtEndExtension);
               while(fse.read(buffer, blockSize));
               fse.seek(0);
            }
            fse.close();
        }
        break;
        case(PosixBenchmark): {
            QByteArray data = filename.toLocal8Bit();
            const char* cfilename = data.constData();
            FILE* cfile = ::fopen(cfilename, "rb");
            QBENCHMARK {
                while(!feof(cfile))
                    ::fread(buffer, blockSize, 1, cfile);
                ::fseek(cfile, 0, SEEK_SET);
            }
            ::fclose(cfile);
        }
        break;
        case(QFileFromPosixBenchmark): {
            // No gain in benchmarking this case
        }
        break;
        case(Win32Benchmark): {
#ifdef Q_OS_WIN
            HANDLE hndl;

            // ensure we don't account string conversion
            wchar_t* cfilename = (wchar_t*)filename.utf16();

            hndl = CreateFile(cfilename, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
            Q_ASSERT(hndl);
            wchar_t* nativeBuffer = new wchar_t[BUFSIZE];
            DWORD numberOfBytesRead;

            QBENCHMARK {
                do {
                   ReadFile(hndl, nativeBuffer, blockSize, &numberOfBytesRead, NULL);
                } while(numberOfBytesRead != 0);
                SetFilePointer(hndl, 0, NULL, FILE_BEGIN);
            }
            delete[] nativeBuffer;
            CloseHandle(hndl);
#else
            QFAIL("Not running on a non-Windows platform!");
#endif
        }
        break;
    }
}

void tst_qfile::seek_data()
{
    QTest::addColumn<tst_qfile::BenchmarkType>("testType");
    QTest::newRow("QFile") << QFileBenchmark;
    QTest::newRow("QFSFileEngine") << QFSFileEngineBenchmark;
    QTest::newRow("Posix FILE*") << PosixBenchmark;
#ifdef Q_OS_WIN
    QTest::newRow("Win32 API") << Win32Benchmark;
#endif
}

void tst_qfile::seek()
{
    QFETCH(tst_qfile::BenchmarkType, testType);
    int i = 0;

    createFile();
    fillFile();

    switch (testType) {
        case(QFileBenchmark): {
            QFile file(filename);
            file.open(QIODevice::ReadOnly);
            QBENCHMARK {
                i=(i+1)%sp_size;
                file.seek(seekpos[i]);
            }
            file.close();
        }
        break;
        case(QFSFileEngineBenchmark): {
            QFSFileEngine fse(filename);
            fse.open(QIODevice::ReadOnly);
            QBENCHMARK {
                i=(i+1)%sp_size;
                fse.seek(seekpos[i]);
            }
            fse.close();
        }
        break;
        case(PosixBenchmark): {
            QByteArray data = filename.toLocal8Bit();
            const char* cfilename = data.constData();
            FILE* cfile = ::fopen(cfilename, "rb");
            QBENCHMARK {
                i=(i+1)%sp_size;
                ::fseek(cfile, seekpos[i], SEEK_SET);
            }
            ::fclose(cfile);
        }
        break;
        case(QFileFromPosixBenchmark): {
            // No gain in benchmarking this case
        }
        break;
        case(Win32Benchmark): {
#ifdef Q_OS_WIN
            HANDLE hndl;

            // ensure we don't account string conversion
            wchar_t* cfilename = (wchar_t*)filename.utf16();

            hndl = CreateFile(cfilename, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
            Q_ASSERT(hndl);
            QBENCHMARK {
                i=(i+1)%sp_size;
                SetFilePointer(hndl, seekpos[i], NULL, 0);
            }
            CloseHandle(hndl);
#else
            QFAIL("Not running on a Windows plattform!");
#endif
        }
        break;
    }
}

void tst_qfile::open_data()
{
    QTest::addColumn<tst_qfile::BenchmarkType>("testType");
    QTest::newRow("QFile") << QFileBenchmark;
    QTest::newRow("QFSFileEngine") << QFSFileEngineBenchmark;
    QTest::newRow("Posix FILE*") << PosixBenchmark;
    QTest::newRow("QFile from FILE*") << QFileFromPosixBenchmark;
#ifdef Q_OS_WIN
    QTest::newRow("Win32 API") << Win32Benchmark;
#endif
}

void tst_qfile::open()
{
    QFETCH(tst_qfile::BenchmarkType, testType);

    removeFile();
    createFile();

    switch (testType) {
        case(QFileBenchmark): {
            QBENCHMARK {
                QFile file( filename );
                file.open( QIODevice::ReadOnly );
                file.close();
            }
        }
        break;
        case(QFSFileEngineBenchmark): {
            QBENCHMARK {
                QFSFileEngine fse(filename);
                fse.open(QIODevice::ReadOnly);
                fse.close();
            }
        }
        break;

        case(PosixBenchmark): {
            // ensure we don't account toLocal8Bit()
            QByteArray data = filename.toLocal8Bit();
            const char* cfilename = data.constData();

            QBENCHMARK {
                FILE* cfile = ::fopen(cfilename, "rb");
                ::fclose(cfile);
            }
        }
        break;
        case(QFileFromPosixBenchmark): {
            // ensure we don't account toLocal8Bit()
            QByteArray data = filename.toLocal8Bit();
            const char* cfilename = data.constData();
            FILE* cfile = ::fopen(cfilename, "rb");

            QBENCHMARK {
                QFile file;
                file.open(cfile, QIODevice::ReadOnly);
                file.close();
            }
        }
        break;
        case(Win32Benchmark): {
#ifdef Q_OS_WIN
            HANDLE hndl;

            // ensure we don't account string conversion
            wchar_t* cfilename = (wchar_t*)filename.utf16();

            QBENCHMARK {
                hndl = CreateFile(cfilename, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
                Q_ASSERT(hndl);
                CloseHandle(hndl);
            }
#else
        QFAIL("Not running on a non-Windows platform!");
#endif
        }
        break;
    }

}


void tst_qfile::readSmallFiles_QFile() { readSmallFiles(); }
void tst_qfile::readSmallFiles_QFSFileEngine() { readSmallFiles(); }
void tst_qfile::readSmallFiles_posix() { readSmallFiles(); }
void tst_qfile::readSmallFiles_Win32() { readSmallFiles(); }

void tst_qfile::readSmallFiles_QFile_data()
{
    readSmallFiles_data(QFileBenchmark, QIODevice::NotOpen, QIODevice::NotOpen);
    readSmallFiles_data(QFileBenchmark, QIODevice::NotOpen, QIODevice::Unbuffered);
    readSmallFiles_data(QFileBenchmark, QIODevice::Text, QIODevice::NotOpen);
    readSmallFiles_data(QFileBenchmark, QIODevice::Text, QIODevice::Unbuffered);

}

void tst_qfile::readSmallFiles_QFSFileEngine_data()
{
    readSmallFiles_data(QFSFileEngineBenchmark, QIODevice::NotOpen, QIODevice::NotOpen);
    readSmallFiles_data(QFSFileEngineBenchmark, QIODevice::NotOpen, QIODevice::Unbuffered);
    readSmallFiles_data(QFSFileEngineBenchmark, QIODevice::Text, QIODevice::NotOpen);
    readSmallFiles_data(QFSFileEngineBenchmark, QIODevice::Text, QIODevice::Unbuffered);
}

void tst_qfile::readSmallFiles_posix_data()
{
    readSmallFiles_data(PosixBenchmark, QIODevice::NotOpen, QIODevice::NotOpen);
}

void tst_qfile::readSmallFiles_Win32_data()
{
    readSmallFiles_data(Win32Benchmark, QIODevice::NotOpen, QIODevice::NotOpen);
}


void tst_qfile::readSmallFiles_data(BenchmarkType type, QIODevice::OpenModeFlag t, QIODevice::OpenModeFlag b)
{
    QTest::addColumn<tst_qfile::BenchmarkType>("testType");
    QTest::addColumn<int>("blockSize");
    QTest::addColumn<QFile::OpenModeFlag>("textMode");
    QTest::addColumn<QFile::OpenModeFlag>("bufferedMode");

    const int bs[] = {1024, 1024*2, 1024*8, 1024*16, 1024*32,1024*512};
    int bs_entries = sizeof(bs)/sizeof(const int);

    QString flagstring;
    if (t & QIODevice::Text)       flagstring += "textMode ";
    if (b & QIODevice::Unbuffered) flagstring += "unbuffered ";
    if (flagstring.isEmpty())      flagstring = "none";

    for (int i=0; i<bs_entries; ++i)
        QTest::newRow((QString("BS: %1, Flags: %2" )).arg(bs[i]).arg(flagstring).toLatin1().constData()) << type << bs[i] << t << b;

}

void tst_qfile::createSmallFiles()
{
    QDir dir = QDir::temp();
    Q_ASSERT(dir.mkdir("tst"));
    dir.cd("tst");
    tmpDirName = dir.absolutePath();

    for (int i = 0; i < 1000; ++i)
    {
        QFile f(tmpDirName+"/"+QString::number(i));
        f.open(QIODevice::WriteOnly);
        f.seek(512);
        f.close();
    }
}

void tst_qfile::removeSmallFiles()
{
    QDirIterator it(tmpDirName, QDirIterator::FollowSymlinks);
    while (it.hasNext())
        QFile::remove(it.next());
    QDir::temp().rmdir("tst");
}


void tst_qfile::readSmallFiles()
{
    QFETCH(tst_qfile::BenchmarkType, testType);
    QFETCH(int, blockSize);
    QFETCH(QFile::OpenModeFlag, textMode);
    QFETCH(QFile::OpenModeFlag, bufferedMode);

    removeSmallFiles();
    createSmallFiles();
    QDir dir(tmpDirName);
    const QStringList files = dir.entryList(QDir::NoDotAndDotDot|QDir::NoSymLinks);
    char buffer[BUFSIZE]; // we can't allocate buffers nice and dynamically in c++

    switch (testType) {
        case(QFileBenchmark): {
            QList<QFile*> fileList;
            Q_FOREACH(QString file, files) {
                QFile *f = new QFile(file);
                f->open(QIODevice::ReadOnly|textMode|bufferedMode);
                fileList.append(f);
            }

            QBENCHMARK {
                Q_FOREACH(QFile *file, fileList) {
                    while (!file->atEnd()) {
                       file->read(buffer, blockSize);
                    }
                }
            }

            Q_FOREACH(QFile *file, fileList) {
                file->close();
                delete file;
            }
        }
        break;
        case(QFSFileEngineBenchmark): {
            QList<QFSFileEngine*> fileList;
            Q_FOREACH(QString file, files) {
                QFSFileEngine *fse = new QFSFileEngine(file);
                fse->open(QIODevice::ReadOnly|textMode|bufferedMode);
                fileList.append(fse);
            }

            QBENCHMARK {
                Q_FOREACH(QFSFileEngine *fse, fileList) {
                    while (fse->read(buffer, blockSize));
                }
            }

            Q_FOREACH(QFSFileEngine *fse, fileList) {
                fse->close();
                delete fse;
            }
        }
        break;
        case(PosixBenchmark): {
            QList<FILE*> fileList;
            Q_FOREACH(QString file, files) {
                fileList.append(::fopen(QFile::encodeName(file).constData(), "rb"));
            }

            QBENCHMARK {
                Q_FOREACH(FILE* cfile, fileList) {
                    while(!feof(cfile))
                        ::fread(buffer, blockSize, 1, cfile);
                    ::fseek(cfile, 0, SEEK_SET);
                }
            }

            Q_FOREACH(FILE* cfile, fileList) {
                ::fclose(cfile);
            }
        }
        break;
        case(QFileFromPosixBenchmark): {
            // No gain in benchmarking this case
        }
        break;
        case(Win32Benchmark): {
#ifdef Q_OS_WIN
            HANDLE hndl;

            // ensure we don't account string conversion
            wchar_t* cfilename = (wchar_t*)filename.utf16();

            hndl = CreateFile(cfilename, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
            Q_ASSERT(hndl);
            wchar_t* nativeBuffer = new wchar_t[BUFSIZE];
            DWORD numberOfBytesRead;
            QBENCHMARK {
                do {
                   ReadFile(hndl, nativeBuffer, blockSize, &numberOfBytesRead, NULL);
                } while(numberOfBytesRead != 0);
            }
            delete nativeBuffer;
            CloseHandle(hndl);
#else
            QFAIL("Not running on a non-Windows platform!");
#endif
        }
        break;
    }
}

Q_DECLARE_METATYPE(tst_qfile::BenchmarkType)
Q_DECLARE_METATYPE(QIODevice::OpenMode)
Q_DECLARE_METATYPE(QIODevice::OpenModeFlag)

QTEST_MAIN(tst_qfile)

#include "main.moc"
