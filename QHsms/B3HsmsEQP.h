#ifndef B3HSMSEQP_H
#define B3HSMSEQP_H
#include "HsmsEQP.h"
#include <QDateTime>

struct MyPRODUCTJUDGE{
    QString G = "G";
    QString N = "N";
    QString R = "R";
    QString P = "P";
    QString S = "S";

    QString Good = "G";
    QString No_Good = "N";
    QString Rework = "R";
    QString Repair = "P";
    QString Scrap = "S";
};
struct MyJUDGECODE{
    QString Unknown = "";
//    测试时可以按以下报：
//    judge grade：G ，judge code：GNA
//    judge grade：R ，judge code：ADR01
    QString Good = "GNA";
    QString No_Good = "N";
    QString Rework = "ADR01";
};
struct MyEQUIPMENTID{
    QString Unknown = "";
    QString Alice_L10_glassLeg = "M3KC0100";
    QString Alice_L10_glassBody = "M3KF0100";
    QString Alice_L10_imu = "M3KH0100";
    QString Alice_L10_zhengji = "M3KG0100";
};

//EQUIPMENTID
static MyPRODUCTJUDGE MyProductJudge;
static MyJUDGECODE MyJudgeCode;
static MyEQUIPMENTID MyEquipmentId;

class B3HsmsEQP : public HsmsEQP
{
    Q_OBJECT
public:
    B3HsmsEQP(QObject *parent = nullptr);
    void setEQPID(QString EQPID) {m_EQPID = EQPID;}
    void setUNITID(QString UNITID) {m_UNITID = UNITID;}
    void setMODULEID(QString MODULEID) {m_MODULEID = MODULEID;}
    QString getPanelInfo(QString itemName);

    //设备连接状态枚举
    enum eqp_connectSatus{
        offline=1,
        online=2
    };
    int m_eqp_connectSatus = 1;

public slots:
    void sendS6F11(); //ControlStateChangeOnLineLocal
    void sendS6F209(QString OPERATORID, QString PASSWORD); //OperatorAuthorityRequest
    void sendS6F207(QString PNLID); //PanelInfoRequest
    void sendS6F3(QString PNLID, QVector< QPair<QString, QString>> data);
    void sendS6F3(QString CEID,QString EQUIPMENTID,QString UNITID,QString PRODUCTID,QString RECIPEID/*, QVector<QPair<QString, QString>>data*/);
public:
    //void sendS2F42(); //进站NG,回复s2f41

    //进站OK,并且在发送此指令后要追加发送s6f11_371, 回复s2f103,
    //void sendS2F104(u1 S,u1 F,u4 sb,QString type/*0: Accepted|1: Busy|2: PPID is Invalid|3s: Other Errors*/);

public slots:
    //alice l10 添加
    void sendS6F3(SECS2Item& item);//不良测试项不能上传，字节太长
    /**
      * @brief 001
      * @brief sendS6F11:扫码之后,dieIDupload,包含产品SN,CEID=370,client TO HOST
      * @brief 等待MES返回:S2F103	进站成功
      * @brief 等待MES返回:S2F41	失败
      * ========================================================================
      * @brief 002,PROCESS START,        CEID=371,      TO HOST,向MES发送开始测试指令
      * ========================================================================
      * @brief 004,PROCESS COMPLETE, 	 CEID=482	    TO HOST,向MES发送完成指令
      * ========================================================================
      * @brief 005,PROCESS END           CEID=372		TO HOST,向MES发送结束指令
      *
       **/
    void sendS6F11_370(
            QString DATAID,
            QString CEID,
            QString EQUIPMENTID,
            QString DIEID,
            QString RECIPEID,
            QString TRAYID);//001

    void sendS6F11_371_372(
            QString DATAID,
            QString CEID,
            QString EQUIPMENTID,
            QString UNITID,
            QString TRAYID,
            QString PTID,
            QString RECIPEID,
            QString DIEID,
            QString TIMESTAMP
            );//002,004,005

    void sendS6F11_482(
            QString DATAID,
            QString CEID,
            QString EQUIPMENTID,
            QString DIEID,
            QString PTID,
            QString Station,
            QString INSPECTIONSTARTTIME,
            QString INSPECTIONENDTIME,
            QString PRODUCTJUDGE,
            QString INSPECTIONTIME,
            QString TIMESTAMP,
            QString JUDGECODE,
            QString TrayID
            );

    /**
     * @brief sendS6F11_104 在线/离线模式请求,当机台连接状态改变,S1F4的参数也会发生变化
     * @param CRST:  O:ON-LINE|F:OFF-LINE|L:ONLINE-LOCAL
     * @param EQST: I: IDLE,R:RUN,D:DOWN,P: PM
     **/
    void sendS6F11_104(QString DATAID,QString CEID,QString CRST,QString EQST = "R");

signals:
    void loginStatus(bool ok);
    void dateTimeReplyReceived(QDateTime dt);
    /**
     * @brief onlineLocal
     * @param ok   true 表示成功切换到ONLINE 模式
     *             false 表示失败
     *             TODO：这里应该在加入第三种状态，命令超时
     */
    void onlineLocal(bool ok);
    void panelInfoUpdated(bool ok);
private slots:
    void privateDataMessage(const HSMSMessages &message);
private:
    SECS2Item buildS6F3Item(QString PNLID, QString DVNAME, QVector< QPair<QString, QString> > data);
    void onReceiveS2F207(const HSMSMessages &message); //PANELINFOSET
    void onReceiveS6F12(const HSMSMessages &message); //EventReportAcknowledge
    void onReceiveS2F18(const HSMSMessages &message); //Date and time data
    void onReceiveS1F5(const HSMSMessages &message); //Formatted status request
    void onReceiveS6F210(const HSMSMessages &message); //OperatorAuthorityRequestReply
    void onReceiveS6F4(const HSMSMessages &message);//DiscreteVariableDataAcknowledge
    void onReceiveS2F209(const HSMSMessages &message);
    void onReceiveS6F208(const HSMSMessages &message); //PanelInfoRequestReply
    void onReceiveS10F5(const HSMSMessages &message);//Terminal display, multi-block
    void onReceiveS1F3(const HSMSMessages &message,int type = 1/*回复机台状态. 1:offline;2:online*/);
    void onReceiveS2F41(const HSMSMessages &message,u1 type = 0/*回复NG. 0:accept;1:no accept*/);//进站NG,回复s2f41
    //进站成功,向host发送S2F104,sendS6F11_371
    void onReceiveS2F103(const HSMSMessages &message,int type=0/*0: Accepted; 1: Busy; 2: PPID is Invalid;3: Other Errors*/);

    void onReceiveS7F19(const HSMSMessages &message,QString PPID = "DUMMY");

    //ACKC10:
    //0: Accepted for display
    //1: Message will not be displayed
    //2: Terminal not available
    void onReceiveS10F3(const HSMSMessages &message,u1 ACKC10 = 1);

    QMap<QString, QString> m_PANELINFOSET;
    QString m_EQPID;
    QString m_UNITID;
    QString m_MODULEID;
    QString m_DVNAME;
    QString m_CRST;
    QString m_EQST;
};

#endif // B3HSMSEQP_H
