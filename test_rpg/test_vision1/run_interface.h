#ifndef RUN_INTERFACE_H
#define RUN_INTERFACE_H
#include"interface.h"

class run_interface:public interface
{
public:
    run_interface();
    ~run_interface(){};
    void loadinterface(QPainter *pa);
};

#endif // RUN_INTERFACE_H
