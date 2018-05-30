#include "attribute.h"

attribute::attribute()
{

}

void attribute::loadAll(QString path)
{
    this->all.load(path);
}

void attribute::move(int direction, int steps)
{
    if(_direc != direction){
        _steps = 1;
        _direc = direction;
    }
    switch (direction){
        case 1:
            this->_posY += steps;
            break;
        case 4:
            this->_posY -= steps;
            break;
        case 2:
            this->_posX -= steps;
            break;
        case 3:
            this->_posX += steps;
            break;
    }
    //this->now = all.copy(QRect(_steps*Character::GRID_SIZE, _direc*Character::GRID_SIZE, 1*Character::GRID_SIZE, 1*Character::GRID_SIZE));
    _steps++;
    _steps = _steps % 3;
}



void attribute::LVup()
{
    if(_EXPnow < _EXP)
           return;
    this->_LV++;
    this->_HP += 5;
    this->_HPnow = _HP;
    this->_MP += 2;
    this->_MPnow = _MP;
    this->_EXPnow = 0;
    this->_EXP += 5;
}

void attribute::injured(int n_attack)
{
    int inj = n_attack - this->_defend;
    if(inj<0) inj = 0;
    this->_HPnow -= inj;
}

void attribute::healed(int HP)
{
    this->_HPnow += HP;
    if(_HP<_HPnow)
        _HPnow = _HP;
}

void attribute::addEXP(int e)
{
    this->_EXPnow += e;
    if(this->_EXPnow >= this->_EXP)
        this->LVup();
}


