#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

class QTcpSocket;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QTcpSocket* m_pTcpSocket = nullptr;

private slots:
    void onSocketConnected(void);
    void onSocketDisConnected(void);
    void onSocketReadyRead(void);
    void onErrorOccurred(QTcpSocket::SocketError socketError);
    void onCloseSocket(void);
};
#endif // WIDGET_H
