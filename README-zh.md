[English](./README.md) | [中文](./README-zh.md)

# Qt 项目实战合集

> 基于 Qt/C++ 的桌面端应用项目合集，涵盖 GUI 布局、游戏开发、网络通信、多媒体播放与商业管理系统等方向，适合 Qt 初学者到进阶开发者参考学习。

---

## 📦 项目一览

| 项目 | 简介 | 涉及 Qt 模块 |
|---|---|---|
| 🎮 **俄罗斯方块** | 经典俄罗斯方块游戏，支持键盘控制与计分 | `QWidget`、`QTimer`、`QPainter` |
| ♟️ **五子棋** | 双人对战五子棋，支持落子判断与胜负检测 | `QWidget`、`QPainter`、`QMouseEvent` |
| 🌤️ **天气预报系统** | 通过网络 API 获取并展示实时天气信息 | `QNetworkAccessManager`、`QJsonDocument` |
| 🎬 **视频播放器** | 桌面视频播放器，支持播放、暂停、进度控制 | `QMediaPlayer`、`QVideoWidget` |
| 💬 **局域网聊天工具** | 基于局域网的即时通讯工具，支持多用户聊天 | `QTcpSocket`、`QTcpServer`、`QUdpSocket` |
| 🛒 **商品管理系统** | 商品增删改查管理系统，数据持久化存储 | `QSqlDatabase`、`QTableView`、`QSqlTableModel` |
| 📝 **文档编辑器** | 富文本文档编辑器，支持字体格式与文件读写 | `QTextEdit`、`QToolBar`、`QFileDialog` |
| 📐 **布局管理** | Qt 常用布局管理器的演示与对比 | `QHBoxLayout`、`QVBoxLayout`、`QGridLayout` |
| 🔌 **tcpserverpross** | TCP 多客户端服务器示例，演示并发连接处理 | `QTcpServer`、`QThread` |

---

## 🛠️ 开发环境要求

- **Qt** 5.x 或 6.x
- **Qt Creator**（推荐 IDE）
- **C++11** 或更高标准
- 天气预报系统需申请天气 API Key（如 OpenWeatherMap）
- 商品管理系统使用 SQLite（Qt 已内置，无需额外安装）

---

## 🚀 快速开始

**1. 克隆仓库**

```bash
git clone https://github.com/your-username/qt-projects-showcase.git
cd qt-projects-showcase
```

**2. 用 Qt Creator 打开项目**

- 启动 Qt Creator
- 点击菜单 **文件 → 打开文件或项目**
- 进入对应项目文件夹，选择 `.pro` 文件打开

**3. 编译并运行**

- 选择目标构建套件（Desktop Qt 5/6）
- 按下 **Ctrl+R** 一键编译运行

---

## 📁 目录结构

```
qt-projects-showcase/
├── 俄罗斯方块/          # 俄罗斯方块游戏
├── 五子棋/              # 五子棋对战游戏
├── 天气预报系统/         # 实时天气预报应用
├── 视频播放器/           # 桌面视频播放器
├── 局域网聊天工具软件/    # 局域网即时通讯工具
├── 商品管理系统/         # 商品信息管理系统
├── 文档编辑器/           # 富文本文档编辑器
├── 布局管理/             # 布局管理器演示
└── tcpserverpross/      # TCP 服务器示例
```

每个子目录均为独立的 Qt 项目，包含对应的 `.pro` 工程文件，可单独打开编译运行。

---

## 🎯 学习收获

通过这些项目，你将系统掌握以下 Qt 开发技能：

- Qt Widgets 桌面应用开发全流程
- 信号与槽机制、事件驱动编程模型
- 基于 `QTcpSocket` / `QUdpSocket` 的网络编程
- 使用 `Qt SQL` 模块操作数据库
- 使用 `Qt Multimedia` 实现音视频播放
- 使用 `QPainter` 进行 2D 图形绘制
- GUI 界面布局设计与响应式排版

---

## 📄 开源说明

本仓库代码仅供学习与参考使用，欢迎自由修改和二次开发。

---

## 🙌 参与贡献

欢迎提交 Issue 或 Pull Request！如果你发现了 Bug，或者希望改进某个项目，随时欢迎参与贡献。
