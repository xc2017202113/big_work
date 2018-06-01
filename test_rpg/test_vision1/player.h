#ifndef PLAYER_H
#define PLAYER_H

#include"attribute.h"
#include"skill.h"
#include<QMouseEvent>
#include<QKeyEvent>
//玩家--属性与技能构成了玩家
class player:public attribute
{
public:
    player();
    void attack(QKeyEvent *k);//按键来发出攻击
    void key_move(QKeyEvent *e);
    void show(QPainter *pa);

    static int GRID_SIZE;
    vector<skill>::iterator it_skill;//迭代器
private:
    vector<skill> sl;//技能在构造函数里实现

};

#endif // PLAYER_H
