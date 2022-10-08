#include "HsmsHost.h"

const int TIMEOUT = 3000;
const int RECONNECT_INTERVAL = 10000;

HsmsHost::HsmsHost(QObject *parent)
    : HsmsDevice(parent),
      m_state(IDLE),
      m_autoReconnect(false)
{
    //=================================================================================================

    m_tcpSocket = new QTcpSocket(this);
    //
//    myTcpServer = new MyTcpServer(this);
//    myTcpServer->my_address = QHostAddress::Any;
//    myTcpServer->my_port = 5000;
//    myTcpServer->startListen();
    //=================================================================================================
    if(m_tcpSocket)
    {
        QObject::connect(m_tcpSocket, &QTcpSocket::readyRead, this, &HsmsHost::readMessage);
        QObject::connect(m_tcpSocket, &QTcpSocket::connected, this, &HsmsHost::connected);
        QObject::connect(m_tcpSocket, SIGNAL(connected()), this, SIGNAL(connectedToEQP()));
        QObject::connect(m_tcpSocket, &QTcpSocket::disconnected, this, &HsmsHost::disconnectFromEQP);
        QObject::connect(m_tcpSocket, SIGNAL(disconnected()), this, SIGNAL(disconnectedFromEQP()));
        QObject::connect(this, &HsmsDevice::selectRspReceived, this, &HsmsHost::on_selectRsp);
        QObject::connect(this, &HsmsDevice::linktestRspReceived, this, &HsmsHost::on_linktestRsp);
    }
}

void HsmsHost::connectToEQP(QString ip, uint16_t port, bool auto_reconnect)
{
    m_ip = ip;
    m_port = port;
    m_autoReconnect = auto_reconnect;

    m_tcpSocket->connectToHost(m_ip, m_port);
    qDebug() << "connectToHost: IP = " << m_ip << ", port = " << m_port;
}

void HsmsHost::timeout()
{
    switch (m_state)
    {
    case WAIT_SELECT_RSP:
        break;
    case WAIT_LINKTEST_RSP:
        break;
    case WAIT_S1F2:
        break;
    default:
        break;
    }
}

void HsmsHost::on_linktestRsp(HSMSMessages m)
{
    m_timer.stop();
    if(m_state == SEND_AREYOUTHERE)
    {
        sendS1F1();
        m_state = WAIT_S1F2;
        m_timer.singleShot(TIMEOUT, this, SLOT(timeout()));
    }
    else
    {
        m_state = IDLE;
    }
}

void HsmsHost::on_selectRsp(HSMSMessages m)
{
    m_timer.stop();
    sendLinkTestReq();
    m_state = SEND_AREYOUTHERE;
    m_timer.singleShot(TIMEOUT, this, SLOT(timeout()));
}


void HsmsHost::connected()
{
    sendSelectReq();
    m_state = WAIT_SELECT_RSP;
    m_timer.singleShot(TIMEOUT, this, SLOT(timeout()));
}

void HsmsHost::disconncected()
{
    if(m_autoReconnect)
    {
        m_timer.singleShot(RECONNECT_INTERVAL, this, SLOT(reconnect));
    }
}

void HsmsHost::disconnectFromEQP()
{
    m_autoReconnect = false;
    sendSeparateReq();
    m_tcpSocket->disconnectFromHost();
    qDebug()<<"I disconnect FromHost===";
}

void HsmsHost::listen_IP(QHostAddress adr, quint16 port)
{
    myTcpServer->my_address = adr;
    myTcpServer->my_port = port;
    myTcpServer->stopListen();
}

void HsmsHost::reconnect()
{
    m_tcpSocket->connectToHost(m_ip, m_port);
}
