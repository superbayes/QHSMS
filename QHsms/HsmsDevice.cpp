#include "HsmsDevice.h"
#include <QDateTime>
#include <QDir>
HsmsDevice::HsmsDevice(QObject *parent)
    : QObject(parent),
      m_sessionID(0),
      m_port(0),
      m_messageLength(0)
{

    registerDataMessage(0, 0);
    registerDataMessage(1, 1); //Are you there
    registerDataMessage(1, 2);
    registerDataMessage(1, 3);
    registerDataMessage(1, 4);
    registerDataMessage(1, 5);
    registerDataMessage(1, 6);
    registerDataMessage(1, 7);
    registerDataMessage(1, 8);
    registerDataMessage(1, 9);
    registerDataMessage(1, 10);
    registerDataMessage(1, 11);
    registerDataMessage(1, 12);
    registerDataMessage(1, 13);
    registerDataMessage(1, 14);
    registerDataMessage(2, 1);
    registerDataMessage(2, 2);
    registerDataMessage(2, 3);
    registerDataMessage(2, 17); //DateTimeRequest
    registerDataMessage(2, 18); //DateTimeRequest
    registerDataMessage(2, 41); //NG
    registerDataMessage(2, 103);//OK
    registerDataMessage(9, 1); //Unrecognized device ID
    registerDataMessage(9, 3); //Unrecognized stream type
    registerDataMessage(9, 5); //Unrecognized function type
    registerDataMessage(6, 4);
    registerDataMessage(6, 12);
    registerDataMessage(6, 17);
}
void HsmsDevice::unRegisterDataMessage(uint8_t stream, uint8_t function)
{
    uint16_t x = stream;
    x = (x << 8) + function;
    m_sfSet.remove(x);

    bool hasStream = false;
    bool hasFunction = false;
    foreach (const uint16_t &value, m_sfSet)
    {
        uint8_t s = value >> 8;
        uint8_t f = value & 0xff;
        if(s == stream)
        {
            hasStream = true;
        }
        if(f == function)
        {
            hasFunction = true;
        }
    }
    if(!hasStream) m_streamSet.remove(stream);
    if(!hasFunction) m_functionSet.remove(function);
}

void HsmsDevice::registerDataMessage(uint8_t stream, uint8_t function)
{
    uint16_t x = stream;
    x = (x << 8) + function;
    m_sfSet.insert(x);

    m_streamSet.insert(stream);
    m_functionSet.insert(function);
}

void HsmsDevice::onReceiveS1F1(const HSMSMessages &message)
{
    HSMSMessages rsp = HSMSMessages::S1F2(message, m_MDLN, m_SOFTREV); //S1,F2 On Line Data (D)
    sendMessage(rsp);
}

//void HsmsDevice::onReceiveS1F3(const HSMSMessages &message, QString type)
//{
//    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, type);//S2F4

//    qDebug()<<"onReceiveS1F3,systemBytes = " <<rsp.systemBytes();
//    sendMessage(rsp);
//}

void HsmsDevice::onReceiveS1F13(const HSMSMessages &message,u1 type)
{
    //pdf 44页
    //<L[2]
    //    1. <B COMMACK>  0: Accepted;1: Denied, try again
    //    2. <L[2]   这部分属于S1F13
    //        1.<A MDLN>
    //        2.<A SOFTREV>
    SECS2Item s1f13 = message.getItem();
    SECS2Item tmp;
    uint8_t x[1] = {type};
    tmp.setUInt8(x,1);
    SECS2Item res = SECS2Item::mergeSECS2Item(tmp,s1f13);

    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, res);//S2F14
    sendMessage(rsp);
}

void HsmsDevice::onReceiveS2F17(const HSMSMessages &message)
{
    qDebug() << message.toByteArray();
    QDateTime dt = QDateTime::currentDateTime();
    QString timeString = dt.toString("yyyyMMddhhmmss");
    //qDebug() << "time string = " << timeString;
    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, timeString);//S2F18
    sendMessage(rsp);
}

//void HsmsDevice::onReceiveS2F41(const HSMSMessages &message, u1 type)
//{
//        //qDebug() << message.toByteArray();
//        HSMSMessages rsp = HSMSMessages::replyDataMessage(message, type);//S2F42
//        sendMessage(rsp);
//}

//void HsmsDevice::onReceiveS2F103(const HSMSMessages &message, QString type)
//{
//    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, type);//S2F104
//    sendMessage(rsp);
//}

void HsmsDevice::onDataMessage()
{
    puts("DataMessage received:");
//    qDebug() << "len = " << m_receivedMessage.length();
    puts(m_receivedMessage.toLogString().toLocal8Bit());
    uint16_t id = m_receivedMessage.sessionID();
    if(id != m_sessionID)
    {
        HSMSMessages mess = HSMSMessages::S9F1(m_receivedMessage, m_sessionID);
        sendMessage(mess);
        return;
    }
    uint8_t stream = m_receivedMessage.stream();
    uint8_t function = m_receivedMessage.function();
    uint32_t sb = m_receivedMessage.systemBytes();
    //qDebug() << "I HsmsDevice recieve S"<<stream<<"F"<<function << "systemBytesID:"<<m_receivedMessage.systemBytes();
    emit signals_eqp_recieve_S_F(stream,function,sb,m_receivedMessage.toLogString());
    if(stream == 1 && function == 1)
    {
        onReceiveS1F1(m_receivedMessage);
        return;
    }
    if(stream == 1 && function == 2)
    {
        return;
    }
    if(/*stream == 1 && function == 3*/false)
    {
        //onReceiveS1F3(m_receivedMessage);
        //保存HSMSMessages的信息
        //保存文件,如有存在文件夹则保存,没有就创建
        //获取复合文件夹,检查是否存在 "./log/202209/" QDateTime::currentDateTime().toString("yyyyMM")
//            QString fileName ="./log/alice_L10_S1F3.csv";//"./log/202209/alice_l10_zhengji.csv"
//            QFile file(fileName);
//            QString saveContent;

//            saveContent += QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//            saveContent += ", S1F3,";

//            for(int i=0;i<this->m_receivedMessage.m_message.length();++i)
//            {
//                QString str__ = QString::number(m_receivedMessage.m_message.at(i),16);
//                saveContent += str__;
//                saveContent+=",";
//                //qDebug()<<"onReceiveS1F3" << str__;
//            }
//            saveContent+="\n";
//            //如果文件不存在,则需要创建文件,并且第一行是字段
//            bool bRet;
//            bRet = file.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append);
//            if(bRet)
//            {
//                //如果文件存在,则只需添加内容即可
//                file.write(saveContent.toLocal8Bit());
//            }
//            file.close();
        //================================================================================
        return;
    }
    if(stream == 1 && function == 4)
    {
        return;
    }
    if(/*stream == 1 && function == 5*/false)
    {
        return;
    }
    if(stream == 1 && function == 13)
    {
        this->onReceiveS1F13(m_receivedMessage);
        return;
    }
    //===================================================
    if(stream == 2 && function == 17)
    {
        onReceiveS2F17(m_receivedMessage);
        return;
    }
    if(/*stream == 2 && function == 41*/false)
    {
        //进站失败
//        onReceiveS2F41(m_receivedMessage,0);
        return;
    }
    if(/*stream == 2 && function == 103*/false)
    {
        //进站成功
        //onReceiveS2F103(m_receivedMessage);
        return;
    }
    //====================================================
    //====================================================





    uint16_t all = stream;
    all = (all << 8) + function;
    if(m_sfSet.contains(all) )
    {
        emit dataReady(m_receivedMessage);
        return;
    }
    if(!m_streamSet.contains(stream))
    {
        HSMSMessages rsp = HSMSMessages::S9F3(m_receivedMessage, m_sessionID);
        sendMessage(rsp);
        return;
    }
    else
    {
        HSMSMessages rsp = HSMSMessages::S9F5(m_receivedMessage, m_sessionID);
        sendMessage(rsp);
        return;
    }
}

void HsmsDevice::readMessage()
{
    //qDebug() << "readMessage";
    m_buffer += m_tcpSocket->readAll();
    do
    {
        if(m_buffer.size()  >= 4) // 前 4 个字节是 Message Length
        {
            m_messageLength = static_cast<uint8_t>(m_buffer.at(0));
            m_messageLength = (m_messageLength << 8) + static_cast<uint8_t>(m_buffer.at(1));
            m_messageLength = (m_messageLength << 8) + static_cast<uint8_t>(m_buffer.at(2));
            m_messageLength = (m_messageLength << 8) + static_cast<uint8_t>(m_buffer.at(3));
        }
        if(m_buffer.size() >= m_messageLength + 4)
        { // 到这里说明收到了一个完整的 Message
            qDebug() << "A full message received";
            m_messageType = m_receivedMessage.loadFromByteArray(m_buffer);
            decodeMessge();
            m_buffer = m_buffer.mid(m_messageLength + 4);
        }
        else
        {
            return;
        }
    }while(m_buffer.size() > 0);
}

void HsmsDevice::decodeMessge()
{
    uint16_t id = m_receivedMessage.sessionID();
    uint32_t sb = m_receivedMessage.systemBytes();
    HSMSMessages rsp;
    switch (m_messageType)
    {
    case HSMSMessages::SelectReq:
        qDebug() << "receive a HSMSMessages::SelectReq, sessionID = " << id << "systemBytes = " << sb;
        sendSelectRsp(id, sb, HSMSMessages::ConnectEstablished);
        emit selectReqReceived(m_receivedMessage);
        break;
    case HSMSMessages::RejectReq:
        qDebug() << "receive a HSMSMessages::RejectReq, sessionID = " << id << "systemBytes = " << sb;
        emit rejectReqReceived(m_receivedMessage);
        break;
    case HSMSMessages::SelectRsp:
        qDebug() << "receive a HSMSMessages::SelectRsp, sessionID = " << id << "systemBytes = " << sb;
        emit selectRspReceived(m_receivedMessage);
        break;
    case HSMSMessages::DeselectReq:
        qDebug() << "receive a HSMSMessages::DeselectReq, sessionID = " << id << "systemBytes = " << sb;
        emit deselectReqReceived(m_receivedMessage);
        sendDeselectRsp(m_receivedMessage, HSMSMessages::CommunicationEnded);
        break;
    case HSMSMessages::DeselectRsp:
        qDebug() << "receive a HSMSMessages::DeselectRsp, sessionID = " << id << "systemBytes = " << sb;
        emit deselectRspReceived(m_receivedMessage);
        break;
    case HSMSMessages::SeparateReq:
        qDebug() << "receive a HSMSMessages::SeparateReq, sessionID = " << id << "systemBytes = " << sb;
        emit separateReqReceived(m_receivedMessage);
        break;
    case HSMSMessages::LinktestReq:
        qDebug() << "receive a HSMSMessages::LinktestReq, sessionID = " << id << "systemBytes = " << sb;
        sendLinkTestRsp(sb);
        break;
    case HSMSMessages::LinktestRsp:
        qDebug() << "receive a HSMSMessages::LinktestRsp, sessionID = " << id << "systemBytes = " << sb;
        emit linktestRspReceived(m_receivedMessage);
        break;
    case HSMSMessages::DataMessage:
        qDebug() << "receive a HSMSMessages::DataMessage, sessionID = " << id << "systemBytes = " << sb;

        onDataMessage();
        break;
    default:
        qDebug() << "error";
        break;
    }
}

void HsmsDevice::displayError(QAbstractSocket::SocketError e)
{
    qDebug() << e;
}

void HsmsDevice::setSessionID(uint16_t sessionID)
{
    m_sessionID = sessionID;
}

void HsmsDevice::sendMessage(const HSMSMessages &message)
{
    if(m_tcpSocket->isWritable())
    {
        //qDebug() << "send Message";
        puts("Send Message");
        //qDebug() << "length = " << message.length();
        puts(message.toLogString().toLocal8Bit());
//        uint16_t id = message.sessionID();
        uint32_t sb = message.systemBytes();
        uint8_t stream = message.stream();
        uint8_t function = message.function();
        //qDebug() << "send S" << stream << "F" << function << ", sessionID = " << id << ", systemBytes = " << sb;
        QByteArray a = message.toByteArray();
        m_tcpSocket->write(a);

        //将信息以信号的形式发送出去
       emit signals_eqp_send_S_F_sb(stream,function,sb,message.toLogString());

    }
    else
    {
        qDebug() << "Message cannot send to Host";
    }
}

void HsmsDevice::sendLinkTestReq()
{
    qDebug() << "send LinkTestReq";
    HSMSMessages linktest = HSMSMessages::linktestReq();
    sendMessage(linktest);
}

void HsmsDevice::sendSelectReq()
{
    qDebug() << "send SelectReq";
    HSMSMessages select = HSMSMessages::selectReq(0);
    sendMessage(select);
}


void HsmsDevice::sendDeselectReq()
{
    qDebug() << "send DeselectReq";
    HSMSMessages deselect = HSMSMessages::deselectReq(0);
    sendMessage(deselect);
}

void HsmsDevice::sendSeparateReq()
{
    qDebug() << "send LinkTestReq";
    HSMSMessages linktest = HSMSMessages::separateReq(0);
    sendMessage(linktest);
}

void HsmsDevice::sendSelectRsp(const HSMSMessages &seleReq, HSMSMessages::SelectStatus status)
{
    qDebug() << "send SelectRsp, Status = " << status;
    HSMSMessages rsp = HSMSMessages::selectRsp(seleReq, status);
    sendMessage(rsp);
}

void HsmsDevice::sendSelectRsp(uint16_t sessionID, uint32_t systemBytes, HSMSMessages::SelectStatus status)
{
    qDebug() << "send SelectRsp, Status = " << status;
    HSMSMessages rsp = HSMSMessages::selectRsp(sessionID, systemBytes, status);
    sendMessage(rsp);
}

void HsmsDevice::sendDeselectRsp(uint16_t sessionID, uint32_t systemBytes, HSMSMessages::DeselectStatus status)
{
    qDebug() << "send DeselectRsp, Status = " << status;
    HSMSMessages rsp = HSMSMessages::deselectRsp(sessionID, systemBytes, status);
    sendMessage(rsp);
}

void HsmsDevice::sendDeselectRsp(const HSMSMessages &deseReq, HSMSMessages::DeselectStatus status) // private
{
    qDebug() << "send DeselectRsp, Status = " << status;
    HSMSMessages rsp = HSMSMessages::deselectRsp(deseReq, status);
    sendMessage(rsp);
}

void HsmsDevice::sendLinkTestRsp(uint32_t systemBytes) // private
{
    qDebug() << "send LinkTestRsp, systemBytes = " << systemBytes;
    HSMSMessages rsp = HSMSMessages::linktestRsp(systemBytes);
    sendMessage(rsp);
}

void HsmsDevice::sendLinkTestRsp(const HSMSMessages &lReq)// private
{
    uint32_t sb = lReq.systemBytes();
    qDebug() << "send LinkTestRsp, systemBytes = " << sb;
    HSMSMessages rsp = HSMSMessages::linktestRsp(sb);
    sendMessage(rsp);
}

void HsmsDevice::sendS1F1()
{
    qDebug() << "send S1F1, Are you there";
    HSMSMessages s1f1 = HSMSMessages::S1F1(m_sessionID);
    sendMessage(s1f1);
}

void HsmsDevice::sendS2F17() //DateTimeRequest
{
    qDebug() << "send S2F17, DateTimeRequest";
    HSMSMessages s2f17 = HSMSMessages::S2F17(m_sessionID);
    qDebug() << s2f17.toByteArray();
    sendMessage(s2f17);
}

void HsmsDevice::setMDLN(QString mdln)
{
    m_MDLN = mdln.left(20);
}

void HsmsDevice::setSOFTREV(QString rev)
{
    m_SOFTREV = rev.left(20);
}
