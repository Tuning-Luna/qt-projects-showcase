#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{
    QString strmd5=strEncriypt("12345");
    QMessageBox::information(this,"提示",strmd5,QMessageBox::Yes);

}

QString MainWindow::strEncriypt(const QString &str) // 字符串加密处理
{
    // 字符串MD5加密算法
    QByteArray btarray;

    btarray.append(str); // 加入原始字符中
    QCryptographicHash hash(QCryptographicHash::Md5);  // MD5加密算法
    hash.addData(btarray); // 添加数据到加密哈希值
    QByteArray resultarray=hash.result(); // 返回最终的哈希值
    QString md5=resultarray.toHex(); // 转换成16进制字符串

    return md5;
}

// 自定义重载操作
// 用鼠标拖动窗口的鼠标事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // 鼠标按键被按下的时候
    if(event->button()==Qt::LeftButton)
    {
        mmove=true;
        mlastpos=event->globalPos()-pos();
    }

    return MainWindow::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标按下左移动操作
    if(mmove && (event->buttons() && Qt::LeftButton) &&
            (event->globalPos()-mlastpos).manhattanLength()>QApplication::startDragDistance())
    {
        move(event->globalPos()-mlastpos);
        mlastpos=event->globalPos()-pos();
    }

    return MainWindow::mouseMoveEvent(event);
}




void MainWindow::mouseReleaseEvent(QMoveEvent *event)
{
    // 松开鼠标键释放
    Q_UNUSED(event);
    mmove=false; // 停止移动
}

void MainWindow::ReadSetting()
{


}
void MainWindow::WriteSetting()
{


}
