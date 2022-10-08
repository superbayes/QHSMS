#include "mytcpserver.h"

#include <QTcpSocket>

MyTcpServer::MyTcpServer(QObject *parent) :QObject(parent)
{
    tcpServer=new QTcpServer(this); //创建server
    connect(tcpServer, &QTcpServer::newConnection, this, &MyTcpServer::NewConnectionSlot);  //新连接客户端处理
}



MyTcpServer::~MyTcpServer() //释放资源
{
    qDeleteAll(tcpClient);
    delete currentClient;
}

//获得新连接的客户端信息
void MyTcpServer::NewConnectionSlot()
{
    //只允许建立一个连接
    if(tcpClient.size()==0){
        currentClient=tcpServer->nextPendingConnection();
        tcpClient.append(currentClient);
        //connect(currentClient, &QTcpSocket::readyRead, this, &MyTcpServer::ReadData);
        //connect(currentClient, &QTcpSocket::disconnected, this, &MyTcpServer::disconnectedSlot);
    }

}

//单个客户端断开处理
void MyTcpServer::disconnectedSlot()
{
    for(int i=0; i<tcpClient.size(); i++)
    {
        if(tcpClient[i]->state()==QAbstractSocket::UnconnectedState)
        {
            tcpClient[i]->destroyed();
            tcpClient.removeAt(i);
        }
    }
}

//开始监听
void MyTcpServer::startListen()
{
    bool ok=tcpServer->listen(my_address/*QHostAddress::Any*/, my_port);
    if(ok)
    {
        QString str="开启Server成功";
        qDebug()<<str.toStdString().c_str();
    }
    else
    {
        QString str="开启Server失败";
        qDebug()<<str.toStdString().c_str();
    }
}

//断开监听
void MyTcpServer::stopListen()
{
    for(int i=0; i<tcpClient.size(); i++)
    {
        QTcpSocket *client=tcpClient[i];
        client->disconnectFromHost();
        tcpClient.removeAt(i);
    }
    tcpServer->close();
}

//获取客户端数据
void MyTcpServer::ReadData()
{
    for(int i=0; i<tcpClient.size(); i++)
    {
        QByteArray buffer=tcpClient[i]->readAll();
        if(buffer.isEmpty())
        {
            continue;
        }
        qDebug()<<"client "<<i<<": "<<buffer;
    }
}


//发送数据
void MyTcpServer::writeData()
{
    qDebug()<<"connection size= "<<tcpClient.size();
    for(int i=0; i<tcpClient.size(); i++)
    {
        QString str="server send "+QString::number(i)+"\n";
        tcpClient[i]->write(str.toLatin1());
    }
}
