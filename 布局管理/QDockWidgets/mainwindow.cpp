#include "mainwindow.h"

#include <QDockWidget>
#include <QTextEdit>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置MainWindow相关功能
    setWindowTitle("停靠窗口测试--QDockWidget类");

    // 设置窗体高度和宽度
    resize(600,400);

    // 定义QTextEdit对象作为主窗口
    QTextEdit *maintext=new QTextEdit(this);

    // 为此控件添加文本内容
    maintext->setText("主窗口测试程序");

    // 将此控件设置中心对齐
    maintext->setAlignment(Qt::AlignCenter);

    // 将此控件设置为主窗口的中央窗口
    setCentralWidget(maintext);



    // 停靠窗口1
    QDockWidget *dock1=new QDockWidget("停靠窗口1",this);
    dock1->setFeatures(QDockWidget::DockWidgetMovable);
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *text1=new QTextEdit();
    text1->setText("停靠窗口1文本编辑区域");
    dock1->setWidget(text1);
    addDockWidget(Qt::RightDockWidgetArea,dock1);


    // 停靠窗口2
    dock1=new QDockWidget("停靠窗口2",this);
    dock1->setFeatures(QDockWidget::DockWidgetMovable);
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *text2=new QTextEdit();
    text2->setText("停靠窗口2文本编辑区域");
    dock1->setWidget(text2);
    addDockWidget(Qt::RightDockWidgetArea,dock1);


    // 停靠窗口3
    dock1=new QDockWidget("停靠窗口3",this);
    dock1->setFeatures(QDockWidget::DockWidgetMovable);
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *text3=new QTextEdit();
    text3->setText("停靠窗口3文本编辑区域");
    dock1->setWidget(text3);
    addDockWidget(Qt::RightDockWidgetArea,dock1);


}

MainWindow::~MainWindow()
{
}

