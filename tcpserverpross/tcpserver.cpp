#include "tcpserver.h"

TcpServer::TcpServer(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    this->resize(500,350);
    setWindowTitle("聊天室服务端系统 V2.0");

    ContentListWidget = new QListWidget;

    PortLabel = new QLabel("机器端口：");

    PortLineEdit = new QLineEdit();


    CreateBtn = new QPushButton("启动服务...");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget,0,0,1,3);
    mainLayout->addWidget(PortLabel,1,0);
    mainLayout->addWidget(PortLineEdit,1,1);
    mainLayout->addWidget(CreateBtn,1,2);

    port=6688;
    PortLineEdit->setText(QString::number(port));

    connect(CreateBtn,SIGNAL(clicked()),this,SLOT(slotCreateServer()));
}

TcpServer::~TcpServer()
{
}

void TcpServer::slotCreateServer()
{
    server = new Server(this,port);
    connect(server,SIGNAL(updateServer(QString,int)),this,SLOT(updateServer(QString,int)));

    CreateBtn->setEnabled(false);
}

void TcpServer::updateServer(QString msg,int length)
{
    ContentListWidget->addItem(msg.left(length));
}

