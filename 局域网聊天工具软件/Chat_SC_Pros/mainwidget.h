#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>



#include <QPainter>
#include <QColor>
#include <QColorDialog>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;


protected:
    // 重绘事件
    void paintEvent(QPaintEvent *event);

    // 自定义字体颜色
    QColor fontcolor;

private slots:
    void on_pushButton_Color_clicked();
    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_comboBox_Size_currentIndexChanged(const QString &arg1);
};
#endif // MAINWIDGET_H
