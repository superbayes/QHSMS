#ifndef HOSTSIM_H
#define HOSTSIM_H

#include "HsmsHost.h"
class B3HsmsHostSim : public HsmsHost
{
    Q_OBJECT
public:
    B3HsmsHostSim(QObject *parent = nullptr);
    /**
     * *******************************************
     * 	   <L,2
     *         1.<A  Device firmware version>
     *	   	2.<L,1
     *     		<L,2
     *     			 1.<A  1>
     *     			 2.<A  Pass(1.02.613)>
     *     		>
     *     	>
     *     >
     * *******************************************
     *
     *
     * @brief getSingleItem4Test 返回一个 SECS2Item,将每一项单独的测试项封装为一个item
     * @param testItemName,for example:"Device firmware version"
     * @param TestResult,for example:"Pass(1.02.613)"
     * @return
     *
     */
    static SECS2Item getSingleItem4Test(QString testItemName,QString TestResult);

public slots:
    void sendS2F207( QMap<QString, QString> PANELINFOSET);
    void sendS1F5();
    void sendS1F5(QString str);
    void sendS6F3(QString CEID,QString EQUIPMENTID,QString UNITID,QString PRODUCTID,QString RECIPEID/*, QVector<QPair<QString, QString>>data*/);
    void sendS6F3(SECS2Item& item);//不良测试项不能上传，字节太长
    void sendS2F41(SECS2Item& item);//NG,不允许进站
    void sendS2F103(SECS2Item& item);//OK,允许进站
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
            QString ECIPEID,
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

private slots:
    void privateDataMessage(const HSMSMessages &message);
private:
    void onReceiveS1F6(const HSMSMessages &message);//EquipmentStatusData
    void onReceiveS2F208(const HSMSMessages &message);//PanelInfoDownloadReply
    void onReceiveS2F210(const HSMSMessages &message);//OperatorAuthorityDownloadReply
    void onReceiveS6F11(const HSMSMessages &message); //ControlStateChangeOnLineLocal
    void onReceiveS6F207(const HSMSMessages &message); //PanelInfoRequest
    void onReceiveS6F209(const HSMSMessages &message);//OperatorAuthorityRequest, 验证工号密码
    void onReceiveS6F3(const HSMSMessages &message);//EqpDiscreteVariableDataSendSites
    void onReceiveS10F6(const HSMSMessages &message); //TerminalDisplayMultiBlockAcknowledge 异常推送

    //send S2F103之后MES返回的结果
    void onReceiveS2F103(const HSMSMessages &message);//OK,允许进站
    void onReceiveS2F41(const HSMSMessages &message);//NG,不允许进站



    QMap<QString, QString> PANELINFOSET;
    bool m_OnLineLocal;
    QString m_operatorID;
    QString m_password;

signals:
    void signals_recieveData(const HSMSMessages &message);

};

#endif // HOSTSIM_H
