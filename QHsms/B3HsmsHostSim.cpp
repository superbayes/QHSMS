#include "B3HsmsHostSim.h"
#include <QDateTime>

B3HsmsHostSim::B3HsmsHostSim(QObject *parent)
    :HsmsHost (parent)
{
    QObject::connect(this, &HsmsDevice::dataReady, this, &B3HsmsHostSim::privateDataMessage);
    registerDataMessage(6, 11); //ControlStateChangeOnLineLocal
    registerDataMessage(1, 6); //EquipmentStatusData
    registerDataMessage(6, 209);//OperatorAuthorityRequest
    registerDataMessage(2, 210);//OperatorAuthorityDownloadReply
    registerDataMessage(6, 207);//PanelInfoRequest
    registerDataMessage(2, 208);//PanelInfoDownloadReply
    registerDataMessage(6, 3);//EqpDiscreteVariableDataSendSites
    registerDataMessage(10, 6);//TerminalDisplayMultiBlockAcknowledge

    m_OnLineLocal = false;
}

SECS2Item B3HsmsHostSim::getSingleItem4Test(QString testItemName, QString TestResult)
{
    //    6-1,<L,2                              //03_04
    //           1.<A  Device firmware version> //03
    //           2.<L,1                         //04
    //               <L,2                       //01_02
    //                    1.<A  1>              //01
    //                    2.<A  Pass(1.02.613)>	//02
    //               >
    //             >
    //        >
    SECS2Item dfv01_02[2];
    dfv01_02[0].setASCII("1");
    dfv01_02[1].setASCII(TestResult);
    SECS2Item dfv03;
    dfv03.setASCII(testItemName);
    SECS2Item dfv04;
    dfv04.setItems(dfv01_02,2);
    SECS2Item dfv03_04[2];
    dfv03_04[0] = dfv03;
    dfv03_04[1] = dfv04;
    SECS2Item project_item6_001;
    project_item6_001.setItems(dfv03_04,2);
    return project_item6_001;
}

void B3HsmsHostSim::privateDataMessage(const HSMSMessages &message)
{
    uint8_t stream = message.stream();
    uint8_t function = message.function();
    emit signals_recieveData(message);
    if(stream == 0 && function == 0)
    {
        qDebug()<<"I recieve S0F0";
        return;
    }
    if(stream == 0 && function == 1)
    {
        qDebug()<<"I recieve S0F1";
        return;
    }
    if(stream == 0 && function == 2)
    {
        qDebug()<<"I recieve S0F2";
        return;
    }
    if(stream == 0 && function == 3)
    {
        qDebug()<<"I recieve S0F3";
        return;
    }
    if(stream == 0 && function == 4)
    {
        qDebug()<<"I recieve S0F4";
        return;
    }
    if(stream == 0 && function == 5)
    {
        qDebug()<<"I recieve S0F5";
        return;
    }
    if(stream == 0 && function == 6)
    {
        qDebug()<<"I recieve S0F6";
        return;
    }
    //==============================================
    if(stream == 1 && function == 1)
    {
        qDebug()<<"I recieve S1F1";
        return;
    }
    if(stream == 1 && function == 2)
    {
        qDebug()<<"I recieve S1F2";
        return;
    }
    if(stream == 1 && function == 3)
    {
        qDebug()<<"I recieve S1F3";
        return;
    }
    if(stream == 1 && function == 4)
    {
        qDebug()<<"I recieve S1F4";
        return;
    }
    if(stream == 1 && function == 5)
    {
        qDebug()<<"I recieve S1F5";
        return;
    }
    if(stream == 1 && function == 6)
    {
        qDebug()<<"I recieve S1F6";
        return;
    }
    if(stream == 1 && function == 7)
    {
        qDebug()<<"I recieve S1F7";
        return;
    }
    //==============================================
    if(stream == 6 && function == 0)
    {
        qDebug()<<"I recieve S6F4";
        return;
    }
    if(stream == 6 && function == 1)
    {
        qDebug()<<"I recieve S6F1";
        return;
    }
    if(stream == 6 && function == 2)
    {
        qDebug()<<"I recieve S6F2";
        return;
    }
    if(stream == 6 && function == 3) //EqpDiscreteVariableDataSendSites
    {
        onReceiveS6F3(message);
        qDebug()<<"I recieve S6F3";
        return;
    }
    if(stream == 6 && function == 4)
    {
        qDebug()<<"I recieve S6F4";
        return;
    }
    if(stream == 6 && function == 11) //ControlStateChangeOnLineLocal
    {
        onReceiveS6F11(message);
        return;
    }
    if(stream == 6 && function == 209) //OperatorAuthorityRequest
    {
        onReceiveS6F209(message);
        return;
    }
    if(stream == 6 && function == 207) //PanelInfoRequest
    {
        onReceiveS6F207(message);
        return;
    }
    //=====================================================================
    if(stream == 2 && function == 210) //OperatorAuthorityDownloadReply
    {
        onReceiveS2F210(message);
        return;
    }
    if(stream == 2 && function == 208) //PanelInfoDownloadReply
    {
        onReceiveS2F208(message);
        return;
    }
    if(stream == 2 && function == 40)
    {
        qDebug()<<"I recieve S2F40;" << "NG,不允许进站";
        return;
    }
    if(stream == 2 && function == 103)
    {
        qDebug()<<"I recieve S2F103;" << "OK,允许进站";
        return;
    }
    //=========================================================================
    if(stream == 10 && function == 6) //TerminalDisplayMultiBlockAcknowledge
    {
        onReceiveS10F6(message);
        return;
    }
}
void B3HsmsHostSim::onReceiveS10F6(const HSMSMessages &message)
{
    qDebug() << "received S10F6 Message: TerminalDisplayMultiBlockAcknowledge";
    SECS2Item it = message.getItem();
    QString str = it.toASCII();
    qDebug() << "ACKC10 :" << str;
}

void B3HsmsHostSim::onReceiveS2F103(const HSMSMessages &message)
{

}

void B3HsmsHostSim::onReceiveS2F41(const HSMSMessages &message)
{

}

void B3HsmsHostSim::onReceiveS6F3(const HSMSMessages &message)
{
    qDebug() << "onReceiveS6F3========";
    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, "0");//S6,F4
    sendMessage(rsp);
}

void B3HsmsHostSim::onReceiveS6F11(const HSMSMessages &message)
{
    qDebug() << "Build S6F12 Message";
    m_OnLineLocal = true;
    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, "0");//S6,F12 EventReportAcknowledge [D=0] [len=13] [SB=2]
    sendMessage(rsp);
}

void B3HsmsHostSim::onReceiveS2F208(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QString str = it.toASCII();
    qDebug() << "S2F208: PanelInfoDownloadReply ACK is " << str;
}

void B3HsmsHostSim::onReceiveS2F210(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QString str = it.toASCII();
    if(str == "0")
    {
        qDebug() << "S2F210 : OperatorAuthorityDownloadReply ACK is OK";
    }
    else
    {
        qDebug() << "S2F210 : OperatorAuthorityDownloadReply ACK is: " << str;
    }
}

void B3HsmsHostSim::onReceiveS6F207(const HSMSMessages &message)
{
    qDebug() << "Build S6F208 Message";
    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, "0");//S6,F208 EventReportAcknowledge [D=0] [len=13] [SB=2]
    sendMessage(rsp);

    SECS2Item it = message.getItem();
    QVector<SECS2Item> list = it.toItems();

    QString EQPID = list[0].toASCII();
    QString UNITID = list[1].toASCII();
    QString PNLID = list[2].toASCII();
    QString MODULEID = list[3].toASCII();

    PANELINFOSET["EQPID"] = EQPID;
    PANELINFOSET["UNITID"] = UNITID;
    PANELINFOSET["PNLID"] = PNLID;
    PANELINFOSET["MODULEID"] = MODULEID;

    qDebug() << "S6F207: EQPID = " << EQPID << ", UNITID = " << UNITID << ", PNLID = " << PNLID << ", MODULEID = " << MODULEID;

    sendS2F207(PANELINFOSET);
}

void B3HsmsHostSim::onReceiveS1F6(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QVector<SECS2Item> list = it.toItems();
    QString SFCD = list[0].toASCII();
    QVector<SECS2Item> CREQSET = list[1].toItems();
    QString EQPID = CREQSET[0].toASCII();
    QString CRST = CREQSET[1].toASCII();
    QString EQST = CREQSET[2].toASCII();

    qDebug() << "S1F6: EQPID = " << EQPID << ", CRST = " << CRST << ", EQST = " << EQST;

}

void B3HsmsHostSim::onReceiveS6F209(const HSMSMessages &message)
{
    qDebug() << "Build S6F210 Message";
    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, "0");//S6,F12 EventReportAcknowledge [D=0] [len=13] [SB=2]
    sendMessage(rsp);
    SECS2Item it = message.getItem();
    if(it.isList())
    {
        QVector<SECS2Item> list = it.toItems();
        QString operatorID = list[2].toASCII();
        QString password = list[3].toASCII();
        if(operatorID == "30145149" && password == "BOEHF")
        {
            HSMSMessages rsp = HSMSMessages::S2F209("3MMUV011", "", operatorID, "0");
            sendMessage(rsp);
            return;
        }
        HSMSMessages rsp = HSMSMessages::S2F209("3MMUV011", "", operatorID, "1");
        sendMessage(rsp);
        return;
    }   
    return;
}

void B3HsmsHostSim::sendS1F5()
{
    sendS1F5("1");
}

void B3HsmsHostSim::sendS1F5(QString str)
{
    SECS2Item it;
    it.setASCII(str);
    HSMSMessages m = HSMSMessages::dataMessage(0, 1, 5, 1, it);
    m.setWBit(HSMSMessages::NeedReply);
    sendMessage(m);
}

void B3HsmsHostSim::sendS6F3(QString CEID, QString EQUIPMENTID, QString UNITID, QString PRODUCTID, QString RECIPEID)
{
    //====================================================================================================
    //1.<A  CEID>
    //2.<A  EQUIPMENTID>
    //3.<A  UNITID>
    //4.<A  PRODUCTID>
    //5.<A  RECIPEID>
    SECS2Item CEID_SECS2Item("CEID");
    SECS2Item EQUIP_SECS2Item("EQUIPMENTID");
    SECS2Item UNITID_SECS2Item("UNITID");
    SECS2Item PRODUCTID_SECS2Item("RODUCTID");
    SECS2Item RECIPEID_SECS2Item("RECIPEID");
    CEID_SECS2Item.setASCII(CEID);
    EQUIP_SECS2Item.setASCII(EQUIPMENTID);
    UNITID_SECS2Item.setASCII(UNITID);
    PRODUCTID_SECS2Item.setASCII(PRODUCTID);
    RECIPEID_SECS2Item.setASCII(RECIPEID);
    SECS2Item SECS2Item_profile[5];//5个profile
    SECS2Item_profile[0] = SECS2Item(CEID_SECS2Item);
    SECS2Item_profile[1] = SECS2Item(EQUIP_SECS2Item);
    SECS2Item_profile[2] = SECS2Item(UNITID_SECS2Item);
    SECS2Item_profile[3] = SECS2Item(PRODUCTID_SECS2Item);
    SECS2Item_profile[4] = SECS2Item(RECIPEID_SECS2Item);
    //=====================================================================================================
    //6.<L,20
    //    6-1,<L,2                              //03_04
    //           1.<A  Device firmware version> //03
    //           2.<L,1                         //04
    //               <L,2                       //01_02
    //                    1.<A  1>              //01
    //                    2.<A  Pass(1.02.613)>	//02
    //               >
    //             >
    //        >
    SECS2Item dfv01_02[2];
    dfv01_02[0].setASCII("1");
    dfv01_02[1].setASCII("Pass(1.02.613)");
    SECS2Item dfv03;
    dfv03.setASCII(QString("Device firmware version"));
    SECS2Item dfv04;
    dfv04.setItems(dfv01_02,2);
    SECS2Item dfv03_04[2];
    dfv03_04[0] = dfv03;
    dfv03_04[1] = dfv04;
    SECS2Item project_item6_001;
    project_item6_001.setItems(dfv03_04,2);

    //    6-2,<L,2                          //03_04
    //           1.<A  Device Phase ID>     //03
    //           2.<L,1                     //04
    //               <L,2                   //01_02
    //                    1.<A  1>          //01
    //                    2.<A  Pass(04)>	//02
    //               >
    //           >
    //       >
    SECS2Item dpi01_02[2];
    dpi01_02[0].setASCII("1");
    dpi01_02[1].setASCII("Pass(04)");
    SECS2Item dpi03;
    dpi03.setASCII(QString("Device Phase ID"));
    SECS2Item dpi04;
    dpi04.setItems(dpi01_02,2);
    SECS2Item dpi03_04[2];
    dpi03_04[0] = dpi03;
    dpi03_04[1] = dpi04;
    SECS2Item project_item6_002;
    project_item6_002.setItems(dpi03_04,2);
    //    6-3,<L,2                                          //03_04
    //           1.<A  LT7911D bridge firmware version>     //03
    //           2.<L,1                                     //04
    //               <L,2                                   //01_02
    //                    1.<A  1>                          //01
    //                    2.<A  Pass(97)>                   //02
    //               >
    //           >
    //       >
    SECS2Item LT7911D01_02[2];
    LT7911D01_02[0].setASCII("1");
    LT7911D01_02[1].setASCII("Pass(97)");
    SECS2Item LT7911D03;
    LT7911D03.setASCII(QString("LT7911D bridge firmware version"));
    SECS2Item LT7911D04;
    LT7911D04.setItems(LT7911D01_02,2);
    SECS2Item LT7911D03_04[2];
    LT7911D03_04[0] = LT7911D03;
    LT7911D03_04[1] = LT7911D04;
    SECS2Item project_item6_003;
    project_item6_003.setItems(LT7911D03_04,2);
    //    6-4,<L,2                                             //03_04
    //           1.<A  Read MCU UID>                           //03
    //           2.<L,1                                        //04
    //               <L,2                                      //01_02
    //                    1.<A  1>                             //01
    //                    2.<A  Pass(203239411111111111111)>   //02
    //               >
    //           >
    //       >
    SECS2Item rmu01_02[2];
    rmu01_02[0].setASCII("1");
    rmu01_02[1].setASCII("Pass(203239411111111111111)");
    SECS2Item rmu03;
    rmu03.setASCII(QString("Read MCU UID"));
    SECS2Item rmu04;
    rmu04.setItems(rmu01_02,2);
    SECS2Item rmu03_04[2];
    rmu03_04[0] = rmu03;
    rmu03_04[1] = rmu04;
    SECS2Item project_item6_004;
    project_item6_004.setItems(rmu03_04,2);
    //    6-5,<L,2                          //03_04
    //           1.<A  Proximity test>      //03
    //           2.<L,1                     //04
    //               <L,2                   //01_02
    //                    1.<A  1>          //01
    //                    2.<A  NO_TEST>	//02
    //               >
    //           >
    //       >
    SECS2Item p65_01_02[2];
    p65_01_02[0].setASCII("1");
    p65_01_02[1].setASCII("NO_TEST");
    SECS2Item p65_03;
    p65_03.setASCII(QString("Proximity test"));
    SECS2Item p65_04;
    p65_04.setItems(p65_01_02,2);
    SECS2Item p65_03_04[2];
    p65_03_04[0] = p65_03;
    p65_03_04[1] = p65_04;
    SECS2Item project_item6_005;
    project_item6_005.setItems(p65_03_04,2);





    //Alice_L10 镜身测试,暂时写到这里==================
    SECS2Item project_item6_ALL[5];
    project_item6_ALL[0] = project_item6_001;
    project_item6_ALL[1] = project_item6_002;
    project_item6_ALL[2] = project_item6_003;
    project_item6_ALL[3] = project_item6_004;
    project_item6_ALL[4] = project_item6_005;
    SECS2Item project_item6_one = SECS2Item::SECS2ItemList2SECS2Item(project_item6_ALL,5);
    //=====================================================================================================
    SECS2Item it =SECS2Item::SECS2ItemList2SECS2Item(SECS2Item_profile,5);;
    it.merge(&project_item6_one,1);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 3, sb, project_item6_one);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsHostSim::sendS6F3(SECS2Item& item)
{
    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 3, sb, item);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsHostSim::sendS2F41(SECS2Item &item)
{

}

void B3HsmsHostSim::sendS2F103(SECS2Item &item)
{

}

void B3HsmsHostSim::sendS6F11_370(QString DATAID,QString CEID,QString EQUIPMENTID,QString DIEID,QString ECIPEID,QString TRAYID)
{
    auto qstringToU32 = [&](QString number)->QVector<U4>{
        QByteArray tmp = number.toUtf8();
        QVector<U4> res;
        for(int i=0;i<tmp.size();++i){
            res[i] = tmp[i];
        }
        return res;
    };
    //====================================================================================================
    //<L[3]               listALL[3]
    //1.<U4 DATAID>
    //2.<U4 CEID>
    //3.<L[1]      t03
        //1.<L[2]  t03_2
            //1.<A 370> /* fix RPTID = 370 */
            //2.<L[4]  t03_3,t03_2[1]
                //1.<A EQUIPMENTID>
                //2.<A DIEID>
                //3.<A ECIPEID>Page 86/128
                //4.<A TRAYID>


    SECS2Item listALL[3];
    SECS2Item DATAID_SECS2Item("DATAID");
    SECS2Item CEID_SECS2Item("CEID");
    listALL[0].setUInt32(qstringToU32(DATAID).data(),DATAID.length());
    listALL[1].setUInt32(qstringToU32(CEID).data(),DATAID.length());

    SECS2Item t03;

    SECS2Item t03_2[2];
    t03_2[0].setASCII("370");

    SECS2Item t03_3[4];
    t03_3[0].setASCII(EQUIPMENTID);
    t03_3[1].setASCII(DIEID);
    t03_3[2].setASCII(ECIPEID);
    t03_3[3].setASCII(TRAYID);

    t03_2[1] = SECS2Item::SECS2ItemList2SECS2Item(t03_3,4);
    t03 = SECS2Item::SECS2ItemList2SECS2Item(t03_2,2);
    listALL[2] = t03;

    SECS2Item finalRes = SECS2Item::SECS2ItemList2SECS2Item(listALL,3);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 11, sb, finalRes);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsHostSim::sendS6F11_371_372(
        QString DATAID,
        QString CEID,
        QString EQUIPMENTID,
        QString UNITID,
        QString TRAYID,
        QString PTID,
        QString RECIPEID,
        QString DIEID,
        QString TIMESTAMP
        )
{
    auto qstringToU32 = [&](QString number)->QVector<U4>{
        QByteArray tmp = number.toUtf8();
        QVector<U4> res;
        for(int i=0;i<tmp.size();++i){
            res[i] = tmp[i];
        }
        return res;
    };
    //====================================================================================================
    //<L[3]                 ;t01[3]
        //1.<U4 DATAID>
        //2.<U4 CEID>
        //3.<L[1]           ;t02
            //1.<L[2]       ;t03[2]
                //1.<A 371>
                //2.<L[7]   ;t04[7]
                    //1.<A EQUIPMENTID>
                    //2.<A UNITID>
                    //3.<A TRAYID>
                    //4.<A PTID>
                    //5.<A RECIPEID>
                    //6.<A DIEID>
                    //7.<A TIMESTAMP>

    SECS2Item t01[3];
    t01[0].setUInt32(qstringToU32(DATAID).data(),DATAID.length());
    t01[1].setUInt32(qstringToU32(CEID).data(),DATAID.length());

    SECS2Item t03[2];
    t03[0].setASCII(CEID);

    SECS2Item t04[7];
    t04[0].setASCII(EQUIPMENTID);
    t04[1].setASCII(UNITID);
    t04[2].setASCII(TRAYID);
    t04[3].setASCII(PTID);
    t04[4].setASCII(RECIPEID);
    t04[5].setASCII(DIEID);
    t04[6].setASCII(TIMESTAMP);

    t03[1] = SECS2Item::SECS2ItemList2SECS2Item(t04,7);

    SECS2Item t02 = SECS2Item::SECS2ItemList2SECS2Item(t03,2);
    t01[2] = t02;

    SECS2Item finalRes = SECS2Item::SECS2ItemList2SECS2Item(t01,3);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 11, sb, finalRes);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsHostSim::sendS6F11_482(
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
        )
{
    //<L[3]             ;t01[3];
        //1.<U4 DATAID> ;
        //2.<U4 CEID>
        //3.<L[1]       ;t02;
            //1.<L[2]   ;t03[2];
                //1.<A 482>
                //2.<L[11]  ;t04[11];
                    //1.<A EQUIPMENTID>
                    //2.<A DIEID>
                    //3.<A PTID>
                    //4.<A Station>
                    //5.<A INSPECTIONSTARTTIME>
                    //6.<A INSPECTIONENDTIME>
                    //7.<A PRODUCTJUDGE>
                    //8.<U4 INSPECTIONTIME>
                    //9.< A TIMESTAMP>
                    //10.<A JUDGECODE>
                    //11.<A TrayID>
    auto qstringToU32 = [&](QString number)->QVector<U4>{
        QByteArray tmp = number.toUtf8();
        QVector<U4> res;
        for(int i=0;i<tmp.size();++i){
            res[i] = tmp[i];
        }
        return res;
    };
    //====================================================================================================
    SECS2Item t01[3];
    t01[0].setUInt32(qstringToU32(DATAID).data(),DATAID.length());
    t01[1].setUInt32(qstringToU32(CEID).data(),DATAID.length());

    SECS2Item t03[2];
    t03[0].setASCII("482");

    SECS2Item t04[11];
    t04[0].setASCII(EQUIPMENTID);
    t04[1].setASCII(DIEID);
    t04[2].setASCII(PTID);
    t04[3].setASCII(Station);
    t04[4].setASCII(INSPECTIONSTARTTIME);
    t04[5].setASCII(INSPECTIONENDTIME);
    t04[6].setASCII(PRODUCTJUDGE);
    t04[7].setASCII(INSPECTIONTIME);
    t04[8].setASCII(TIMESTAMP);
    t04[9].setASCII(JUDGECODE);
    t04[10].setASCII(TrayID);

    t03[1] = SECS2Item::SECS2ItemList2SECS2Item(t04,11);

    SECS2Item t02 = SECS2Item::SECS2ItemList2SECS2Item(t03,2);

    t01[2] = t02;

    SECS2Item finalRes = SECS2Item::SECS2ItemList2SECS2Item(t01,3);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 11, sb, finalRes);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsHostSim::sendS2F207(QMap<QString, QString> PANELINFOSET)
{
    SECS2Item its[17];
    if(PANELINFOSET["PNLID"] == "3AUE090016A4BM")
    {
        PANELINFOSET["RTCODE"] = "0";
        PANELINFOSET["FGCODE"] = "TV080WUM-AS0-38P0";
    }
    else {
        PANELINFOSET["RTCODE"] = "1";
        PANELINFOSET["FGCODE"] = "";
    }
    its[0].setASCII(PANELINFOSET["RTCODE"]);
    its[1].setASCII(PANELINFOSET["EQPID"]);
    its[2].setASCII(PANELINFOSET["UNITID"]);
    its[3].setASCII(PANELINFOSET["PNLID"]);
    its[4].setASCII(PANELINFOSET["MODULEID"]);
    its[5].setASCII(PANELINFOSET["FGCODE"]);
    its[6].setASCII(PANELINFOSET["WORKORDER"]);
    its[7].setASCII(PANELINFOSET["PNLJUDGE"]);
    its[8].setASCII(PANELINFOSET["PNLGRADE"]);
    its[9].setASCII(PANELINFOSET["REASONCODE"]);
    its[10].setASCII(PANELINFOSET["CURRENTSTEP"]);
    its[11].setASCII(PANELINFOSET["GROUPID"]);
    its[12].setASCII(PANELINFOSET["INSPFILENAME"]);
    its[13].setASCII(PANELINFOSET["INSPFILEPATH"]);
    its[14].setASCII(PANELINFOSET["REVISION"]);
    its[15].setASCII(PANELINFOSET["CELLGRADE"]);
    its[16].setASCII(PANELINFOSET["WOGRADE"]);

    SECS2Item it;
    it.setItems(its, 17);

    HSMSMessages rsp = HSMSMessages::dataMessage(0, 2, 207, 0, it);
    sendMessage(rsp);
}
