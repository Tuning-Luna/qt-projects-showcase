#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 固定窗口大小（以自定义尺寸为准）
   setFixedSize(width(),height());


}

MainWidget::~MainWidget()
{
    delete ui;
}

// 重绘事件
void MainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painters(this);
    painters.drawPixmap(rect(),QPixmap(":/new/prefix1/images/bg2.jpg"),QRect());

}

void MainWidget::on_pushButton_Color_clicked()
{
    fontcolor=QColorDialog::getColor(fontcolor,this);
    if(fontcolor.isValid())
    {
        ui->textEdit_Msg->setTextColor(fontcolor);
        ui->textEdit_Msg->setFocus();
    }

}

void MainWidget::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit_Msg->setCurrentFont(f);
    ui->textEdit_Msg->setFocus();

}



void MainWidget::on_comboBox_Size_currentIndexChanged(const QString &arg1)
{
    ui->textEdit_Msg->setFontPointSize(arg1.toDouble());
    ui->textEdit_Msg->setFocus();
}
