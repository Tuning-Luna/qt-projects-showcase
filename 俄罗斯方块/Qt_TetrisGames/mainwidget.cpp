#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <time.h>
#include <QMessageBox>
#include <QPainter>
#include <QKeyEvent>
#include <QtDebug>

// 定义方块图案代码和边界
// 田字形状
int item1[4][4]={
    {0,0,0,0},
    {0,1,1,0},
    {0,1,1,0},
    {0,0,0,0}
};

// 右L
int item2[4][4]={
    {0,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,0,0}
};

// 左L
int item3[4][4]={
    {0,0,1,0},
    {0,0,1,0},
    {0,1,1,0},
    {0,0,0,0}
};

// 右S
int item4[4][4]={
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,0,0}
};

// 左S
int item5[4][4]={
    {0,0,1,0},
    {0,1,1,0},
    {0,1,0,0},
    {0,0,0,0}
};

// 山形
int item6[4][4]={
    {0,0,0,0},
    {0,0,1,0},
    {0,1,1,1},
    {0,0,0,0}
};

// 左S
int item7[4][4]={
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0}
};



// 拷贝方块图案
inline void block_copy(int dblock[4][4],int sblock[4][5])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            dblock[i][j]=sblock[i][j];
        }
    }
}







MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::InitGameFunc()    // 初始化工作
{
    for (int i=0;i<AREA_ROW;i++) {
        for (int j=0;j<AREA_COL;j++) {
            game_area[i][j]=0;

        }
    }

    speed_ms=800;
    refresh_ms=30;

    // 初始化随机种子
    srand(time(0));

    // 分数初始化为0
    score=0;

    // 游戏开始
    StartGameFunc();

}

void MainWidget::StartGameFunc()   // 游戏开始
{
    game_timer=startTimer(speed_ms); // 游戏开始timer
    paint_timer=startTimer(refresh_ms);

    // 产生初始化下一个方块
    int block_id=rand()%7;

    CreateBlock(next_block,block_id);

    // 产生方块
    ResetBlock();

}

void MainWidget::GameOverFunc()    // 游戏结束
{

}




void MainWidget::ResetBlock() // 重置方块
{

}

void MainWidget::BlockMove(Direction dir) // 方块开动
{

}

void MainWidget::BlockRotate(int block[4][4]) // 方块旋转
{

}

void MainWidget::CreateBlock(int block[4][4],int block_id) // 产生方块
{
    switch (block_id) {
    case 0:
        block_copy(block,item1);
        break;
    case 1:
        block_copy(block,item2);
        break;

    case 2:
        block_copy(block,item3);
        break;
    case 3:
        block_copy(block,item4);
        break;
    case 4:
        block_copy(block,item5);
        break;
    case 5:
        block_copy(block,item6);
        break;
    case 6:
        block_copy(block,item7);
        break;
    default:
        break;
    }
}

void MainWidget::GetBorder(int block[4][4],Border &border) // 计算边界
{

}

void MainWidget::ConvertStable(int x,int y) // 转换为稳定方块
{

}

bool MainWidget::IsCollide(int x,int y,Direction dir) // 判断是否会碰撞
{

}









MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 设置窗口标题名称
    setWindowTitle("俄罗斯方块游戏--测试版V1.0");

    // 禁止用户使用最大化按钮
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    // 固定窗口大小
    setFixedSize(AREA_COL*BLOCK_SIZE+MARGIN*4+4*BLOCK_SIZE,AREA_ROW*BLOCK_SIZE+MARGIN*2);

    // 设置游戏背景图片
    QPixmap bkground("d://3.png");
    bkground=bkground.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palatte;
    palatte.setBrush(QPalette::Background,bkground);
    this->setPalette(palatte);

    // 设置游戏背景音乐
    QMediaPlayer *player=new QMediaPlayer;
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile("d://testmp3.mp3"));
    player->setVolume(10);
    player->play();

    // 初始化游戏
    InitGameFunc();    // 初始化工作

}




