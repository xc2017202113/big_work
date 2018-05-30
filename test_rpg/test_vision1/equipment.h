#ifndef EQUIPMENT_H
#define EQUIPMENT_H

//这里是装备的类:分为头盔，手套，戒指，盾牌，武器
#include<QDebug>
#include<QImage>
#include<iostream>
using namespace std;

class equipment
{
public:
    equipment();


protected:

    int eq_HP;      //生命值
    int eq_MP;      //魔法值
    int eq_attack;        //攻击力
    int eq_m_attack;  //魔法攻击
    int eq_defend;        //防御力
    int eq_m_defend; //魔法防御
};

#endif // EQUIPMENT_H
