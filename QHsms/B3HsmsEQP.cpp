#include "B3HsmsEQP.h"
#include <QDateTime>
#include <QMessageBox>
#include <QMultiHash>

B3HsmsEQP::B3HsmsEQP(QObject *parent)
    :HsmsEQP (parent)
{
    QObject::connect(this, &HsmsDevice::dataReady, this, &B3HsmsEQP::privateDataMessage);
    registerDataMessage(1, 3);
    registerDataMessage(1, 5);
    registerDataMessage(1, 13);
    registerDataMessage(2, 207);//PANELINFOSET
    registerDataMessage(2, 209);
    registerDataMessage(2, 18); //DateTimeRequest
    registerDataMessage(6, 4); //DiscreteVariableDataAcknowledge
    registerDataMessage(6, 12); //EventReportAcknowledge
    registerDataMessage(6, 210);
    registerDataMessage(6, 208); //PanelInfoRequestReply
    registerDataMessage(7, 19);//查询设备配方
    registerDataMessage(10, 3);//for display
    registerDataMessage(10, 5);
}
void B3HsmsEQP::sendS6F3(QString PNLID, QVector<QPair<QString, QString> > data)
{
    SECS2Item DVDATASET = buildS6F3Item(PNLID, m_DVNAME, data);
    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 3, sb, DVDATASET);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsEQP::sendS6F3(
        QString CEID,
        QString EQUIPMENTID,
        QString UNITID,
        QString PRODUCTID,
        QString RECIPEID/*, QVector<QPair<QString, QString> > data*/)
{
#if 0
    //====================================================================================================
    QByteArray ceid_arr;
    ceid_arr.append("A");
    ceid_arr.append(QString::number(CEID.length()));
    ceid_arr.append(CEID.toLatin1().constData());
    //==================================================
    QByteArray equp_arr;
    equp_arr.append("A");
    equp_arr.append(QString::number(EQUIPMENTID.length()));
    equp_arr.append(EQUIPMENTID.toLatin1().constData());
    //==================================================
    QByteArray UNITID_arr;
    UNITID_arr.append("A");
    UNITID_arr.append(QString::number(UNITID.length()));
    UNITID_arr.append(UNITID.toLatin1().constData());
    //==================================================
    QByteArray PRODUCTID_arr;
    PRODUCTID_arr.append("A");
    PRODUCTID_arr.append(QString::number(PRODUCTID.length()));
    PRODUCTID_arr.append(PRODUCTID.toLatin1().constData());
    //==================================================
    QByteArray RECIPEID_arr;
    RECIPEID_arr.append("A");
    RECIPEID_arr.append(QString::number(RECIPEID.length()));
    RECIPEID_arr.append(RECIPEID.toLatin1().constData());
    //===================================================
    SECS2Item CEID_SECS2Item("CEID");
    SECS2Item EQUIP_SECS2Item("EQUIP");
    SECS2Item UNITID_SECS2Item("UNITID");
    SECS2Item PRODUCTID_SECS2Item("RODUCTID");
    SECS2Item RECIPEID_SECS2Item("RECIPEID");
    CEID_SECS2Item.setASCII(QString(ceid_arr));
    EQUIP_SECS2Item.setASCII(QString(equp_arr));
    UNITID_SECS2Item.setASCII(QString(UNITID_arr));
    PRODUCTID_SECS2Item.setASCII(QString(PRODUCTID_arr));
    RECIPEID_SECS2Item.setASCII(QString(RECIPEID_arr));
    //=====================================================================================================
    SECS2Item its[6];
    SECS2Item HEADER_;
    HEADER_.setASCII("L4");
    its[0] = SECS2Item(HEADER_);
    its[1] = SECS2Item(CEID_SECS2Item);
    its[2] = SECS2Item(EQUIP_SECS2Item);
    its[3] = SECS2Item(UNITID_SECS2Item);
    its[4] = SECS2Item(PRODUCTID_SECS2Item);
    its[5] = SECS2Item(RECIPEID_SECS2Item);
    SECS2Item it("ALL");
    it.setItems(its, 6);
    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 3, sb, it);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
#endif
}


void B3HsmsEQP::sendS6F3(SECS2Item &item)
{
    //QMessageBox::critical(NULL,"imu45","sendS6F3(SECS2Item &item)=====");
    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 3, sb, item);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsEQP::sendS6F11_370(
        QString DATAID,
        QString CEID,
        QString EQUIPMENTID,
        QString DIEID,
        QString RECIPEID,
        QString TRAYID)
{
    //====================================================================================================
    //<L[3]               listALL[3]
    //1.<U4 DATAID>
    //2.<U4 CEID>
    //3.<L[1]      t03[1]
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
    listALL[0].setUInt32(DATAID.toUInt());
    listALL[1].setUInt32(370);

    SECS2Item t03[1];

    SECS2Item t03_2[2];
    t03_2[0].setASCII("370");

    SECS2Item t03_3[4];
    t03_3[0].setASCII(EQUIPMENTID);
    t03_3[1].setASCII(DIEID);
    t03_3[2].setASCII(RECIPEID);
    t03_3[3].setASCII(TRAYID);

    t03_2[1] = SECS2Item::SECS2ItemList2SECS2Item(t03_3,4);
    t03[0] = SECS2Item::SECS2ItemList2SECS2Item(t03_2,2);

    listALL[2] = SECS2Item::SECS2ItemList2SECS2Item(t03,1);

    SECS2Item finalRes = SECS2Item::SECS2ItemList2SECS2Item(listALL,3);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 11, sb, finalRes);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsEQP::sendS6F11_371_372(QString DATAID, QString CEID, QString EQUIPMENTID, QString UNITID, QString TRAYID, QString PTID, QString RECIPEID, QString DIEID, QString TIMESTAMP)
{

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
    t01[0].setUInt32(DATAID.toUInt());
    t01[1].setUInt32(CEID.toUInt());

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

    SECS2Item t02[1];
    t02[0] = SECS2Item::SECS2ItemList2SECS2Item(t03,2);

    t01[2] = SECS2Item::SECS2ItemList2SECS2Item(t02,1);

    SECS2Item finalRes = SECS2Item::SECS2ItemList2SECS2Item(t01,3);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 11, sb, finalRes);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsEQP::sendS6F11_482(
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
        QString TrayID)
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

    SECS2Item t01[3];
    t01[0].setUInt32(DATAID.toUInt());
    t01[1].setUInt32(482);

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

    SECS2Item t02[1];
    t02[0] = SECS2Item::SECS2ItemList2SECS2Item(t03,2);

    t01[2] = SECS2Item::SECS2ItemList2SECS2Item(t02,1);

    SECS2Item finalRes = SECS2Item::SECS2ItemList2SECS2Item(t01,3);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 11, sb, finalRes);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsEQP::sendS6F11_104(QString DATAID,QString CEID,QString CRST,QString EQST)
{
    //<L[3]                 t01[3];
    //1.<U4 DATAID>
    //2.<U4 CEID>
    //3.<L[1]               t02;
        //1.<L[2]           t03[2];
            //1.<A 100>
            //2.<L[2]       t04[2];
                //1.<A CRST>
                //2.<A EQST>
    SECS2Item t01[3];
    t01[0].setUInt32(DATAID.toUInt());
    t01[1].setUInt32(CEID.toUInt());

    SECS2Item t02[1],t03[2];
    t03[0].setASCII("100");

    SECS2Item t04[2];
    t04[0].setASCII(CRST);
    t04[1].setASCII(EQST);

    t03[1] = SECS2Item::SECS2ItemList2SECS2Item(t04,2);

    t02[0] = SECS2Item::SECS2ItemList2SECS2Item(t03,2);

    t01[2] = SECS2Item::SECS2ItemList2SECS2Item(t02,1);

    SECS2Item finalRes = SECS2Item::SECS2ItemList2SECS2Item(t01,3);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 11, sb, finalRes);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);

    //============================
    //当改变了设备的控制状态后,要更新状态变量
    //CRST:  O:ON-LINE|F:OFF-LINE|L:ONLINE-LOCAL
    if(CRST=="O" | CRST=="L"){this->m_eqp_connectSatus=online;}
    else if(CRST=="F"){this->m_eqp_connectSatus=offline;}
}

SECS2Item buildSITESET(QPair<QString, QString> item)
{
    SECS2Item it("SITESET");
    SECS2Item its[2];
    its[0].setASCII(item.first);
    its[1].setASCII(item.second);
    it.setItems(its, 2);
    //qDebug() << it.stringLog("");
    return it;
}

SECS2Item buildSITESETLIST(QVector< QPair<QString, QString> > data)
{
    int N = data.size();
    SECS2Item *SITESET = new SECS2Item[N];
    for(int i = 0; i < N; i ++)
    {
        SECS2Item its[2];
        QPair<QString, QString> item = data.at(i);
        its[0].setASCII(item.first);
        its[1].setASCII(item.second);
        SITESET[i].setItems(its, 2);
    }
    SECS2Item SITESETLIST("SITESETLIST");
    SITESETLIST.setItems(SITESET, N);
    delete [] SITESET;
    return SITESETLIST;
}

SECS2Item buildSITESETLIST(QMultiHash<QString, QString> siteset)
{
    int N = siteset.size(), i = 0;
    SECS2Item *SITESET = new SECS2Item[N];
    QHashIterator<QString, QString> iter(siteset);
    while (iter.hasNext())
    {
        SECS2Item its[2];
        iter.next();
        its[0].setASCII(iter.key());
        its[1].setASCII(iter.value());
        SITESET[i].setItems(its, 2);
    }
    SECS2Item SITESETLIST("SITESETLIST");
    SITESETLIST.setItems(SITESET, N);
    return SITESETLIST;
}

SECS2Item buildDVSET(QString DVNAME, SECS2Item SITESETLIST)
{
    SECS2Item DVSET_Items[2];
    DVSET_Items[0].setASCII(DVNAME); // 到这里是正确的
    DVSET_Items[1] = SITESETLIST;
    SECS2Item DVSET("DVSET"); // LIST
    DVSET.setItems(DVSET_Items, 2);
    return DVSET;
}

SECS2Item buildDVSET(QString DVNAME, SECS2Item SITESET[], int N)
{
    SECS2Item DVSET_Items[2];
    DVSET_Items[0].setASCII(DVNAME); // 到这里是正确的
    DVSET_Items[1].setItems(SITESET, N); // 到这里是正确的
    SECS2Item DVSET("DVSET"); // LIST
    DVSET.setItems(DVSET_Items, 2);
    return DVSET;
}

SECS2Item buildDATASET(QString EQPID, QString UNITID, QString PNLID, SECS2Item DVSET)
{
    SECS2Item DATASET_Items[4];
    DATASET_Items[0].setASCII(EQPID);
    DATASET_Items[1].setASCII(UNITID);
    DATASET_Items[2].setASCII(PNLID);
    DATASET_Items[3].setItems(&DVSET, 1); //DVSETLIST

    SECS2Item DATASET("DATASET");
    DATASET.setItems(DATASET_Items, 4);
    return DATASET;
}

SECS2Item B3HsmsEQP::buildS6F3Item(QString PNLID, QString DVNAME,
                    QVector< QPair<QString, QString> > data)
{
    SECS2Item SITESETLIST = buildSITESETLIST(data);
    SECS2Item DVSET = buildDVSET(DVNAME, SITESETLIST);
    SECS2Item DATASET = buildDATASET(m_EQPID, m_UNITID, PNLID, DVSET);

    SECS2Item DVDATASET_Items[2];
    DVDATASET_Items[0].setASCII("501"); // CEID
    DVDATASET_Items[1] = DATASET; //LIST

    SECS2Item DVDATASET("DVDATASET");
    DVDATASET.setItems(DVDATASET_Items, 2);

    return DVDATASET;
}

void B3HsmsEQP::onReceiveS6F210(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QString str = it.toASCII();

    qDebug() << "OperatorAuthorityRequestReply = " << str;
}

void B3HsmsEQP::onReceiveS6F208(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QString str = it.toASCII();

    qDebug() << "PanelInfoRequestReply = " << str;
}

void B3HsmsEQP::onReceiveS2F209(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QVector<SECS2Item> AUTHORITYSET = it.toItems();
    QString EQPID = AUTHORITYSET[0].toASCII();
    QString UNITID = AUTHORITYSET[1].toASCII();
    QString OPERATORID = AUTHORITYSET[2].toASCII();
    QString AUTHORITYCODE = AUTHORITYSET[3].toASCII();

    HSMSMessages m = (HSMSMessages::replyDataMessage)(message, "0"); //OperatorAuthorityDownloadReply
    sendMessage(m);

    if(AUTHORITYCODE == "0")
    {
        emit loginStatus(true);
        return;
    }
    qDebug() << "ID or Password is wrong!";
    emit loginStatus(false);
    return;
}

void B3HsmsEQP::onReceiveS6F4(const HSMSMessages &message)
{
    Q_UNUSED(message);
    //TODO: 这里暂时什么都不做。后续会增加超时重发机制。这里就需要增加功能了。
}

void B3HsmsEQP::onReceiveS10F5(const HSMSMessages &message)
{
    qDebug() << "S10F5: Do nothing, only reply.";
    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, "0"); //TerminalDisplayMultiBlockAcknowledge
    sendMessage(rsp);
}

void B3HsmsEQP::onReceiveS1F3(const HSMSMessages &message, int type)
{
    QString s = QString::number(type);

    SECS2Item t01[1];
    t01[0].setASCII(s);

    SECS2Item t02 = SECS2Item::SECS2ItemList2SECS2Item(t01,1);

    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, t02);//S1F4
    qDebug()<<"onReceiveS1F3,systemBytes = " <<rsp.systemBytes();
    sendMessage(rsp);
}

void B3HsmsEQP::onReceiveS2F41(const HSMSMessages &message, u1 type)
{
    SECS2Item t01[1];
    t01[0].setUInt8(type);
    SECS2Item t02 = SECS2Item::SECS2ItemList2SECS2Item(t01,1);

    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, t02);//S2F42
    //qDebug()<<"onReceiveS1F3,systemBytes = " <<rsp.systemBytes();
    sendMessage(rsp);
}

void B3HsmsEQP::onReceiveS2F103(const HSMSMessages &message, int type)
{
    QString tmp = QString::number(type,10);
    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, tmp);//S2F103进站成功,注意要追加指令s6f11_371
    //qDebug()<<"onReceiveS1F3,systemBytes = " <<rsp.systemBytes();
    sendMessage(rsp);
}

void B3HsmsEQP::onReceiveS7F19(const HSMSMessages &message,QString PPID)
{
    SECS2Item t01[1];
    t01[0].setASCII(PPID);
    SECS2Item t02 = SECS2Item::SECS2ItemList2SECS2Item(t01,1);

    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, t02);//S7F20,回复状态查询
    //qDebug()<<"onReceiveS1F3,systemBytes = " <<rsp.systemBytes();
    sendMessage(rsp);
}

void B3HsmsEQP::onReceiveS10F3(const HSMSMessages &message, u1 ACKC10)
{
    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, ACKC10);
    sendMessage(rsp);
}

void B3HsmsEQP::privateDataMessage(const HSMSMessages &message)
{
    uint8_t stream = message.stream();
    uint8_t function = message.function();

    qDebug()<< "i B3HsmsEQP recieve S="<<stream <<"F="<<function;
    if(stream == 1 && function == 3) //1:offline; 2:online
    {
        onReceiveS1F3(message,m_eqp_connectSatus);
        return;
    }
    if(stream == 2 && function == 41) //进站失败
    {
        onReceiveS2F41(message);
        return;
    }
    if(stream == 2 && function == 103) //进站成功
    {
        onReceiveS2F103(message);
        return;
    }
    if(stream == 2 && function == 207) //PANELINFOSET
    {
        onReceiveS2F207(message);
        return;
    }
    if(stream == 6 && function == 12) //EventReportAcknowledge
    {
        onReceiveS6F12(message);
        return;
    }
    if(stream == 2 && function == 18) //Date and time data
    {
        onReceiveS2F18(message);
        return;
    }
    if(stream == 1 && function == 5) //Formatted status request
    {
        onReceiveS1F5(message);
        return;
    }
    if(stream == 6 && function == 210) //OperatorAuthorityRequestReply
    {
        onReceiveS6F210(message);
        return;
    }
    if(stream == 6 && function == 4) //DiscreteVariableDataAcknowledge
    {
        onReceiveS6F4(message);
        return;
    }
    if(stream == 2 && function == 209) //
    {
        onReceiveS2F209(message);
        return;
    }
    if(stream == 6 && function == 208) //PanelInfoRequestReply
    {
        onReceiveS6F208(message);
        return;
    }
    if(stream == 7 && function == 19)
    {
        onReceiveS7F19(message);
        return;
    }
    if(stream == 10 && function == 3) //for display
    {
        onReceiveS10F3(message,1);
        return;
    }
    if(stream == 10 && function == 5) //Terminal display, multi-block
    {
        onReceiveS10F5(message);
        return;
    }
//onReceiveS10F3
}

void B3HsmsEQP::sendS6F207(QString PNLID)
{
    SECS2Item its[4];
    its[0].setASCII(m_EQPID);
    its[1].setASCII(m_UNITID);
    its[2].setASCII(PNLID);
    its[3].setASCII(m_MODULEID);
    SECS2Item PANELINFOSET;
    PANELINFOSET.setItems(its, 4);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 207, sb, PANELINFOSET);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsEQP::sendS6F209(QString OPERATORID, QString PASSWORD)
{
    SECS2Item its[4];
    its[0].setASCII(m_EQPID);
    its[1].setASCII(m_UNITID);
    its[2].setASCII(OPERATORID);
    its[3].setASCII(PASSWORD);

    SECS2Item AUTHORITYINFOSET;
    AUTHORITYINFOSET.setItems(its, 4);

    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 209, sb, AUTHORITYINFOSET);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsEQP::sendS6F11()
{
    SECS2Item CRST[1];
    CRST[0].setASCII("1"); //CRST
    SECS2Item CREQSET[2];
    CREQSET[0].setASCII("111");  //CREQRPTID
    CREQSET[1].setItems(CRST, 1);//CREQSET
    SECS2Item CREQRPTSET;
    CREQRPTSET.setItems(CREQSET, 2); //CREQRPTSET
    SECS2Item RPTIDLIST[3];
    RPTIDLIST[0].setASCII("1");  //DATAID
    RPTIDLIST[1].setASCII("112"); //CEID
    RPTIDLIST[2].setItems(&CREQRPTSET, 1); //RPTIDLIST
    SECS2Item EVENTREPORTSET;
    EVENTREPORTSET.setItems(RPTIDLIST, 3); //EVENTREPORTSET
    uint32_t sb = HSMSMessages::uniqueSystemBytes();
    HSMSMessages x = HSMSMessages::dataMessage(m_sessionID, 6, 11, sb, EVENTREPORTSET);
    x.setWBit(HSMSMessages::NeedReply);
    sendMessage(x);
}

void B3HsmsEQP::onReceiveS2F18(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QString str = it.toASCII();
    QDateTime t = QDateTime::fromString(str, "yyyyMMddhhmmss");

    emit dateTimeReplyReceived(t);
    qDebug() << "DateTime from Host is " << t;
}

void B3HsmsEQP::onReceiveS1F5(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QString SFCD = it.toASCII();

    SECS2Item its[3];
    its[0].setASCII(m_EQPID);
    its[1].setASCII(m_CRST);
    its[2].setASCII(m_EQST);

    SECS2Item CREQSET;
    CREQSET.setItems(its, 3);

    SECS2Item its2[2];
    its2[0].setASCII(SFCD);
    its2[1].setItems(&CREQSET, 1);

    SECS2Item SFCDSET;
    SFCDSET.setItems(its2, 2);

    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, SFCDSET);
    sendMessage(rsp);
    qDebug()<<"B3HsmsEQP send S1F6";
}

void B3HsmsEQP::onReceiveS6F12(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QString str = it.toASCII();
    qDebug() << "Receive S6F12: ACKC6 = " << str;

    if(str == "0")
    {
        emit onlineLocal(true);
        return;
    }
    emit onlineLocal(false);
    return;
}

void B3HsmsEQP::onReceiveS2F207(const HSMSMessages &message)
{
    SECS2Item it = message.getItem();
    QVector<SECS2Item> its = it.toItems();
    QString RTCODE = its[0].toASCII();
    QString EQPID = its[1].toASCII();
    QString UNITID = its[2].toASCII();
    QString PNLID = its[3].toASCII();
    QString MODULEID = its[4].toASCII();
    QString FGCODE = its[5].toASCII();
    QString WORKORDER = its[6].toASCII();
    QString PNLJUDGE = its[7].toASCII();
    QString PNLGRADE = its[8].toASCII();
    QString REASONCODE = its[9].toASCII();
    QString CURRENTSTEP = its[10].toASCII();
    QString GROUPID = its[11].toASCII();
    QString INSPFILENAME = its[12].toASCII();
    QString INSPFILEPATH = its[13].toASCII();
    QString REVISION = its[14].toASCII();
    QString CELLGRADE = its[15].toASCII();
    QString WOGRADE = its[16].toASCII();

    m_PANELINFOSET.clear();
    m_PANELINFOSET.insert("PNLID", PNLID);
    m_PANELINFOSET.insert("FGCODE", FGCODE);
    m_PANELINFOSET.insert("UNITID", UNITID);
    m_PANELINFOSET.insert("MODULEID", MODULEID);
    m_PANELINFOSET.insert("WORKORDER", WORKORDER);
    m_PANELINFOSET.insert("PNLJUDGE", PNLJUDGE);
    m_PANELINFOSET.insert("PNLGRADE", PNLGRADE);
    m_PANELINFOSET.insert("REASONCODE", REASONCODE);
    m_PANELINFOSET.insert("CURRENTSTEP", CURRENTSTEP);
    m_PANELINFOSET.insert("GROUPID", GROUPID);
    m_PANELINFOSET.insert("INSPFILENAME", INSPFILENAME);
    m_PANELINFOSET.insert("INSPFILEPATH", INSPFILEPATH);
    m_PANELINFOSET.insert("REVISION", REVISION);
    m_PANELINFOSET.insert("CELLGRADE", CELLGRADE);
    m_PANELINFOSET.insert("WOGRADE", WOGRADE);

    HSMSMessages rsp = HSMSMessages::replyDataMessage(message, "0"); //PanelInfoDownloadReply
    sendMessage(rsp);

    if(RTCODE == "0")
    {
        emit panelInfoUpdated(true);
    }
    else {
        emit panelInfoUpdated(false);
    }
}

QString B3HsmsEQP::getPanelInfo(QString itemName)
{
    return m_PANELINFOSET.value(itemName, "");
}

