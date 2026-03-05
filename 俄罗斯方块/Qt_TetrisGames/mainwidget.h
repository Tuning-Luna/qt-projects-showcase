#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#pragma execution_character_set("utf-8")

#include <QWidget>

#include <QtMultimedia>


// 场景设置：行数和列数
const int AREA_ROW=20;
const int AREA_COL=12;

// 场景设置：边距
const int MARGIN=5;

// 单个方块单元的边长
const int BLOCK_SIZE=25;


// 方向
enum Direction{
    UP,DOWN,LEFT,RIGHT,SPACE
};

// 定义边界
struct Border{
    int ubound;
    int dbound;
    int lbound;
    int rbound;
};

// 定义坐标
struct block_point{
    int pos_x,pos_y;
};



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


public:
    void InitGameFunc();    // 初始化工作
    void StartGameFunc();   // 游戏开始
    void GameOverFunc();    // 游戏结束

    void ResetBlock(); // 重置方块
    void BlockMove(Direction dir); // 方块开动
    void BlockRotate(int block[4][4]); // 方块旋转
    void CreateBlock(int block[4][4],int block_id); // 产生方块
    void GetBorder(int block[4][4],Border &border); // 计算边界
    void ConvertStable(int x,int y); // 转换为稳定方块
    bool IsCollide(int x,int y,Direction dir); // 判断是否会碰撞


private:
    // 场景区域 1表示活动的方块 2表示稳定的方块 0表示为空
    int game_area[AREA_ROW][AREA_COL];

    // 当前方块形状
    int cur_block[4][4];

    // 下一个方块形状
    int next_block[4][4];

    // 当前方块坐标
    block_point block_pos;

    // 当前方块边界
    Border cur_border;

    // 游戏分数
    int score;

    // 方块下落计时器
    int game_timer;

    // 渲染刷新计时器
    int paint_timer;

    // 下落赶时间间隔
    int speed_ms;

    // 刷新时间间隔
    int refresh_ms;

    // 当前方块是否稳定
    bool isStable;




};
#endif // MAINWIDGET_H
