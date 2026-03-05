#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



#include <QMouseEvent>
#include <QSettings>
#include <QMessageBox>
#include <QByteArray>
#include <QCryptographicHash>
#include <QDialog>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::MainWindow *ui;



    // 自定义变量及函数
    // 测试版本直接使用指定：用户名称和用户口令
    // 上线版本直接使用数据库里面对应：数据表

    QString struser="123"; // 初始化用户名称
    QString strpwd="456"; // 初始化用户口令，没有加密

    int icount=0; // 登录系统错误资料统计

    QString strEncriypt(const QString &str); // 字符串加密处理

    // 读取设置直接从注册表去实现
    void ReadSetting();
    void WriteSetting();

    bool mmove=false; // 表示窗口是否在鼠标操作下移动功能
    QPoint mlastpos; // 上一次鼠标操作位置

protected:
    // 自定义重载操作
    // 用鼠标拖动窗口的鼠标事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMoveEvent *event);

















};
#endif // MAINWINDOW_H
