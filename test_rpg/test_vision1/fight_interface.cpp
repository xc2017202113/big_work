#include "fight_interface.h"

fight_interface::fight_interface()
{
    QImage buff;
    buff.load("F:\\qt\\test_rpg\\test_vision1\\pic\\background.jpg");
    this->_pic.push_back(buff);

    //初始化一些参数
    this->turn = 1;
    this->time = 60;
    this->it = this->_pic.begin();
}

void fight_interface::loadinterface(QPainter *pa)
{
    pa->drawImage(0,0,(*it));
}
