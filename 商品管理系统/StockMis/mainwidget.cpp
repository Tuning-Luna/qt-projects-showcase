#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 禁止窗口最大化按钮
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    // 固定窗口大小（以UI界面设计为准）
    setFixedSize(width(),height());

    // 设置输入密码控件为密文
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);

    // 初始用户权限
    ui->comboBox_cleck->addItem("管理员",1);
    ui->comboBox_cleck->addItem("普通用户",2);

    // 限制用户名称和用户密码长度
    ui->lineEdit_user->setMaxLength(16);
    ui->lineEdit_Password->setMaxLength(16);



}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::on_pushButton_Exit_clicked()
{
    this->close();
}
