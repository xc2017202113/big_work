#ifndef MONSTER_H
#define MONSTER_H
#include"attribute.h"
#include"skill.h"
#include<QMouseEvent>
#include<QKeyEvent>

class monster:public attribute
{
public:
    monster();
    void attack(QKeyEvent *k);//按键来发出攻击
    void key_move(QKeyEvent *e){};//自己移动暂时不用处理
    void show(QPainter *pa);

    static int GRID_SIZE;
    //自己移动的一个槽函数
    void move_monster();


private:
    vector<skill> sl;//技能在构造函数里实现
    vector<skill>::iterator it_skill;//迭代器
};

#endif // MONSTER_H