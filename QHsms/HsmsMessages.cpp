#include "HsmsMessages.h"
#include <QDateTime>
#include <QDebug>
uint32_t HSMSMessages::SystemBytes = 0;
uint32_t HSMSMessages::SystemBytes_counter = 0;
HSMSMessages::HSMSMessages()
{
    m_message.resize(14);
    setLength(10);
}

uint32_t HSMSMessages::uniqueSystemBytes()
{
    SystemBytes_counter ++;
    uint32_t timeDate = QDateTime::currentDateTime().toTime_t();  // 获取当前时间,将当前时间转为时间戳
    SystemBytes = timeDate<<4;
    SystemBytes += SystemBytes_counter%16;
    return SystemBytes;
}

QString HSMSMessages::toLogString() const
{
    uint32_t sid = sessionID();
    uint32_t sb = systemBytes();
    QString str = QString("sessionID = %1, systemBytes = %2\n").arg(sid).arg(sb);
    str += QString("Stream = %1, function = %2\n").arg(stream()).arg(function());
    SECS2Item it = getItem();
    str += it.stringLog("");
    return str;
}

HSMSMessages::MessageType HSMSMessages::loadFromByteArray(const QByteArray &array)
{
    m_message = array;
    if(array.size() < 14)
    {
        return HSMSMessages::Unknown;
    }
    int messageLength = array.at(0);
    messageLength = (messageLength << 8) + array.at(1);
    messageLength = (messageLength << 8) + array.at(2);
    messageLength = (messageLength << 8) + array.at(3);
    if(messageLength + 4 > array.size())
    {
        return HSMSMessages::Unknown;
    }
    if( pType() != 0)
    {
        return HSMSMessages::Unknown;
    }
    if( stream() & ( !sType() ) )
    {
        return HSMSMessages::DataMessage;
    }

    if( sType() >= 0 && sType() < 10)
    {
        return static_cast<HSMSMessages::MessageType>(sType());
    }
    else
    {
        return HSMSMessages::Unknown;
    }

}

void HSMSMessages::setLength(uint32_t n)
{
    m_message[0] = static_cast<char>( (n >> 24) & 0xff);
    m_message[1] = static_cast<char>( (n >> 16) & 0xff);
    m_message[2] = static_cast<char>( (n >> 8) & 0xff);
    m_message[3] = static_cast<char>( (n >> 0) & 0xff);
}

void HSMSMessages::setSessionID(uint16_t id)
{
    m_message[4] = static_cast<char>( (id >> 8) & 0xff); //header byte 0
    m_message[5] = static_cast<char>( (id >> 0) & 0xff); //header byte 1
}

void HSMSMessages::setSteamFunction(uint8_t stream, uint8_t function)
{
    m_message[6] = static_cast<char>(stream);  //header byte 2
    m_message[7] = static_cast<char>(function); //header byte 3
}

void HSMSMessages::setPSType(uint8_t ptype, uint8_t stype)
{
    m_message[8] = static_cast<char>(ptype);  //header byte 4
    m_message[9] = static_cast<char>(stype); //header byte 5
}

void HSMSMessages::setSystemBytes(uint32_t systemByte)
{
    m_message[10] = static_cast<uchar>( (systemByte >> 24) & 0xff); //header byte 6
    m_message[11] = static_cast<uchar>( (systemByte >> 16) & 0xff); //header byte 7
    m_message[12] = static_cast<uchar>( (systemByte >> 8) & 0xff); //header byte 8
    m_message[13] = static_cast<uchar>( (systemByte >> 0) & 0xff); //header byte 9
}

uint16_t HSMSMessages::sessionID() const
{
    uint16_t ret = static_cast<uint16_t>(m_message.at(4));
    ret = (ret << 8) + static_cast<uint16_t>(m_message.at(5));
    return ret;
}

uint32_t HSMSMessages::systemBytes() const
{
//    uint32_t ret = static_cast<uint32_t>(m_message.at(10));
//    ret = (ret << 8) + static_cast<uint32_t>(m_message.at(11));
//    ret = (ret << 8) + static_cast<uint32_t>(m_message.at(12));
//    ret = (ret << 8) + static_cast<uint32_t>(m_message.at(13));
//    return ret;

    uint32_t ret = static_cast<uint32_t>((unsigned char)m_message.at(10));
    ret = (ret << 8) + static_cast<uint32_t>((unsigned char)m_message.at(11));
    ret = (ret << 8) + static_cast<uint32_t>((unsigned char)m_message.at(12));
    ret = (ret << 8) + static_cast<uint32_t>((unsigned char)m_message.at(13));

    //将static sb等于接受到的sb,防止收发双方的sb一样,注意这是一个风险点 20221001 juxing========================
    this->SystemBytes = ret;
    return ret;
    //===================================================================
//    uint32_t ret;
//    uint32_t ret1  =  m_message.at(10); //10
//    uint32_t ret2  = (m_message.at(11))<<8;//11
//    uint32_t ret3  = (m_message.at(12))<<16;//12
//    uint32_t ret4  = (m_message.at(13))<<24;//13
//    ret = (ret1) + (ret2) + (ret3) + (ret4);
//    return ret;
    //===================================================================
//    uint32_t ret_val = 0;
//    ret_val  =  m_message.at(10);
//    ret_val <<= 8;
//    ret_val |=  m_message.at(11);
//    ret_val <<= 8;
//    ret_val |=  m_message.at(12);
//    ret_val <<= 8;
//    ret_val |=  m_message.at(13);
//    return ret_val;
}

void HSMSMessages::setWBit(WBit bit)
{
    uint8_t f = function();
    uint8_t s = stream();
    if(bit == HSMSMessages::NeedReply)
    {
        s = s | 0b10000000;
    }
    else
    {
        s = s & 0b01111111;
    }
    setSteamFunction(s, f);
}

HSMSMessages HSMSMessages::S1F1(uint16_t sessionID)
{
    //SECS2Item it = SECS2Item::emptyList();
    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages m = HSMSMessages::dataMessage(sessionID, 1, 1, sb);
    m.setWBit(NeedReply);
    return m;
}

HSMSMessages HSMSMessages::S2F17(uint16_t sessionID)
{
    //SECS2Item it = SECS2Item::emptyList();
    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages m = HSMSMessages::dataMessage(sessionID, 2, 17, sb);
    m.setWBit(NeedReply);
    return m;
}

HSMSMessages HSMSMessages::S2F210(const HSMSMessages &primary, QString str)
{
    SECS2Item it;
    it.setASCII(str);
    return  HSMSMessages::replyDataMessage(primary, it);
}

HSMSMessages HSMSMessages::S2F209(QString EQPID, QString UNITID, QString OPERATORID, QString AUTHORITYCODE)
{
    SECS2Item its[4];
    its[0].setASCII(EQPID);
    its[1].setASCII(UNITID);
    its[2].setASCII(OPERATORID);
    its[3].setASCII(AUTHORITYCODE);
    SECS2Item it;
    it.setItems(its, 4);
    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages m = HSMSMessages::dataMessage(0, 2, 209, sb, it);
    m.setWBit(NeedReply);
    return m;
}

HSMSMessages HSMSMessages::S1F2(const HSMSMessages &primary, QString MDLN, QString SOFTREV)
{
    SECS2Item its[2];
    its[0].setASCII(MDLN.toLatin1().constData());
    its[1].setASCII(SOFTREV.toLatin1().constData());
    SECS2Item it;
    it.setItems(its, 2);
    return  HSMSMessages::replyDataMessage(primary, it);
}

HSMSMessages HSMSMessages::S9F1(const HSMSMessages &primary, uint16_t sessionID)
{
    SECS2Item it;
    QByteArray a(static_cast<int>(0), static_cast<char>(0));
    it.setBinary(a);
    uint32_t sb = primary.systemBytes();
    return HSMSMessages::dataMessage(sessionID, 9, 1, sb, it);
}

HSMSMessages HSMSMessages::S9F3(const HSMSMessages &primary, uint16_t sessionID)
{
    SECS2Item it;
    QByteArray a(static_cast<int>(0), static_cast<char>(0));
    it.setBinary(a);
    uint32_t sb = primary.systemBytes();
    return HSMSMessages::dataMessage(sessionID, 9, 3, sb, it);
}

HSMSMessages HSMSMessages::S9F5(const HSMSMessages &primary, uint16_t sessionID)
{
    SECS2Item it;
    QByteArray a(static_cast<int>(0), static_cast<char>(0));
    it.setBinary(a);
    uint32_t sb = primary.systemBytes();
    return HSMSMessages::dataMessage(sessionID, 9, 5, sb, it);
}


HSMSMessages HSMSMessages::replyDataMessage(const HSMSMessages &primary, SECS2Item item)
{
    uint16_t sessionID = primary.sessionID();
    uint8_t stream = primary.stream();
    uint8_t function = primary.function() + 1;
    uint32_t systemBytes = primary.systemBytes();
    return dataMessage(sessionID, stream, function, systemBytes, item);
}

HSMSMessages HSMSMessages::replyDataMessage(const HSMSMessages &primary, QString str)
{
    SECS2Item it;
    it.setASCII(str);
    return  HSMSMessages::replyDataMessage(primary, it);
}

HSMSMessages HSMSMessages::replyDataMessage(const HSMSMessages &primary, u1 bte)
{
    SECS2Item it;
    it.setUInt8(bte);
    return  HSMSMessages::replyDataMessage(primary, it);
}

HSMSMessages HSMSMessages::dataMessage(uint16_t sessionID, uint8_t stream, uint8_t function, uint32_t systemBytes)
{
    HSMSMessages ret;
    ret.setLength(10); // 不包括开头那 4 个字节
    ret.setSessionID(sessionID);
    ret.setSteamFunction(stream, function);
    ret.setPSType(0, 0);
    ret.setSystemBytes(systemBytes);
    return ret;
}

HSMSMessages HSMSMessages::dataMessage(uint16_t sessionID, uint8_t stream, uint8_t function, uint32_t systemBytes, SECS2Item item)
{
    HSMSMessages ret;
    ret.m_message.append(item.itemData());
    ret.setLength(10 + item.size()); // 不包括开头那 4 个字节
    ret.setSessionID(sessionID);
    ret.setSteamFunction(stream, function);
    ret.setPSType(0, 0);
    ret.setSystemBytes(systemBytes);
    return ret;
}

SECS2Item HSMSMessages::getItem() const
{
    SECS2Item item;
    item.loadFromByteArray(m_message.mid(14));

    return item;
}
HSMSMessages HSMSMessages::linktestReq()
{
    HSMSMessages message;
    message.setSessionID(0xFFFF);
    message.setSteamFunction(0, 0);
    message.setPSType(0, 5);
    uint32_t sb = message.uniqueSystemBytes();
    message.setSystemBytes(sb);
    return message;
}

HSMSMessages HSMSMessages::linktestRsp(uint32_t systemBytes)
{
    HSMSMessages message;
    message.setSessionID(0xFFFF);
    message.setSteamFunction(0, 0);
    message.setPSType(0, 6);
    message.setSystemBytes(systemBytes);
    return message;
}

HSMSMessages HSMSMessages::selectReq(uint16_t sessionID)
{
    HSMSMessages message;
    message.setSessionID(sessionID);
    message.setSteamFunction(0, 0);
    message.setPSType(0, 1);
    uint32_t sb = message.uniqueSystemBytes();
    message.setSystemBytes(sb);
    return message;
}

HSMSMessages HSMSMessages::selectRsp(uint16_t sessionID, uint32_t systemBytes, SelectStatus status)
{
    HSMSMessages message;
    message.setSessionID(sessionID);
    message.setSteamFunction(0, status);
    message.setPSType(0, 2);
    message.setSystemBytes(systemBytes);
    return message;
}

HSMSMessages HSMSMessages::selectRsp(const HSMSMessages &seleReq, SelectStatus status)
{
    HSMSMessages message;
    uint16_t sessionID = seleReq.sessionID();
    uint32_t systemBytes = seleReq.systemBytes();
    message.setSessionID(sessionID);
    message.setSteamFunction(0, status);
    message.setPSType(0, 2);
    message.setSystemBytes(systemBytes);
    return message;
}

HSMSMessages HSMSMessages::deselectReq(uint16_t sessionID)
{
    HSMSMessages message;
    message.setSessionID(sessionID);
    message.setSteamFunction(0, 0);
    message.setPSType(0, 3);
    uint32_t sb = message.uniqueSystemBytes();
    message.setSystemBytes(sb);
    return message;
}

HSMSMessages HSMSMessages::deselectRsp(uint16_t sessionID, uint32_t systemBytes, DeselectStatus status)
{
    HSMSMessages message;
    message.setSessionID(sessionID);
    message.setSteamFunction(0, status);
    message.setPSType(0, 4);
    message.setSystemBytes(systemBytes);
    return message;
}

HSMSMessages HSMSMessages::deselectRsp(const HSMSMessages &deseReq, DeselectStatus status)
{
    HSMSMessages message;
    uint16_t sessionID = deseReq.sessionID();
    uint32_t systemBytes = deseReq.systemBytes();
    message.setSessionID(sessionID);
    message.setSteamFunction(0, status);
    message.setPSType(0, 4);
    message.setSystemBytes(systemBytes);
    return message;
}

HSMSMessages HSMSMessages::separateReq(uint16_t sessionID)
{
    HSMSMessages message;
    message.setSessionID(sessionID);
    message.setSteamFunction(0, 0);
    message.setPSType(0, 9);
    uint32_t sb = message.uniqueSystemBytes();
    message.setSystemBytes(sb);
    return message;
}

HSMSMessages HSMSMessages::rejectReq(const HSMSMessages &mes, ReasonCode reason)
{
    uint16_t sid = mes.sessionID();
    uint32_t systemBytes = mes.systemBytes();
    uint8_t stream = mes.stream();
    HSMSMessages message;
    message.setSessionID(sid);
    message.setSteamFunction(stream, reason);
    message.setPSType(0, 7);
    message.setSystemBytes(systemBytes);
    return message;
}
