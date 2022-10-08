#ifndef HSMSDEVICE_H
#define HSMSDEVICE_H
#pragma execution_character_set("utf-8")
#include <QObject>
#include <QSet>
#include <QTcpSocket>
#include "HsmsMessages.h"

/**
 * @brief The HsmsDevice class HSMS Host 和 HSMS EQP 的公共基类。
 *                   包含 HSMS 通讯的一些公共的功能。
 */
class HsmsDevice : public QObject
{
    Q_OBJECT
public:
    explicit HsmsDevice(QObject *parent = nullptr);
    void setMDLN(QString mdln);
    void setSOFTREV(QString rev);
    void setSessionID(uint16_t sessionID);
    void registerDataMessage(uint8_t stream, uint8_t function);
    void unRegisterDataMessage(uint8_t stream, uint8_t function);

signals:
    void dataReady(HSMSMessages dataMessage);
    void selectReqReceived(HSMSMessages selectReqMessage);
    void selectRspReceived(HSMSMessages selectRspMessage);
    void deselectReqReceived(HSMSMessages deselectReqMessage);
    void deselectRspReceived(HSMSMessages deselectRspMessage);
    void linktestReqReceived(HSMSMessages linktestReqMessage);
    void linktestRspReceived(HSMSMessages linktestRspMessage);
    void separateReqReceived(HSMSMessages separateReqMessage);
    void rejectReqReceived(HSMSMessages separateReqMessage);
    void signals_eqp_recieve_S_F(u1 S,u1 F,u4 sb,QString log);
    void signals_eqp_send_S_F_sb(u1 S,u1 F,u4 sb,QString log);

public slots:
    void sendMessage(const HSMSMessages &message);
    void sendLinkTestReq();
    void sendSelectReq();
    void sendDeselectReq();
    void sendSeparateReq();
    void sendS1F1(); //AreYouThere
    void sendS2F17(); //DateTimeRequest
    void readMessage();

protected slots:
    void sendSelectRsp(uint16_t sessionID, uint32_t systemBytes, HSMSMessages::SelectStatus status);
    void sendSelectRsp(const HSMSMessages &seleReq, HSMSMessages::SelectStatus status);
    void sendDeselectRsp(uint16_t sessionID, uint32_t systemBytes, HSMSMessages::DeselectStatus status);
    void sendDeselectRsp(const HSMSMessages &deseReq, HSMSMessages::DeselectStatus status);
    void sendLinkTestRsp(uint32_t systemBytes);
    void sendLinkTestRsp(const HSMSMessages &linktestReq);
    virtual void displayError(QAbstractSocket::SocketError);    
protected:
    void decodeMessge();
    void onDataMessage();
    void onReceiveS1F1(const HSMSMessages &message); //AreYouThere
    //void onReceiveS1F3(const HSMSMessages &message,QString type= "1"/*回复机台状态. 1:offline;2:online*/);
    void onReceiveS1F13(const HSMSMessages &message,u1 type=0/*0: Accepted; 1: Denied,try again*/);
    void onReceiveS2F17(const HSMSMessages &message); //DateTimeRequest
//    virtual void onReceiveS2F41(const HSMSMessages &message,u1 type=0/*0: Accepted; 1:not Accepted*/);//s2f42
    //virtual void onReceiveS2F103(const HSMSMessages &message,QString type=0/*0: Accepted; 1: Busy; 2: PPID is Invalid;3: Other Errors*/);//s2f104

    //0: Accepted; 1: Busy; 2: PPID is Invalid;3s: Other Errors
    //virtual privateDataMessage(const HSMSMessages message) = 0;
protected:
    uint16_t m_sessionID;
    QTcpSocket * m_tcpSocket;
    QString m_ip;
    uint16_t m_port;
    QByteArray m_buffer;
    int m_messageLength;
    HSMSMessages m_receivedMessage;
    HSMSMessages::MessageType m_messageType;

    QSet<uint8_t> m_streamSet;
    QSet<uint8_t> m_functionSet;
    QSet<uint16_t> m_sfSet;

    QString m_MDLN; //Equipment Model Type, 20bytes max
    QString m_SOFTREV;  //Software revision code, 20bytes max
};

#endif // HSMSDEVICE_H
