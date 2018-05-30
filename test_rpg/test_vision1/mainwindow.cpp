#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1400,800);//改变屏幕的大小
    this->now_interface = 1;
    this->ld = new load_interface;
    this->rd = new run_interface;
    this->_player1 = new player;
    this->_monster1 = new monster;

    monster_move = new QTimer(this);
    connect(monster_move,SIGNAL(timeout()),this,SLOT(control_move()));//timeoutslot()为自定义槽
    //timer2->start(10);
    monster_move->start(800);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter *pa = new QPainter;
    pa->begin(this);
    //this->change_interface(1,1);
    switch(this->now_interface)
    {//画出界面
        case 1:
        qDebug()<<"1"<<endl;
            this->ld->loadinterface(pa);
            break;

        case 2:
            this->rd->loadinterface(pa);
            this->_player1->show(pa);
            this->_monster1->show(pa);
            break;
    }
    //this->repaint();

    pa->end();

    delete pa;

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(this->now_interface == 1  )
    {

        if(event->button() == Qt::LeftButton)//用左键来控制
        {
            qDebug()<<"x: "<<event->pos().x()<<endl;
            qDebug()<<"y: "<<event->pos().y()<<endl;
            if(event->pos().x()>= 415 && event->pos().x()<= 600 && event->pos().y()>= 282 && event->pos().y()<= 340)
            {
                this->now_interface = 2;
            }
        }
        this->repaint();
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    this->_player1->key_move(event);
    this->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::control_move()
{
    this->_monster1->move_monster();
}

void MainWindow::change_interface(int pre,int now)
{
    switch(pre)
    {
        case 1:
            delete this->ld;
            break;

        case 2:
            delete this->rd;
            break;

    }

    switch(now)
    {
        case 1:
            this->ld = new load_interface;
            break;

        case 2:
            this->rd = new run_interface;
            break;
    }
}
