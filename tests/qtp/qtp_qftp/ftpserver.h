#ifndef FTPSERVER_H
#define FTPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

 class ftpServer : public QTcpServer // , public QThread
 {
     Q_OBJECT

 public:
     ftpServer( QObject *parent = 0 );
     ~ftpServer();

     bool isDone();
//     void run();
/*
private:
    void sendSomething( QTcpSocket *outSock, quint16 port );
*/
private slots:
    void handleNewConnection();
    void readConnection();
    void displayConnectionError(QAbstractSocket::SocketError socketError);

    void readDataConnection();
    void handleNewDataConnection();
    void displayDataConnectionError(QAbstractSocket::SocketError socketError);

 private:
    QTcpServer *tcpServer;
    QTcpSocket *ftpSocket;

    QTcpServer *dataServer;
    QTcpSocket *dataSocket;

    bool not_done;
};

#endif // FTPSERVER_H
