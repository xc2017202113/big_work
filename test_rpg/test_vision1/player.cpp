#include "player.h"


int player::GRID_SIZE = 32;
/*
 *    short _direc;//0123上下左右
    int _steps;//人物走的步数
    short _state;    //0死亡1正常
    int _posX;  //人物的坐标
    int _posY;
    int _LV;      //等级
    int _HP;      //生命值
    int _HPnow;     //当前生命
    int _MP;      //魔法值
    int _MPnow;     //当前魔法
    int _EXP;     //经验值
    int _EXPnow;   //当前经验
    int _attack;        //攻击力
    int _m_attack;  //魔法攻击
    int _defend;        //防御力
    int _m_defend; //魔法防御
    int _camp;     //阵营
    int _sence; //场景 1.游走模式 2.战斗模式
*/


player::player()
{
    skill first;//第一个技能--普通攻击
    //技能的实现
    first.set_CD(10);
    first.set_state(1);
    first.set_harm(2);
    first.set_type(1);
    first.store_pic("F:\\qt\\test_rpg\\test_vision1\\pic\\file.png");

    this->sl.push_back(first);

    //设置人物属性
    this->setDirec(1);
    this->setSteps(1);
    this->setState(1);
    this->setX(20);
    this->setY(10);
    this->setLV(1);
    this->setHP(10);
    this->setMP(5);
    this->setEXP(10);
    this->setAtt(5);
    this->setMAtt(3);
    this->setDef(1);
    this->setMDef(1);
    this->setCamp(0);
    this->setsence(1);

    //设置图片
    this->loadAll("F:\\qt\\test_rpg\\test_vision1\\pic\\boss4a.png");
    this->fight_all.load("F:\\qt\\test_rpg\\test_vision1\\pic\\fight_player.png");

    QImage buff;
    buff.load("F:\\qt\\test_rpg\\test_vision1\\pic\\attack.png")
    QImage attack_pic;
    for(int i=0;i<3;i++)
    {
        attack_pic = buff.copy(QRect(i*this->GRID_SIZE,4*this->GRID_SIZE,4*this->GRID_SIZE,4*this->GRID_SIZE));
        this->fight.push_back(attack_pic);
    }//加载进战斗的图片



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

void player::key_move(QKeyEvent *e)
{
    if(e->key() == Qt::Key_A)
    {
        this->move(2,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->move(3,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->move(4,1);
    }
    else if(e->key() == Qt::Key_S)
    {
        this->move(1,1);
    }

}

void player::show(QPainter *pa)
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
