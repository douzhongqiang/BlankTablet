#ifndef BLANKTABLETTCPSERVER_H
#define BLANKTABLETTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class BlankTabletTcpServer : public QObject
{
    Q_OBJECT

public:
    BlankTabletTcpServer(QObject* parent = nullptr);
    ~BlankTabletTcpServer();

private:
    QTcpServer* m_pTcpServer = nullptr;
    bool m_isTcpServerSuccessed = false;

private slots:
    void onHandleNewConnection(void);
    void onClientSocketReadyRead(void);
};

#endif
