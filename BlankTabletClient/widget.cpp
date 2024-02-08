#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_pTcpSocket = new QTcpSocket(this);

    QObject::connect(m_pTcpSocket, &QTcpSocket::connected, this, &Widget::onSocketConnected);
    QObject::connect(m_pTcpSocket, &QTcpSocket::disconnected, this, &Widget::onSocketDisConnected);
    QObject::connect(m_pTcpSocket, &QTcpSocket::readyRead, this, &Widget::onSocketReadyRead);
    QObject::connect(m_pTcpSocket, &QTcpSocket::errorOccurred, this, &Widget::onErrorOccurred);

    m_pTcpSocket->connectToHost("127.0.0.1", 12345);
}


Widget::~Widget()
{
}

void Widget::onSocketConnected(void)
{
    m_pTcpSocket->write("Hello!");
}

void Widget::onSocketDisConnected(void)
{

}

void Widget::onSocketReadyRead(void)
{
    QByteArray byteArray = m_pTcpSocket->readAll();
    qInfo() << __FUNCTION__ << QString(byteArray);
}

void Widget::onErrorOccurred(QTcpSocket::SocketError socketError)
{
    qInfo() << socketError;
}

void Widget::onCloseSocket(void)
{

}

