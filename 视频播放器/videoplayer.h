#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>

#include <QGraphicsVideoItem>

#include <QFileDialog>
#include <QGraphicsScene>

#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class VideoPlayer; }
QT_END_NAMESPACE

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();

private:
    Ui::VideoPlayer *ui;




private:
    QMediaPlayer *player;
    QGraphicsVideoItem *videoItem;

    QString durationTime;
    QString positionTime;

private slots:
    // 自定义槽函数
    void onStateChanged(QMediaPlayer::State stat);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);














    void on_pushButton_Add_clicked();
    void on_pushButton_Player_clicked();
    void on_pushButton_Sound_clicked();
    void on_pushButton_Pause_clicked();
    void on_pushButton_Stop_clicked();
};
#endif // VIDEOPLAYER_H
