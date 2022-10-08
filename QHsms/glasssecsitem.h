#ifndef GLASSSECSITEM_H
#define GLASSSECSITEM_H

#include <QObject>
#include "qiukuisecsitem.h"

class glassSECSItem : public QObject
{
    Q_OBJECT
public:
    explicit glassSECSItem(QObject *parent = nullptr);

signals:

};

class Alice_L10_glassLeg_SECSItem:public qiukuiSECSItem{
public:
    Alice_L10_glassLeg_SECSItem();
    ~Alice_L10_glassLeg_SECSItem();
    bool judgeResult() override;

public:
//     singleTestItem *testItem01 = new singleTestItem("Device firmware version",1,"UNKNOWN");
//     singleTestItem *testItem02 = new singleTestItem("Device Phase ID",2,"UNKNOWN");
//     singleTestItem *testItem03 = new singleTestItem("LT7911D bridge firmware version",3,"UNKNOWN");
//     singleTestItem *testItem04 = new singleTestItem("Read MCU UID",4,"UNKNOWN");
//     singleTestItem *testItem05 = new singleTestItem("Proximity test",5,"NO_TEST");
//     singleTestItem *testItem06 = new singleTestItem("E-Compass test",6,"UNKNOWN");
//     singleTestItem *testItem07 = new singleTestItem("Component I2C / SPI test",7,"UNKNOWN");
//     singleTestItem *testItem08 = new singleTestItem("Component I2C / SPI test2",8,"NO_TEST");
//     singleTestItem *testItem09 = new singleTestItem("Component I2C / SPI test3",9,"UNKNOWN");
//     singleTestItem *testItem10 = new singleTestItem("Component I2C / SPI test4",10,"UNKNOWN");
//     singleTestItem *testItem11 = new singleTestItem("HID Cmd test",11,"UNKNOWN");//USB HID资料传输测试
//     singleTestItem *testItem12 = new singleTestItem("IMU Data test",12,"UNKNOWN");//3自由度资料测试
//     singleTestItem *testItem13 = new singleTestItem("HID AGM data test",13,"UNKNOWN");//USB HID加速度计、陀螺仪、地磁测试
//     singleTestItem *testItem14 = new singleTestItem("Keypad test(right up)",14,"UNKNOWN");//"按钮测试(右腿 前按钮 短按)"
//     singleTestItem *testItem15 = new singleTestItem("Keypad test(right up long pressed)",15,"UNKNOWN");//按钮测试(右腿 前按钮 长按)
//     singleTestItem *testItem16 = new singleTestItem("Keypad test(right down)",16,"UNKNOWN");//按钮测试(右腿 后按钮 短按)
//     singleTestItem *testItem17 = new singleTestItem("Keypad test(right down long pressed)",17,"UNKNOWN");//按钮测试(右腿 后按钮 长按)
//     singleTestItem *testItem18 = new singleTestItem("Audio test(left)",18,"UNKNOWN");//喇叭测试(左)
//     singleTestItem *testItem19 = new singleTestItem("Audio test(right)",19,"UNKNOWN");//喇叭测试(右)
//     singleTestItem *testItem20 = new singleTestItem("Audio test(all)",20,"UNKNOWN");//喇叭测试(立体声)
     singleTestItem *testItem01 = new singleTestItem("firmware version",1,"UNKNOWN");
     singleTestItem *testItem02 = new singleTestItem("Phase ID",2,"UNKNOWN");
     singleTestItem *testItem03 = new singleTestItem("LT7911D firmware version",3,"UNKNOWN");
     singleTestItem *testItem04 = new singleTestItem("MCU UID",4,"UNKNOWN");
     singleTestItem *testItem05 = new singleTestItem("Proximity test",5,"NO_TEST");
     singleTestItem *testItem06 = new singleTestItem("E-Compass test",6,"UNKNOWN");
     singleTestItem *testItem07 = new singleTestItem("I2C_SPI test",7,"UNKNOWN");
     singleTestItem *testItem08 = new singleTestItem("I2C_SPI test2",8,"NO_TEST");
     singleTestItem *testItem09 = new singleTestItem("I2C_SPI test3",9,"UNKNOWN");
     singleTestItem *testItem10 = new singleTestItem("I2C_SPI test4",10,"UNKNOWN");
     singleTestItem *testItem11 = new singleTestItem("HID Cmd test",11,"UNKNOWN");//USB HID资料传输测试
     singleTestItem *testItem12 = new singleTestItem("IMU Data test",12,"UNKNOWN");//3自由度资料测试
     singleTestItem *testItem13 = new singleTestItem("HID AGM data test",13,"UNKNOWN");//USB HID加速度计、陀螺仪、地磁测试
     singleTestItem *testItem14 = new singleTestItem("right up",14,"UNKNOWN");//"按钮测试(右腿 前按钮 短按)"
     singleTestItem *testItem15 = new singleTestItem("right up long",15,"UNKNOWN");//按钮测试(右腿 前按钮 长按)
     singleTestItem *testItem16 = new singleTestItem("right down",16,"UNKNOWN");//按钮测试(右腿 后按钮 短按)
     singleTestItem *testItem17 = new singleTestItem("right down long)",17,"UNKNOWN");//按钮测试(右腿 后按钮 长按)
     singleTestItem *testItem18 = new singleTestItem("Audio testleft",18,"UNKNOWN");//喇叭测试(左)
     singleTestItem *testItem19 = new singleTestItem("Audio testright",19,"UNKNOWN");//喇叭测试(右)
     singleTestItem *testItem20 = new singleTestItem("Audio testall",20,"UNKNOWN");//喇叭测试(立体声)

};

class Alice_L10_zhengji_SECSItem:public qiukuiSECSItem{
public:
    Alice_L10_zhengji_SECSItem();
    ~Alice_L10_zhengji_SECSItem();
    bool judgeResult() override;
public:
//    singleTestItem *testItem01 = new singleTestItem("Keypad test(right up)",1);//"按钮测试(右腿 前按钮 短按)"
//    singleTestItem *testItem02 = new singleTestItem("Keypad test(right up long pressed)",2);//按钮测试(右腿 前按钮 长按)
//    singleTestItem *testItem03 = new singleTestItem("Keypad test(right down)",3);//按钮测试(右腿 后按钮 短按)
//    singleTestItem *testItem04 = new singleTestItem("Keypad test(right down long pressed)",4);//按钮测试(右腿 后按钮 长按)
//    singleTestItem *testItem05 = new singleTestItem("Audio test(left)",5);//喇叭测试(左)
//    singleTestItem *testItem06 = new singleTestItem("Audio test(right)",6);//喇叭测试(右)
//    singleTestItem *testItem07 = new singleTestItem("Audio test(all)",7);//喇叭测试(立体声)
//    singleTestItem *testItem08 = new singleTestItem("Backlight test",8);//背光测试
//    singleTestItem *testItem09 = new singleTestItem("Display test",9);//显示测试
//    singleTestItem *testItem10 = new singleTestItem("The 2d3d test",10);//2d3d切换测试
//    singleTestItem *testItem11 = new singleTestItem("The 2d power test",11);//2d功耗测试
//    singleTestItem *testItem12 = new singleTestItem("The 3d power test",12);//3d功耗测试

    singleTestItem *testItem01 = new singleTestItem("right up",1);//"按钮测试(右腿 前按钮 短按)"
    singleTestItem *testItem02 = new singleTestItem("right up long",2);//按钮测试(右腿 前按钮 长按)
    singleTestItem *testItem03 = new singleTestItem("right down",3);//按钮测试(右腿 后按钮 短按)
    singleTestItem *testItem04 = new singleTestItem("right down long",4);//按钮测试(右腿 后按钮 长按)
    singleTestItem *testItem05 = new singleTestItem("Audio testleft",5);//喇叭测试(左)
    singleTestItem *testItem06 = new singleTestItem("Audio testright",6);//喇叭测试(右)
    singleTestItem *testItem07 = new singleTestItem("Audio testall",7);//喇叭测试(立体声)
    singleTestItem *testItem08 = new singleTestItem("Backlight test",8);//背光测试
    singleTestItem *testItem09 = new singleTestItem("Display test",9);//显示测试
    singleTestItem *testItem10 = new singleTestItem("The 2d3d test",10);//2d3d切换测试
    singleTestItem *testItem11 = new singleTestItem("The 2d power test",11);//2d功耗测试
    singleTestItem *testItem12 = new singleTestItem("The 3d power test",12);//3d功耗测试
};

class Alice_L10_glassBody_SECSItem:public qiukuiSECSItem{
public:
    Alice_L10_glassBody_SECSItem();
    ~Alice_L10_glassBody_SECSItem();
    bool judgeResult() override;
public:
//    singleTestItem *testItem01 = new singleTestItem("Proximity test",1,"NO_TEST");//邻近感测器测试
//    singleTestItem *testItem02 = new singleTestItem("Device firmware version",2);//装置阶段版号
//    singleTestItem *testItem03 = new singleTestItem("Device Phase ID",3);//装置阶段版号
//    singleTestItem *testItem04 = new singleTestItem("LT7911D bridge firmware version",4);//LT7911D显示桥接晶片韧体版号
//    singleTestItem *testItem05 = new singleTestItem("Read MCU UID",5);//读取MCU序号
//    singleTestItem *testItem06 = new singleTestItem("Proximity test",6,"NO_TEST");//邻近感测器测试
//    singleTestItem *testItem07 = new singleTestItem("E-Compass test",7);//电子罗盘测试
//    singleTestItem *testItem08 = new singleTestItem("The 6-axis sensor calibration test",8);//六轴感知器校正测试
//    singleTestItem *testItem09 = new singleTestItem("Component I2C / SPI test",9);//电子罗盘I2C/SPI测试
//    singleTestItem *testItem10 = new singleTestItem("Component I2C / SPI test2",10,"NO_TEST");//邻近感测器I2C / SPI测试
//    singleTestItem *testItem11 = new singleTestItem("Component I2C / SPI test3",11);//六轴感知器I2C / SPI测试
//    singleTestItem *testItem12 = new singleTestItem("Component I2C / SPI test4",12);//六轴感知器中断信号测试
//    singleTestItem *testItem13 = new singleTestItem("HID Cmd test",13);//USB HID资料传输测试
//    singleTestItem *testItem14 = new singleTestItem("IMU Data test",14);//3自由度资料测试
//    singleTestItem *testItem15 = new singleTestItem("HID AGM data test",15);//USB HID加速度计、陀螺仪、地磁测试
//    singleTestItem *testItem16 = new singleTestItem("Keypad test(right up)",16);//"按钮测试(右腿 前按钮 短按)"
//    singleTestItem *testItem17 = new singleTestItem("Keypad test(right up long pressed)",17);//按钮测试(右腿 前按钮 长按)
//    singleTestItem *testItem18 = new singleTestItem("Keypad test(right down)",18);//按钮测试(右腿 后按钮 短按)
//    singleTestItem *testItem19 = new singleTestItem("Keypad test(right down long pressed)",19);//按钮测试(右腿 后按钮 长按)
//    singleTestItem *testItem20 = new singleTestItem("Audio test(left)",20);//喇叭测试(左)
//    singleTestItem *testItem21 = new singleTestItem("Audio test(right)",21);//喇叭测试(右)
//    singleTestItem *testItem22 = new singleTestItem("Audio test(all)",22);//喇叭测试(立体声)
//    singleTestItem *testItem23 = new singleTestItem("Backlight test",23);//背光测试
//    singleTestItem *testItem24 = new singleTestItem("Display test",24);//显示测试
//    singleTestItem *testItem25 = new singleTestItem("The 2d3d test",25);//2d3d切换测试

    singleTestItem *testItem01 = new singleTestItem("Proximity test",1,"NO_TEST");//邻近感测器测试
    singleTestItem *testItem02 = new singleTestItem("firmware version",2);//装置阶段版号
    singleTestItem *testItem03 = new singleTestItem("Device Phase ID",3);//装置阶段版号
    singleTestItem *testItem04 = new singleTestItem("LT7911Dfirmware version",4);//LT7911D显示桥接晶片韧体版号
    singleTestItem *testItem05 = new singleTestItem("MCU UID",5);//读取MCU序号
    singleTestItem *testItem06 = new singleTestItem("Proximity test2",6,"NO_TEST");//邻近感测器测试
    singleTestItem *testItem07 = new singleTestItem("E-Compass test",7);//电子罗盘测试
    singleTestItem *testItem08 = new singleTestItem("The 6-axis calibration test",8);//六轴感知器校正测试
    singleTestItem *testItem09 = new singleTestItem("I2C_SPI test",9);//电子罗盘I2C/SPI测试
    singleTestItem *testItem10 = new singleTestItem("I2C_SPI test2",10,"NO_TEST");//邻近感测器I2C / SPI测试
    singleTestItem *testItem11 = new singleTestItem("I2C_SPI test3",11);//六轴感知器I2C / SPI测试
    singleTestItem *testItem12 = new singleTestItem("I2C_SPI test4",12);//六轴感知器中断信号测试
    singleTestItem *testItem13 = new singleTestItem("HID Cmd test",13);//USB HID资料传输测试
    singleTestItem *testItem14 = new singleTestItem("IMU Data test",14);//3自由度资料测试
    singleTestItem *testItem15 = new singleTestItem("HID AGM data test",15);//USB HID加速度计、陀螺仪、地磁测试
    singleTestItem *testItem16 = new singleTestItem("right up",16);//"按钮测试(右腿 前按钮 短按)"
    singleTestItem *testItem17 = new singleTestItem("right up long",17);//按钮测试(右腿 前按钮 长按)
    singleTestItem *testItem18 = new singleTestItem("right down",18);//按钮测试(右腿 后按钮 短按)
    singleTestItem *testItem19 = new singleTestItem("right down long",19);//按钮测试(右腿 后按钮 长按)
    singleTestItem *testItem20 = new singleTestItem("Audio testleft",20);//喇叭测试(左)
    singleTestItem *testItem21 = new singleTestItem("Audio testright",21);//喇叭测试(右)
    singleTestItem *testItem22 = new singleTestItem("Audio testall",22);//喇叭测试(立体声)
    singleTestItem *testItem23 = new singleTestItem("Backlight test",23);//背光测试
    singleTestItem *testItem24 = new singleTestItem("Display test",24);//显示测试
    singleTestItem *testItem25 = new singleTestItem("The 2d3d test",25);//2d3d切换测试
};


class Alice_L10_IMU_SECSItem:public qiukuiSECSItem{
public:
    Alice_L10_IMU_SECSItem();
    ~Alice_L10_IMU_SECSItem();
    bool judgeResult() override;
public:
//    singleTestItem *testItem01 = new singleTestItem("Calibrate Proximity Offset",1,"NO_TEST");//校正邻近感测器偏移值
//    singleTestItem *testItem02 = new singleTestItem("Proximity test",2,"NO_TEST");//邻近感测器测试(>10公分)
//    singleTestItem *testItem03 = new singleTestItem("Device firmware version",3);//装置阶段版号
//    singleTestItem *testItem04 = new singleTestItem("Device Phase ID",4);//装置阶段版号
//    singleTestItem *testItem05 = new singleTestItem("LT7911D bridge firmware version",5);//LT7911D显示桥接晶片韧体版号
//    singleTestItem *testItem06 = new singleTestItem("Read MCU UID",6);//读取MCU序号
//    singleTestItem *testItem07 = new singleTestItem("Proximity test",7,"NO_TEST");//邻近感测器测试
//    singleTestItem *testItem08 = new singleTestItem("Audio calibration test",8,"NO_TEST");//音频校正(左)
//    singleTestItem *testItem09 = new singleTestItem("Audio calibration right test",9);//音频校正(右)
//    singleTestItem *testItem10 = new singleTestItem("E-Compass test",10);//电子罗盘测试
//    singleTestItem *testItem11 = new singleTestItem("Component I2C / SPI test",11);//电子罗盘I2C/SPI测试
//    singleTestItem *testItem12 = new singleTestItem("Component I2C / SPI test2",12,"NO_TEST");//邻近感测器I2C / SPI测试
//    singleTestItem *testItem13 = new singleTestItem("Component I2C / SPI test3",13);//六轴感知器I2C / SPI测试
//    singleTestItem *testItem14 = new singleTestItem("Component I2C / SPI test4",14);//六轴感知器中断信号测试
//    singleTestItem *testItem15 = new singleTestItem("HID Cmd test",15);//USB HID资料传输测试
//    singleTestItem *testItem16 = new singleTestItem("IMU Data test",16);//3自由度资料测试
//    singleTestItem *testItem17 = new singleTestItem("HID AGM data test",17);//USB HID加速度计、陀螺仪、地磁测试
//    singleTestItem *testItem18 = new singleTestItem("The 6-axis sensor calibration test",18);//六轴感知器校正测试
//    singleTestItem *testItem19 = new singleTestItem("Reads 6-axis sensor data test",19);//读取六轴感知器数据测试
//    singleTestItem *testItem20 = new singleTestItem("Factory Reset",20);//恢复出厂设置
//    singleTestItem *testItem21 = new singleTestItem("The 6-axis sensor calibration check test",21);//六轴感知器静态校正写入确认
    singleTestItem *testItem01 = new singleTestItem("CalibrateProximityOffset",1,"NO_TEST");//校正邻近感测器偏移值
    singleTestItem *testItem02 = new singleTestItem("Proximity test",2,"NO_TEST");//邻近感测器测试(>10公分)
    singleTestItem *testItem03 = new singleTestItem("firmware version",3);//装置阶段版号
    singleTestItem *testItem04 = new singleTestItem("Phase ID",4);//装置阶段版号
    singleTestItem *testItem05 = new singleTestItem("LT7911D firmware version",5);//LT7911D显示桥接晶片韧体版号
    singleTestItem *testItem06 = new singleTestItem("MCU UID",6);//读取MCU序号
    singleTestItem *testItem07 = new singleTestItem("Proximity test",7,"NO_TEST");//邻近感测器测试
    singleTestItem *testItem08 = new singleTestItem("Audio calibration test",8,"NO_TEST");//音频校正(左)
    singleTestItem *testItem09 = new singleTestItem("Audio calibration right test",9);//音频校正(右)
    singleTestItem *testItem10 = new singleTestItem("E-Compass test",10);//电子罗盘测试
    singleTestItem *testItem11 = new singleTestItem("I2C_SPI test",11);//电子罗盘I2C/SPI测试
    singleTestItem *testItem12 = new singleTestItem("I2C_SPI test2",12,"NO_TEST");//邻近感测器I2C / SPI测试
    singleTestItem *testItem13 = new singleTestItem("I2C_SPI test3",13);//六轴感知器I2C / SPI测试
    singleTestItem *testItem14 = new singleTestItem("I2C_SPI test4",14);//六轴感知器中断信号测试
    singleTestItem *testItem15 = new singleTestItem("HID Cmd test",15);//USB HID资料传输测试
    singleTestItem *testItem16 = new singleTestItem("IMU Data test",16);//3自由度资料测试
    singleTestItem *testItem17 = new singleTestItem("HID AGM data test",17);//USB HID加速度计、陀螺仪、地磁测试
    singleTestItem *testItem18 = new singleTestItem("The 6-axis calibration test",18);//六轴感知器校正测试
    singleTestItem *testItem19 = new singleTestItem("Reads 6-axis data test",19);//读取六轴感知器数据测试
    singleTestItem *testItem20 = new singleTestItem("Factory Reset",20);//恢复出厂设置
    singleTestItem *testItem21 = new singleTestItem("The 6-axis calibration check test",21);//六轴感知器静态校正写入确认



};
#endif // GLASSSECSITEM_H
