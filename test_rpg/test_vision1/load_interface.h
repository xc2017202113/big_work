#ifndef LOAD_INTERFACE_H
#define LOAD_INTERFACE_H
#include "interface.h"
#include<vector>
//这个类的登录界面
class load_interface:public interface
{
public:
    load_interface();
    ~load_interface(){};
    void loadinterface(QPainter *pa);

private:
    QImage click;
};

#endif // LOAD_INTERFACE_H
