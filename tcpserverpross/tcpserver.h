#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>

#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "server.h"

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~TcpServer();
private:
    // 使用 Qt 框架开发 GUI 程序，如果需要以列表的方法展示数据，可以优先考虑用 QListWidget 类实现。
    QListWidget *ContentListWidget;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;
    int port;
    Server *server;

public slots:
    void slotCreateServer();
    void updateServer(QString,int);

};
#endif // TCPSERVER_H
