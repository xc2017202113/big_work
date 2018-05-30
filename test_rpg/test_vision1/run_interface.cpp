#include "run_interface.h"

run_interface::run_interface()
{
    this->set_interface(2);
    QImage sence1 ;
    sence1.load("F:\\qt\\test_rpg\\test_vision1\\pic\\CastleExample .png");
    this->_pic.push_back(sence1);
    this->start = false;
    it = this->_pic.begin();
}

void run_interface::loadinterface(QPainter *pa)
{
    //vector<QImage>::iterator it;
    pa->drawImage(0,0,(*it));//画图
}
