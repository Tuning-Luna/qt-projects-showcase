#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>



class UserInfo : public QDialog
{
    Q_OBJECT

public:
    UserInfo(QWidget *parent = nullptr);
    ~UserInfo();


private:
    // 标签控件对象
    QLabel *usernamelabel;

    // 单行编辑框控件对象
    QLineEdit *usernamelineedit;

    QGridLayout *llayout;

















};
#endif // USERINFO_H
