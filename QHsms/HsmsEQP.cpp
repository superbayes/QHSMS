#include "HsmsEQP.h"
#include <QDebug>
HsmsEQP::HsmsEQP(QObject *parent)
    : HsmsDevice(parent),
      m_address(QHostAddress::Any)
{
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &HsmsEQP::onNewConnection);
}

HsmsEQP::~HsmsEQP()
{
    m_server->close();
    m_server->deleteLater();
}

void HsmsEQP::setAddressPort(const QHostAddress &address, quint16 port)
{
    m_address = address;
    m_port = port;
}

bool HsmsEQP::startListen()
{
    if( !m_server )
    {
        m_server = new QTcpServer(this);
    }
    if(m_server->isListening())
    {
        m_server->close();
    }
    m_server->setMaxPendingConnections(2); // 只允许一个连接
    bool ret = m_server->listen(m_address, m_port);
    qDebug() << "m_server->listen(m_address, m_port);";
    emit signals_listenStatus(ret);
    return ret;
}

void HsmsEQP::stopListen()
{
    m_server->close();
}

void HsmsEQP::onNewConnection()
{
    qDebug() << "new connection setup";
    m_tcpSocket = m_server->nextPendingConnection();
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &HsmsDevice::readMessage);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &HsmsEQP::onDisconnected);
    connect(m_tcpSocket, &QTcpSocket::disconnected, m_tcpSocket, &QTcpSocket::deleteLater);
    //m_server->close(); // 只允许一个连接。连接建立后就不再监听了。
    emit newConnection();
}


void HsmsEQP::onDisconnected()
{
    qDebug() << "disconnect";
    emit disconnected();
    startListen();
}






