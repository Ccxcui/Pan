#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QFile>
#include <QTcpSocket>

namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();
    void loadConfig();

public slots:
    void showConnect();

private:
    Ui::TcpClient *ui;
    QString m_strIP;
    quint16 m_usPort;

    //连接服务器，和服务器数据交互
    QTcpSocket m_tcpSocket;
};

#endif // TCPCLIENT_H
