#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QKeyEvent>
#include<QDebug>
#include<QTime>
#include<QTimer>

#include"interface.h"
#include"load_interface.h"
#include"run_interface.h"
#include"player.h"
#include"attribute.h"
#include"monster.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void setinterface(short i){this->now_interface = i;}
    short getinterface()const{return this->now_interface;}

    void change_interface(int pre, int) ;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void control_move();

private:
    Ui::MainWindow *ui;
    load_interface *ld;
    run_interface *rd;
    player *_player1;
    monster *_monster1;
    QTimer *monster_move;
    short now_interface;//现在的界面 1.登录界面 2.游走界面 3.战斗界面
};

#endif // MAINWINDOW_H
