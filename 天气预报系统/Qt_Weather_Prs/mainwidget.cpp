#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 初始化天气预报所在：城市
    ui->comboBox_City->clear();
    QStringList qStrList;
    qStrList<<"Beijing"<<"Shanghai"<<"ShenZhen"<<"GuangZhou"<<"Changsha"<<"Chongqing";
    ui->comboBox_City->addItems(qStrList);

    // 处理QLCDNumber控件
    ui->lcdNumber_Time->setDigitCount(10);
    ui->lcdNumber_Time->setMode(QLCDNumber::Dec);
    ui->lcdNumber_Time->setSegmentStyle(QLCDNumber::Flat);

    QTimer *qtimer;
    qtimer=new QTimer();
    qtimer->setInterval(1000);

    qtimer->start();
    //信号和槽连接
    connect(qtimer,SIGNAL(timeout()),this,SLOT(OnTimerOutFunc()));

}

MainWidget::~MainWidget()
{
    delete ui;
}

// 获取当前时间
void MainWidget::OnTimerOutFunc()
{
    // 获取系统当前时间
    QTime qtime=QTime::currentTime();

    // 设置晶体管控件QLCDNumber显示时间
    ui->lcdNumber_Time->display(qtime.toString("HH:mm:ss"));
}

// 获取当天的天气预报数据
void  MainWidget::Get_CurrentWeather(QNetworkReply *qReply)
{

}

// 获取三天内天气预报数据
void MainWidget::Get_ThreeWeather(QNetworkReply *qReply)
{

}

void MainWidget::on_pushButton_GetData_clicked()
{

}
