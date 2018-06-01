#include "skill.h"


using namespace std;



skill::skill()
{
    this->state = 1;
}

void skill::store_pic(QString path)
{
    QImage buff;
    buff.load(path);
    if(buff.isNull()) qDebug()<<"not load skill"<<endl;
    this->pic.push_back(buff);
}

bool skill::attack(QPoint &a, QPoint &b)
{//传两个点的距离
    if( (a.x()-b.x())*(a.x()-b.x()) + (a.y()-b.y())*(a.y()-b.y()) <= this->radius*this->radius )
    {
        if(this->state == 1)
        {
            //this->set_state(3);
            return true;
        }
        else return false;
    }
    else return false;
}

void skill::show(QPainter *pa,int x,int y)
{
    for(this->it_pic = this->pic.begin();it_pic != this->pic.end();it_pic++)
    {
        pa->drawImage(x,y,(*it_pic));
    }
    this->change_state();
}
