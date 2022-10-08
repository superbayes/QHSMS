#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
//    const QHostAddress &address = QHostAddress::Any, quint16 port = 0
    QHostAddress my_address;//server监听的ip
    quint16 my_port;//server监听的port

signals:
private:
    QTcpServer  *tcpServer;  //Server对象
    QList<QTcpSocket*> tcpClient;   //客户端集合
    QTcpSocket *currentClient;  //当前添加的socket客户端

public slots:
    void NewConnectionSlot();   //获取新连接客户端
    void disconnectedSlot();    //断开单个客户端
    void startListen();         //开始监听
    void stopListen();          //停止监听
    void ReadData();            //获取数据
    void writeData();           //发送数据
};

#endif // MYTCPSERVER_H
