#ifndef QIUKUISECSITEM_H
#define QIUKUISECSITEM_H
#pragma execution_character_set("utf-8")
#include "HsmsHost.h"
#include "SECS2Item.h"
#include <QObject>
#ifndef singleTestItem
struct singleTestItem{
    QString myTestItemName;
    QString myTestItemResult = "UNKNOWN";
    int testID;
    singleTestItem(){}
    singleTestItem(QString TestItemName){
        this->myTestItemName = TestItemName;
    }
    singleTestItem(QString TestItemName,int testID){
        this->myTestItemName = TestItemName;
        this->testID = testID;
    }
    singleTestItem(QString TestItemName,QString TestItemResult){
        this->myTestItemName = TestItemName;
        this->myTestItemResult = TestItemResult;
    }
    singleTestItem(QString TestItemName,int testID,QString TestItemResult){
        this->myTestItemName = TestItemName;
        this->myTestItemResult = TestItemResult;
        this->testID = testID;
    }
};
#endif
class qiukuiSECSItem : public QObject
{
    Q_OBJECT
public:
    explicit qiukuiSECSItem(QObject *parent = nullptr);
    virtual ~qiukuiSECSItem();

    int num_item;//测试项的个数
    U4 CEID = 500;
    QString EQUIPMENTID = "NULL";//设备ID
    QString UNITID = "NULL";
    QString PRODUCTID = "NULL";//产品SN号
    QString RECIPEID = "NULL";

public:
    SECS2Item m_finalItem;//最终用于发送的消息体
    QVector<singleTestItem *> m_TestItems;//用于存放消息体

    /**
      * @brief 用于存放每一项测试的评判结果()
      * @brief 每一个测试项都可能有三种结果: (0:Fail|1:Pass|2:unknown)
      * @brief 对应的函数 [bool judgeResult()]
      **/
    QVector<uchar>m_testResult;

public:
    SECS2Item getSECS2Item();//获取最终的消息体
    virtual void set_TestResult(singleTestItem *testItem,QString result);//设置测试结果
    virtual void setCEID(U4 CEID);
    virtual void setEQUIPMENTID(QString eqpID);//设置设备Id
    virtual void setPRODUCTID(QString productID);//设置产品SN号
    virtual void setRECIPEID(QString RECIPEID);
    /**
      * @brief 判断产品是否合格,(0:Fail|1:Pass|2:unknown)
      * @param
      * @return bool,如果所有测试项Pass,则返回true;否则返回false
      **/
    virtual bool judgeResult()=0;

    /**
      * @brief 发送消息前更新消息结构体
      * @param
      * @return null
      *
      **/
    virtual void update();

    /**
      * @brief 保存日志,格式csv
      * @param fileName,文件路径(不包含文件名)
      * @param stationName,工站名称
      * @return null
      *
      **/
    virtual void saveLog(QString path,QString stationName);

    virtual singleTestItem* get_singleTestItem_byVar(QString itemName){return NULL;};
    virtual singleTestItem* get_singleTestItem_byVar(int itemOrderNum/*第N项,从1开始*/);
public:
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
signals:

};

#endif // QIUKUISECSITEM_H
