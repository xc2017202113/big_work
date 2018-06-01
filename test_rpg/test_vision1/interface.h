#ifndef INTERFACE_H
#define INTERFACE_H

#include<iostream>
#include<QKeyEvent>
#include<QImage>
#include<QMouseEvent>
#include<vector>
#include<string>
#include<QString>
#include<QDebug>
#include <QPainter>
using namespace std;
//这里是界面的类
//登录界面 游走界面 战斗界面
class interface
{
public:
    interface(){};
    //~interface(){};//析构类
    //~interface(){};
    virtual void loadinterface(QPainter *pa){};//加载界面的函数

    void set_interface(short i){this->now_interface = i;}//设置场景
    short get_interface()const{return this->now_interface;}//得到场景
    vector<QImage>::iterator it;


protected:
    vector<QImage> _pic;
    short now_interface;//1.登录界面 2.游走界面 3.战斗界面

    bool start = false;
};

#endif // INTERFACE_H
