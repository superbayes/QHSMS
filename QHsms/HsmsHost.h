#ifndef HSMSHOST_H
#define HSMSHOST_H

#include <QObject>
#include <QTimer>
#include "HsmsDevice.h"
#include "mytcpserver.h"

/**
 * @brief The HsmsHost class Host 基类。这个类里面包含了一个 Host 的通用功能。
 *     实际项目中应该从这个类派生一个新的类，在派生类里添加项目相关的功能。
 */
class HsmsHost : public HsmsDevice
{
    Q_OBJECT
public:
    explicit HsmsHost(QObject *parent = nullptr);
    void connectToEQP(QString ip, uint16_t port, bool auto_reconnect = false);
    void disconnectFromEQP();

public:
    //作为主机端存在,等待其他客户端连接
    //    1.listen
    //    2.响应newConnection信号
    //    3.处理客户端连接
    //    4.关闭客户端连接
    MyTcpServer * myTcpServer;
    void listen_IP(QHostAddress adr,quint16 port);//开启监听



signals:
    void connectedToEQP();
    void disconnectedFromEQP();

public slots:
    void connected();
    void disconncected();
private slots:
    void on_selectRsp(HSMSMessages m);
    void on_linktestRsp(HSMSMessages m);
    void reconnect();
    void timeout();

private:
    enum STATE{IDLE, WAIT_SELECT_RSP, WAIT_LINKTEST_RSP, SEND_AREYOUTHERE, WAIT_S1F2};

    enum STATE m_state;
    bool m_autoReconnect;
    QTimer m_timer;

};

#endif // HSMSHOST_H
