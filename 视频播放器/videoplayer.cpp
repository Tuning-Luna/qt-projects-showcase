#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
{
    ui->setupUi(this);



    player=new QMediaPlayer(this);
    player->setNotifyInterval(2000);

    QGraphicsScene *scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    videoItem=new QGraphicsVideoItem;
    videoItem->setSize(QSizeF(380,260));
    videoItem->setFlags(QGraphicsItem::ItemIsMovable
                        | QGraphicsItem::ItemIsSelectable
                        | QGraphicsItem::ItemIsFocusable);
    scene->addItem(videoItem);
    player->setVideoOutput(videoItem);

    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),
            this,SLOT(onStateChanged(QMediaPlayer::State)));


    connect(player,SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));

    connect(player,SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));

}

VideoPlayer::~VideoPlayer()
{
    delete ui;
}


void VideoPlayer::on_pushButton_Add_clicked()
{
    QString currentpath=QDir::homePath(); // 获取系统当前目录
    QString dlgTitle="请选择视频文件"; // 打开文件对话框标题名称
    QString strfilter="Mp4 Files(*.mp4);;All Files(*.*)"; // 文件过滤器
    QString allfiles=QFileDialog::getOpenFileName(this,dlgTitle,currentpath,strfilter);

    if(allfiles.isEmpty())
    {
        QMessageBox::critical(this,"错误","打开视频文件失败，请重新检查？",QMessageBox::Yes);
        return;
    }

    QFileInfo fileInfos(allfiles); // 获取文件信息
    ui->labelCurrentMdia->setText(fileInfos.fileName());

    player->setMedia(QUrl::fromLocalFile(allfiles));
    player->play();
}

void VideoPlayer::onStateChanged(QMediaPlayer::State state)
{
    ui->pushButton_Player->setEnabled(!(state==QMediaPlayer::PlayingState));
    ui->pushButton_Pause->setEnabled(state==QMediaPlayer::PlayingState);
    ui->pushButton_Stop->setEnabled(state==QMediaPlayer::PlayingState);

}
void VideoPlayer::onDurationChanged(qint64 duration)
{
    ui->horizontalSlider_Position->setMaximum(duration);

    int   secs=duration/1000;//秒
    int   mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    durationTime=QString::asprintf("%d:%d",mins,secs);
    ui->label_Ratio->setText(positionTime+"/"+durationTime);

}
void VideoPlayer::onPositionChanged(qint64 position)
{
    if (ui->horizontalSlider_Position->isSliderDown())
        return;

    ui->horizontalSlider_Position->setSliderPosition(position);//

    int   secs=position/1000;//秒
    int   mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    positionTime=QString::asprintf("%d:%d",mins,secs);
    ui->label_Ratio->setText(positionTime+"/"+durationTime);

}


void VideoPlayer::on_pushButton_Player_clicked()
{
    player->play();
}

void VideoPlayer::on_pushButton_Sound_clicked()
{
    bool mte=player->isMuted();
    player->setMuted(!mte);

    if(mte)
        ui->pushButton_Sound->setIcon(QIcon(":/new/prefix1/images/volumn.bmp"));
    else
        ui->pushButton_Sound->setIcon(QIcon(":/new/prefix1/images/mute.bmp"));;
}

void VideoPlayer::on_pushButton_Pause_clicked()
{
    player->pause();
}

void VideoPlayer::on_pushButton_Stop_clicked()
{
    player->stop();
}
