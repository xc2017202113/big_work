#ifndef SYSTEM_H
#define SYSTEM_H

#include<QDebug>
#include<iostream>
#include<QPainter>
#include<QImage>

using namespace std;

//系统的类：背包系统；设置系统：储存，离开游戏；任务系统

class system
{
public:
    system();
    int getstate()const{return this->state;}

    void set_state(int i){this->state = i;}


protected:
    QImage pic;//图标
    int state;//1.启用 2.不启用
};

#endif // SYSTEM_H
