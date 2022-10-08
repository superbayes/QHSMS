#include "qiukuisecsitem.h"

#include <QDateTime>
#include <QDir>

qiukuiSECSItem::qiukuiSECSItem(QObject *parent) : QObject(parent)
{

}

qiukuiSECSItem::~qiukuiSECSItem()
{
    for(int i =0;i<num_item;++i)
    {
        if(m_TestItems[i]!=NULL){
            delete m_TestItems[i];
        }
    }
}

SECS2Item qiukuiSECSItem::getSECS2Item()
{
    this->update();
    return this->m_finalItem;
}

void qiukuiSECSItem::set_TestResult(singleTestItem *testItem, QString result)
{
    testItem->myTestItemResult = result;
}

void qiukuiSECSItem::setCEID(U4 CEID)
{
    this->CEID = CEID;
}

void qiukuiSECSItem::setEQUIPMENTID(QString eqpID)
{
    this->EQUIPMENTID = eqpID;
}

void qiukuiSECSItem::setPRODUCTID(QString productID)
{
     this->PRODUCTID = productID;
}

void qiukuiSECSItem::setRECIPEID(QString RECIPEID)
{
    this->RECIPEID = RECIPEID;
}

void qiukuiSECSItem::update()
{
    //一些外部参数
    //1.<A  CEID>
    //2.<A  EQUIPMENTID>
    //3.<A  UNITID>
    //4.<A  PRODUCTID>
    //5.<A  RECIPEID>

    SECS2Item tmp1_1[6],tmp2;
    tmp1_1[0] = SECS2Item("CEID",CEID);
    tmp1_1[1] = SECS2Item("EQUIPMENTID",EQUIPMENTID);
    tmp1_1[2] = SECS2Item("UNITID",UNITID);
    tmp1_1[3] = SECS2Item("PRODUCTID",PRODUCTID);
    tmp1_1[4] = SECS2Item("RECIPEID",RECIPEID);

    //镜身测试所有检测项
    SECS2Item  *tmp2_2 = new SECS2Item[num_item];
    for(int i =0;i<num_item;++i)
    {
        if(m_TestItems[i]->myTestItemResult.isEmpty()){
            tmp2_2[i] = qiukuiSECSItem::getSingleItem4Test(m_TestItems[i]->myTestItemName,"UNKWNOWN");
        }else {
            tmp2_2[i] = qiukuiSECSItem::getSingleItem4Test(m_TestItems[i]->myTestItemName,m_TestItems[i]->myTestItemResult);
        }
    }
    tmp2.setItems(tmp2_2,num_item);
    tmp1_1[5] = tmp2;
    //all
    this->m_finalItem.setItems(tmp1_1,6);
    delete[] tmp2_2;
}

void qiukuiSECSItem::saveLog(QString path,QString stationName)
{
    QString saveContent;
    //工位名=================================
//    saveContent += stationName;
//    saveContent += ",";
    //产品sn=======================================
    saveContent += PRODUCTID;
    saveContent += ",";
    //测试结果pass fail=======================================
    if(this->judgeResult()){
        saveContent += "Pass,";
    }
    else {
        saveContent += "Fail,";
    }
    //保存时间================================
    QString current_date =QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//current_date字符串结果为"2016.05.20 12:17:01"
    saveContent += current_date;
    saveContent += ",";
    //所有项的测试结果=======================================
    for(int i =0;i<num_item;++i)
    {
        saveContent+= m_TestItems[i]->myTestItemResult;
        if(i!=num_item-1){saveContent+=",";}
    }
    saveContent+="\n";


    //保存文件,如有存在文件夹则保存,没有就创建
    //获取复合文件夹,检查是否存在 "./log/202209/"
    if(!path.endsWith("/")){path+="/";}
    QString folderPath = path + QDateTime::currentDateTime().toString("yyyyMM");
    QDir dir(folderPath);
    if(!dir.exists()){
        //创建文件夹
        QDir base_folderPath(path);
        base_folderPath.mkdir(QDateTime::currentDateTime().toString("yyyyMM"));
    }


    //----------------------------
    if(stationName.toLower().contains("alice_l10")){
        QString fileName =folderPath+"/"+stationName+".csv";//"./log/202209/alice_l10_zhengji.csv"
        QFile file(fileName);
        QFileInfo fileInfo(fileName);

        //如果文件不存在,则需要创建文件,并且第一行是字段名
        QString FiledName;//字段名
        if(!fileInfo.exists()){
            FiledName+="SN,";//sn
            FiledName+="test Result,";//pass,fail
            FiledName+="test time,";
            for(int i=0;i<num_item;i++){
                FiledName+=m_TestItems[i]->myTestItemName;
                if(i!=num_item-1){FiledName+=",";}
            }
            FiledName+="\n";
        }

        bool bRet;
        bRet = file.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append);
        if(bRet)
        {
            if(!FiledName.isEmpty()){file.write(FiledName.toLocal8Bit());}
            //如果文件存在,则只需添加内容即可
            file.write(saveContent.toLocal8Bit());
            qDebug()<<"数据保存成功=======" << current_date;
        }
        file.close();
    }
}

singleTestItem *qiukuiSECSItem::get_singleTestItem_byVar(int itemOrderNum)
{
    singleTestItem* tmp=NULL;
    if(m_TestItems[itemOrderNum-1]){
        tmp = m_TestItems[itemOrderNum];
    }
    return tmp;
}

SECS2Item qiukuiSECSItem::getSingleItem4Test(QString testItemName, QString TestResult)
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
    dfv01_02[0].setASCII("01");
    dfv01_02[1].setASCII(TestResult);

    SECS2Item dfv04[1];
    dfv04[0].setItems(dfv01_02,2);


    SECS2Item dfv03;
    dfv03.setASCII(testItemName);

    SECS2Item dfv03_04[2];
    dfv03_04[0] = dfv03;    
    dfv03_04[1] = SECS2Item::SECS2ItemList2SECS2Item(dfv04,1);

    SECS2Item project_item6_001;
    project_item6_001.setItems(dfv03_04,2);
    return project_item6_001;
}
