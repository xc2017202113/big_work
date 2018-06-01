#ifndef FIGHT_INTERFACE_H
#define FIGHT_INTERFACE_H

#include"interface.h"

class fight_interface:public interface
{
public:
    fight_interface();
    void loadinterface(QPainter *pa);

    inline void changeturn()
    {
        if(turn == 1) turn = 2;
        else turn = 1;
    }

    void set_time(int i){this->time = i;}
    int get_time()const{return this->time;}
    int get_turn()const{return this->turn;}

private:

    int turn;//1.己方攻击 2.敌方攻击
    int time;//回合的时间
};

#endif // FIGHT_INTERFACE_H
