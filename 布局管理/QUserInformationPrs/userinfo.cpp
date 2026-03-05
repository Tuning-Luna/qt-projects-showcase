#include "userinfo.h"

UserInfo::UserInfo(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("项目1--布局管理");

    // 创建对象
    usernamelabel=new QLabel("用户名:");
    usernamelineedit=new QLineEdit;


    // 布局管理
    llayout=new QGridLayout();
    llayout->addWidget(usernamelabel,0,0);
    llayout->addWidget(usernamelineedit,0,1);



    QGridLayout *mainlayout=new QGridLayout(this);
    mainlayout->addLayout(llayout,0,0);

}

UserInfo::~UserInfo()
{
}

