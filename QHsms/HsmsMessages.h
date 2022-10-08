#ifndef HSMSMESSAGES_H
#define HSMSMESSAGES_H

#ifndef SECS2ItemVector
#define SECS2ItemVector std::vector<SECS2Item>
#endif

#include "SECS2Item.h"


/**
 * @brief The HSMSMessages class 一个 HSMS 消息由 4 字节消息长度，10字节 header ，任意长度的数据组成
 * 消息长度为 header 长度 + 数据长度
 */
class HSMSMessages
{
public:
    enum SelectStatus{ConnectEstablished = 0, AlreadyActive = 1, NotReady = 2, ConnectExhaust = 3};
    enum DeselectStatus{CommunicationEnded = 0, CommunicationNotEstablished = 1, CommunicationBusy = 2};
    enum ReasonCode{STypeNotSupported = 1, PTypeNotSupported = 2, TransactionNotOpen = 3, EntityNotSelected = 4};
    enum WBit{NeedReply = 1, NoReply = 0};
    enum MessageType{ Unknown = -1,
                      DataMessage = 0,
                      SelectReq = 1,
                      SelectRsp = 2,
                      DeselectReq = 3,
                      DeselectRsp = 4,
                      LinktestReq = 5,
                      LinktestRsp = 6,
                      RejectReq = 7,
                      SeparateReq = 9};
    HSMSMessages();
    QByteArray toByteArray() const {return m_message;}
    MessageType loadFromByteArray(const QByteArray &array);

    QString toLogString() const;

    uint16_t sessionID() const;
    uint32_t systemBytes() const;
    uint8_t pType() const {return static_cast<uint8_t>(m_message.at(8));}
    int8_t sType() const {return static_cast<int8_t>(m_message.at(9));}
    uint8_t stream() const {return static_cast<uint8_t>(m_message.at(6) & 0b01111111);}
    uint8_t function() const {return static_cast<uint8_t>(m_message.at(7));}

    SECS2Item getItem() const ;
    static HSMSMessages S1F1(uint16_t sessionID);
    static HSMSMessages S2F17(uint16_t sessionID); //DateTimeRequest
    static HSMSMessages S2F209(QString EQPID, QString UNITID, QString OPERATORID, QString AUTHORITYCODE);
    static HSMSMessages S2F210(const HSMSMessages &primary, QString str);
    static HSMSMessages S1F2(const HSMSMessages &primary, QString MDLN, QString SOFTREV); //S1,F2 On Line Data (D)
    static HSMSMessages S9F1(const HSMSMessages &primary, uint16_t sessionID); //S9F1 Unrecognized Device ID (UDN)
    static HSMSMessages S9F3(const HSMSMessages &primary, uint16_t sessionID); //S9F3 Unrecognized Stream Type (USN)
    static HSMSMessages S9F5(const HSMSMessages &primary, uint16_t sessionID); //S9F5 Unrecognized Function Type (UFN)

    static HSMSMessages replyDataMessage(const HSMSMessages &primary, SECS2Item item);
    static HSMSMessages replyDataMessage(const HSMSMessages &primary, QString str);
    static HSMSMessages replyDataMessage(const HSMSMessages &primary, u1 bte);
    static HSMSMessages dataMessage(uint16_t sessionID, uint8_t stream, uint8_t function, uint32_t systemBytes);
    static HSMSMessages dataMessage(uint16_t sessionID,
                                    uint8_t stream,
                                    uint8_t function,
                                    uint32_t systemBytes,
                                    SECS2Item item);
    void setWBit(WBit bit);
    static HSMSMessages selectReq(uint16_t sessionID);
    static HSMSMessages selectRsp(uint16_t sessionID, uint32_t systemBytes, SelectStatus status);
    static HSMSMessages selectRsp(const HSMSMessages & seleReq, SelectStatus status);

    static HSMSMessages deselectReq(uint16_t sessionID);
    static HSMSMessages deselectRsp(uint16_t sessionID, uint32_t systemBytes, DeselectStatus status);
    static HSMSMessages deselectRsp(const HSMSMessages &deseReq, DeselectStatus status);

    static HSMSMessages linktestReq();
    static HSMSMessages linktestRsp(uint32_t systemBytes);

    static HSMSMessages rejectReq(const HSMSMessages& mes, ReasonCode reason);
    static HSMSMessages separateReq(uint16_t sessionID);

    /**
     * @brief setSteamFunction 设置 Stream 和 Function
     * @param stream
     * @param function
     */
    void setSteamFunction(uint8_t stream, uint8_t function);
    void setSessionID(uint16_t id);
    void setPSType(uint8_t ptype, uint8_t stype);
    void setSystemBytes(uint32_t systemByte);
    static uint32_t uniqueSystemBytes();
//private:
public:
    /**
     * @brief setLength 设置消息长度，这里的长度不包括前 4 个字节
     * @param n
     */
    void setLength(uint32_t n);
    static uint32_t SystemBytes;
    static uint32_t SystemBytes_counter;
    QByteArray m_message;
};

#endif // HSMSMESSAGES_H
