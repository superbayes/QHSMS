#ifndef HSMSEQUIPMENT_H
#define HSMSEQUIPMENT_H

#include <QObject>
#include <QTcpServer>
#include <QPair>
#include "HsmsDevice.h"



/**
 * @brief The HsmsEquipment class HSMS 设备端的公共基类。实现设备端的公共功能。
 *    实际使用时应该从这个类派生一个新的类。在新的类里增加特殊功能。
 */
class HsmsEQP : public HsmsDevice
{
    Q_OBJECT
public:
    explicit HsmsEQP(QObject *parent = nullptr);
    ~HsmsEQP();
    void setAddressPort(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);
    /**
     * @brief startListen 开始监听，等待客户端连接。一旦连接上就不再等待其他连接。但是连接关闭后会继续监听，直到调用 stopListen。
     */
    bool startListen();
    /**
     * @brief stopListen 停止监听端口。
     */
    void stopListen();
signals:
    void disconnected();
    void newConnection();
    void signals_listenStatus(bool isListenScuess);//是否监听成功
protected slots:
    void onNewConnection();
    void onDisconnected();

private:

    int m_state;

    QTcpServer * m_server;
    QHostAddress m_address;

};

#endif // HSMSEQUIPMENT_H
