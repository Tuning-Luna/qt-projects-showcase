#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#pragma execution_character_set("utf-8")

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_pushButton_Exit_clicked();

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
