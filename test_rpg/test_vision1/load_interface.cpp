#include "load_interface.h"

load_interface::load_interface()
{
    this->set_interface(1);
    QString buff;

    for(int i=1;i<=16;i++)
    {
        QString path("F:\\qt\\test_rpg\\test_vision1\\load_pic\\snow.png");
        QImage p ;
        buff.setNum(i);
        path.insert(41,buff);
        qDebug()<<"debug: "<<path<<endl;
        p.load(path);
        if(p.isNull()) qDebug()<<"unload"<<endl;
        this->_pic.push_back(p);
        //delete p;
    }
    this->start = false;
    this->click.load("F:\\qt\\test_rpg\\test_vision1\\load_pic\\load_pic.png");

}

void load_interface::loadinterface(QPainter *pa)
{

    //it = this->_pic.begin();
    it++;
    if(it == this->_pic.end() || start == false)
    {
        it = this->_pic.begin();
        start = true;
    }

    if((*it).isNull())qDebug()<<"worry to load"<<endl;
    static int i = 0;
    i%=16;
    i++;
    qDebug()<<"i: "<<i<<endl;
    //advance(it,i);//向后移动i个单位


    pa->drawImage(0,0,(*it));
     pa->drawImage(150,150,this->click);

}
