#ifndef SKILL_H
#define SKILL_H

#include<iostream>
#include<QImage>
#include<QPainter>
#include<vector>//图片用vector来储存
#include<QString>、
#include<QPoint>
#include<QDebug>
#include<cmath>

using namespace std;
class skill
{
public:
    skill();
    //这些函数是得到状态的接口
    int get_state()const{return this->state;}
    int get_CD()const {return this->CD;}
    int get_harm()const{return this->harm;}
    int get_type()const {return this->type;}

    //这些是改变值的函数
    void change_state(){
        if(this->state == 1) this->state = 2;
        else this->state = 1;
    }
    void set_CD(int i){this->CD = i;}
    void set_harm(int i){this->harm = i;}
    void set_type(int i){this->type = i;}

    bool attack(QPoint &a,QPoint &b);//攻击的函数
    void store_pic(QString);
    vector<QImage>::iterator it_pic;
    void show(QPainter *pa,int x,int y);//画出技能的函数
    vector<QImage> pic;
protected:


    int state;//1.未触发的状态 2.触发的状态
    int CD;
    int harm;//收到的伤害
    int type;//攻击的类型 1.物理攻击 2.魔法攻击
    int radius;//攻击的范围
};

#endif // SKILL_H
