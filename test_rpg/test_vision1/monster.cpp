#include "monster.h"
int monster::GRID_SIZE = 32;

monster::monster()
{
    skill first;//第一个技能--普通攻击
    //技能的实现
    first.set_CD(10);
    //first.set_state(1);
    this->_state = 1;
    first.set_harm(2);
    first.set_type(1);

    first.store_pic("F:\\qt\\test_rpg\\test_vision1\\pic\\file.png");
    this->sl.push_back(first);
    this->it_skill = this->sl.begin();
    (*it_skill).it_pic = (*it_skill).pic.begin();

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
    this->fight_all.load("F:\\qt\\test_rpg\\test_vision1\\pic\\monster.png");//加载总的战斗图片

    QImage buff;
    buff.load("F:\\qt\\test_rpg\\test_vision1\\pic\\monster.png");
    if(buff.isNull()) qDebug()<<"wrong to load fight"<<endl;
    this->fight.push_back(buff);
    buff.load("F:\\qt\\test_rpg\\test_vision1\\pic\\monster.png");
    this->fight.push_back(buff);
    buff.load("F:\\qt\\test_rpg\\test_vision1\\pic\\monster.png");
    this->fight.push_back(buff);
    buff.load("F:\\qt\\test_rpg\\test_vision1\\pic\\monster.png");
    this->fight.push_back(buff);//加载释放技能的图片

}


void monster::show(QPainter *pa)
{
    if(this->_sence == 1)
    {
        this->it_pic = this->pic.begin();
        this->it_pic += (this->_direc-1)*3 + this->_steps;
        if((*it_pic).isNull()) qDebug()<<"wrong to load this player"<<endl;
        pa->drawImage(this->_posX*GRID_SIZE,this->_posY*GRID_SIZE,(*it_pic));
    }
    else if(this->_sence == 2)
    {
        this->setX(30);
        this->setY(10);
        pa->drawImage(this->_posX*GRID_SIZE,this->_posY*GRID_SIZE,(this->fight_all));

    }

    else if(this->_sence == 3)
    {
        this->setX(30);
        this->setY(10);
        static int time = 0;
        this->it_pic = this->fight.begin();
        this->it_pic += time;
        if(it_pic == this->fight.end())
        {
            time = 0;
            this->setsence(4);//放完图片切回2
        }
        else
        {
            pa->drawImage(this->_posX*GRID_SIZE,this->_posY*GRID_SIZE,*(this->it_pic));
            time++;
        }
    }

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
    if(this->_sence == 1)
    {
        srand((unsigned)time(NULL));
        int i=(rand()%4)+1;
        this->move(i,1);
    }

}

void monster::attack()
{
    (*this->it_skill).it_pic = (*this->it_skill).pic.begin();//第一个技能
    (*this->it_skill).change_state();//改变技能的状态
    this->setsence(3);
}
