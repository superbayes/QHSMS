#include "glasssecsitem.h"

#include <QRegularExpression>

glassSECSItem::glassSECSItem(QObject *parent) : QObject(parent)
{


}
//==============镜腿测试==================================
Alice_L10_glassLeg_SECSItem::Alice_L10_glassLeg_SECSItem()
{
    num_item = 20;
    EQUIPMENTID = "M3KC0100";
    m_TestItems.push_back(this->testItem01);
    m_TestItems.push_back(this->testItem02);
    m_TestItems.push_back(this->testItem03);
    m_TestItems.push_back(this->testItem04);
    m_TestItems.push_back(this->testItem05);
    m_TestItems.push_back(this->testItem06);
    m_TestItems.push_back(this->testItem07);
    m_TestItems.push_back(this->testItem08);
    m_TestItems.push_back(this->testItem09);
    m_TestItems.push_back(this->testItem10);
    m_TestItems.push_back(this->testItem11);
    m_TestItems.push_back(this->testItem12);
    m_TestItems.push_back(this->testItem13);
    m_TestItems.push_back(this->testItem14);
    m_TestItems.push_back(this->testItem15);
    m_TestItems.push_back(this->testItem16);
    m_TestItems.push_back(this->testItem17);
    m_TestItems.push_back(this->testItem18);
    m_TestItems.push_back(this->testItem19);
    m_TestItems.push_back(this->testItem20);
}

Alice_L10_glassLeg_SECSItem::~Alice_L10_glassLeg_SECSItem()
{

}

bool Alice_L10_glassLeg_SECSItem::judgeResult()
{
    //左右镜腿
    //QRegularExpressionMatch
//    每一个测试项都可能有三种结果: (0:Fail|1:Pass)
    bool  ret;
    int counter4res=0;
    for(int i=0;i<num_item;++i)
    {
        if(i==0)
        {
            if(m_TestItems[i]->myTestItemResult.contains("Firmware version"))
            {
                m_testResult.push_back(1);
                ++counter4res;continue;
            }
            else{m_testResult.push_back(0);continue;}

        }
        else if (i==1)
        {
            if(m_TestItems[i]->myTestItemResult.contains("Phase ID:")){
                m_testResult.push_back(1);++counter4res;continue;
            }
            else {
                m_testResult.push_back(0);continue;
            }
        }
        else if (i==2)
        {
            if(m_TestItems[i]->myTestItemResult.contains("LT7911D firmware version")){
                m_testResult.push_back(1);++counter4res;continue;
            }
            else {
                m_testResult.push_back(0);continue;
            }
        }
        else if (i==3)
        {//mcu
            if(m_TestItems[i]->myTestItemResult.length()>20){
                m_testResult.push_back(1);++counter4res;continue;
            }
            else {
                m_testResult.push_back(0);continue;
            }
        }
        else if (i==5)
        {//E-Compass test OK
            if(m_TestItems[i]->myTestItemResult.contains("OK")){
                m_testResult.push_back(1);++counter4res;continue;
            }
            else {
                m_testResult.push_back(0);continue;
            }
        }
        else if (i==6||i==8||i==9)
        {
            if(m_TestItems[i]->myTestItemResult.contains("pass")){
                m_testResult.push_back(1);++counter4res;continue;
            }
            else {
                m_testResult.push_back(0);continue;
            }
        }
        else if (i>9) {
            if(m_TestItems[i]->myTestItemResult.toLower().contains("pass")){
                m_testResult.push_back(1);++counter4res;
            }
            else {
                m_testResult.push_back(0);
            }
        }
    }
    //分析结果
    if(counter4res==num_item-2){
        return true;
    }else {
        return false;
    }

}

//==========================Alice_L10整机=================================
Alice_L10_zhengji_SECSItem::Alice_L10_zhengji_SECSItem()
{
    num_item = 12;//测试项的个数
    EQUIPMENTID = "M3KG0100";//设备ID
    m_TestItems.push_back(this->testItem01);
    m_TestItems.push_back(this->testItem02);
    m_TestItems.push_back(this->testItem03);
    m_TestItems.push_back(this->testItem04);
    m_TestItems.push_back(this->testItem05);
    m_TestItems.push_back(this->testItem06);
    m_TestItems.push_back(this->testItem07);
    m_TestItems.push_back(this->testItem08);
    m_TestItems.push_back(this->testItem09);
    m_TestItems.push_back(this->testItem10);
    m_TestItems.push_back(this->testItem11);
    m_TestItems.push_back(this->testItem12);

}

Alice_L10_zhengji_SECSItem::~Alice_L10_zhengji_SECSItem()
{

}

bool Alice_L10_zhengji_SECSItem::judgeResult()
{
    int counter4res = 0;
    for(int i=0;i<num_item;++i){
        if(m_TestItems[i]->myTestItemResult.toLower().contains("pass")){
            m_testResult.push_back(1);++counter4res;
        }
        else {
            m_testResult.push_back(0);
        }
    }
    //分析结果
    if(counter4res==num_item){
        return true;
    }else {
        return false;
    }
}

//==========================Alice_L10镜身=================================
Alice_L10_glassBody_SECSItem::Alice_L10_glassBody_SECSItem()
{
    num_item = 25;//测试项的个数
    EQUIPMENTID = "M3KF0100";//设备ID
    m_TestItems.push_back(this->testItem01);
    m_TestItems.push_back(this->testItem02);
    m_TestItems.push_back(this->testItem03);
    m_TestItems.push_back(this->testItem04);
    m_TestItems.push_back(this->testItem05);
    m_TestItems.push_back(this->testItem06);
    m_TestItems.push_back(this->testItem07);
    m_TestItems.push_back(this->testItem08);
    m_TestItems.push_back(this->testItem09);
    m_TestItems.push_back(this->testItem10);
    m_TestItems.push_back(this->testItem11);
    m_TestItems.push_back(this->testItem12);
    m_TestItems.push_back(this->testItem13);
    m_TestItems.push_back(this->testItem14);
    m_TestItems.push_back(this->testItem15);
    m_TestItems.push_back(this->testItem16);
    m_TestItems.push_back(this->testItem17);
    m_TestItems.push_back(this->testItem18);
    m_TestItems.push_back(this->testItem19);
    m_TestItems.push_back(this->testItem20);
    m_TestItems.push_back(this->testItem21);
    m_TestItems.push_back(this->testItem22);
    m_TestItems.push_back(this->testItem23);
    m_TestItems.push_back(this->testItem24);
    m_TestItems.push_back(this->testItem25);
}

Alice_L10_glassBody_SECSItem::~Alice_L10_glassBody_SECSItem()
{

}

bool Alice_L10_glassBody_SECSItem::judgeResult()
{
    int counter4res=0;
    for(int i=0;i<num_item;++i){

        if(i==1){
            if(m_TestItems[i]->myTestItemResult.contains("Firmware version"))
            {
                m_testResult.push_back(1);
                ++counter4res;continue;
            }
            else{m_testResult.push_back(0);continue;}
        }
        if(i==2){
            if(m_TestItems[i]->myTestItemResult.contains("Phase ID"))
            {
                m_testResult.push_back(1);
                ++counter4res;continue;
            }
            else{m_testResult.push_back(0);continue;}
        }
        if(i==3){
            if(m_TestItems[i]->myTestItemResult.contains("LT7911D firmware version"))
            {
                m_testResult.push_back(1);
                ++counter4res;continue;
            }
            else{m_testResult.push_back(0);continue;}
        }
        if(i==4){
            if(m_TestItems[i]->myTestItemResult.length()>20)
            {
                m_testResult.push_back(1);
                ++counter4res;continue;
            }
            else{m_testResult.push_back(0);continue;}
        }
        if(i==6||i==7){
            if(m_TestItems[i]->myTestItemResult.contains("OK"))
            {
                m_testResult.push_back(1);
                ++counter4res;continue;
            }
            else{m_testResult.push_back(0);continue;}
        }
        if(i==8||i>9){
            if(m_TestItems[i]->myTestItemResult.toLower().contains("pass"))
            {
                m_testResult.push_back(1);
                ++counter4res;
            }
            else{m_testResult.push_back(0);}
        }
    }
    if(counter4res==num_item-3){return true;}
    else {return false;}
}
//==========================Alice_L10IMU=================================
Alice_L10_IMU_SECSItem::Alice_L10_IMU_SECSItem()
{
    num_item = 21;//测试项的个数
    EQUIPMENTID = "M3KH0100";//设备ID
    m_TestItems.push_back(this->testItem01);
    m_TestItems.push_back(this->testItem02);
    m_TestItems.push_back(this->testItem03);
    m_TestItems.push_back(this->testItem04);
    m_TestItems.push_back(this->testItem05);
    m_TestItems.push_back(this->testItem06);
    m_TestItems.push_back(this->testItem07);
    m_TestItems.push_back(this->testItem08);
    m_TestItems.push_back(this->testItem09);
    m_TestItems.push_back(this->testItem10);
    m_TestItems.push_back(this->testItem11);
    m_TestItems.push_back(this->testItem12);
    m_TestItems.push_back(this->testItem13);
    m_TestItems.push_back(this->testItem14);
    m_TestItems.push_back(this->testItem15);
    m_TestItems.push_back(this->testItem16);
    m_TestItems.push_back(this->testItem17);
    m_TestItems.push_back(this->testItem18);
    m_TestItems.push_back(this->testItem19);
    m_TestItems.push_back(this->testItem20);
    m_TestItems.push_back(this->testItem21);
}

Alice_L10_IMU_SECSItem::~Alice_L10_IMU_SECSItem()
{


}

bool Alice_L10_IMU_SECSItem::judgeResult()
{
    //    每一个测试项都可能有三种结果: (0:Fail|1:Pass)
        int counter4res=0;
        for(int i=2;i<num_item;++i)
        {
            if(i==2)
            {
                if(m_TestItems[i]->myTestItemResult.contains("Firmware version"))
                {
                    m_testResult.push_back(1);
                    ++counter4res;continue;
                }
                else{m_testResult.push_back(0);continue;}
            }
            else if (i==3)
            {
                if(m_TestItems[i]->myTestItemResult.contains("Phase ID:")){
                    m_testResult.push_back(1);++counter4res;continue;
                }
                else {
                    m_testResult.push_back(0);continue;
                }
            }
            else if (i==4)
            {
                if(m_TestItems[i]->myTestItemResult.contains("LT7911D firmware version")){
                    m_testResult.push_back(1);++counter4res;continue;
                }
                else {
                    m_testResult.push_back(0);continue;
                }
            }
            else if (i==5)
            {//mcu
                if(m_TestItems[i]->myTestItemResult.length()>20){
                    m_testResult.push_back(1);++counter4res;continue;
                }
                else {
                    m_testResult.push_back(0);continue;
                }
            }
            else if (i==7||i==8)
            {//音频矫正
                if(m_TestItems[i]->myTestItemResult.toLower().contains("pass")){
                    m_testResult.push_back(1);++counter4res;continue;
                }
                else {
                    m_testResult.push_back(0);continue;
                }
            }
            else if (i==9)
            {
                if(m_TestItems[i]->myTestItemResult.toLower().contains("ok")){
                    m_testResult.push_back(1);++counter4res;continue;
                }
                else {
                    m_testResult.push_back(0);continue;
                }
            }
            else if (i==10 || (i>11&&i<17)) {
                if(m_TestItems[i]->myTestItemResult.toLower().contains("pass")){
                    m_testResult.push_back(1);
                    ++counter4res;
                    continue;
                }
                else {
                    m_testResult.push_back(0);continue;
                }
            }
            else if (i>=17)
            {
                if(m_TestItems[i]->myTestItemResult.toLower().contains("ok") ||
                        m_TestItems[i]->myTestItemResult.toLower().contains("pass")
                        ){
                    m_testResult.push_back(1);++counter4res;continue;
                }
                else {
                    m_testResult.push_back(0);continue;
                }
            }
        }
        //分析结果
        if(counter4res==num_item-4){
            return true;
        }else {
            return false;
        }

}
