#include "mainwindow.h"


#include <QDockWidget>
#include <QCalendarWidget>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDockWidget *dkwidget1=new QDockWidget("日历显示");

    resize(500,300);

    setWindowTitle("停靠窗体测试--QDockWidget类");
    // 可以进行移动、可以浮动、但是不能关闭
    dkwidget1->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);

    // 在停靠窗体里面添加一个日历控件
    dkwidget1->setWidget(new QCalendarWidget());

    // 允许停靠窗口在左 右 顶部
    dkwidget1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea|Qt::TopDockWidgetArea);

    // 将停靠窗口dkwidget1添加到MainWindow
    this->addDockWidget(Qt::RightDockWidgetArea,dkwidget1);

    // 禁止dock嵌套
    this->setDockNestingEnabled(false);



    QDockWidget *dkwidget2=new QDockWidget("文档编辑器");

    dkwidget2->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);

    dkwidget2->setWidget(new QTextEdit());

    dkwidget2->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea|Qt::TopDockWidgetArea);

    this->addDockWidget(Qt::RightDockWidgetArea,dkwidget2);


}

MainWindow::~MainWindow()
{
}

