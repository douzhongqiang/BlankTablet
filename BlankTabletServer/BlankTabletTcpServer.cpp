#include "BlankTabletTcpServer.h"
#include <QDebug>

BlankTabletTcpServer::BlankTabletTcpServer(QObject* parent)
    :QObject(parent)
{
    m_pTcpServer = new QTcpServer(this);
    m_isTcpServerSuccessed = m_pTcpServer->listen(QHostAddress::Any, 12345);
    QObject::connect(m_pTcpServer, &QTcpServer::newConnection, this, &BlankTabletTcpServer::onHandleNewConnection);
}

BlankTabletTcpServer::~BlankTabletTcpServer()
{

}

void BlankTabletTcpServer::onHandleNewConnection(void)
{
    QTcpSocket *clientSocket = m_pTcpServer->nextPendingConnection();
    QObject::connect(clientSocket, &QTcpSocket::readyRead, this, &BlankTabletTcpServer::onClientSocketReadyRead);
}

void BlankTabletTcpServer::onClientSocketReadyRead(void)
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    QByteArray data = clientSocket->readAll();

    // 处理数据...
    qInfo() << __FUNCTION__ << QString(data);

    // 回复客户端
    clientSocket->write("Hello from server");
}
