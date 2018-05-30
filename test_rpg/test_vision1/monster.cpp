#include "monster.h"
int monster::GRID_SIZE = 32;

monster::monster()
{
    skill first;//第一个技能--普通攻击
    //技能的实现
    first.set_CD(10);
    first.set_state(1);
    first.set_harm(2);
    first.set_type(1);

    this->sl.push_back(first);

    //设置人物属性
    this->setDirec(1);
    this->setSteps(1);
    this->setState(1);
    this->setX(30);
    this->setY(20);
    this->setLV(1);
    this->setHP(10);
    this->setMP(5);
    this->setEXP(10);
    this->setAtt(5);
    this->setMAtt(3);
    this->setDef(1);
    this->setMDef(1);
    this->setCamp(1);
    this->setsence(1);

    //设置图片
    this->loadAll("F:\\qt\\test_rpg\\test_vision1\\pic\\magician1a.png");
    if(this->all.isNull()) qDebug()<<"all is wrong"<<endl;
    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=2;j++)
        {
            QImage now = this->all.copy(QRect(j*GRID_SIZE,i*GRID_SIZE,1*GRID_SIZE,1*GRID_SIZE));
            if(now.isNull()) qDebug()<<"now is null "<<endl;
            this->pic.push_back(now);
        }
    }
}


void monster::show(QPainter *pa)
{
    this->it_pic = this->pic.begin();
    this->it_pic += (this->_direc-1)*3 + this->_steps;
    if((*it_pic).isNull()) qDebug()<<"wrong to load this player"<<endl;
    pa->drawImage(this->_posX*GRID_SIZE,this->_posY*GRID_SIZE,(*it_pic));
    pa->setBrush(Qt::NoBrush);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.6) * GRID_SIZE, GRID_SIZE, GRID_SIZE / 8);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.4) * GRID_SIZE, GRID_SIZE, GRID_SIZE / 8);

    pa->setBrush(Qt::red);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.6) * GRID_SIZE, _HPnow * GRID_SIZE / _HP, GRID_SIZE / 8);
    pa->setBrush(Qt::blue);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.4) * GRID_SIZE, _MPnow * GRID_SIZE / _MP, GRID_SIZE / 8);
}

void monster::move_monster()//槽函数的设置
{
    srand((unsigned)time(NULL));
    int i=(rand()%4)+1;
    this->move(i,1);
}
