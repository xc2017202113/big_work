#ifndef NPC_H
#define NPC_H

//npc只有属性

#include"attribute.h"

class NPC:public attribute
{
public:
    NPC();
    void key_move(QKeyEvent *e){};
    void show(QPainter *pa){};
};

#endif // NPC_H
