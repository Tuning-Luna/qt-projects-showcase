[English](./README.md) | [中文](./README-zh.md)

# qt-projects-showcase

> A collection of practical Qt/C++ desktop application projects, covering GUI layout, games, networking, multimedia, and business systems.

---

## 📦 Projects Overview

| Project | Description | Key Qt Modules |
|---|---|---|
| 🎮 **俄罗斯方块** (Tetris) | Classic Tetris game with keyboard controls and scoring | `QWidget`, `QTimer`, `QPainter` |
| ♟️ **五子棋** (Gomoku) | Two-player Gomoku (Five in a Row) board game | `QWidget`, `QPainter`, `QMouseEvent` |
| 🌤️ **天气预报系统** (Weather App) | Real-time weather forecast system via API | `QNetworkAccessManager`, `QJsonDocument` |
| 🎬 **视频播放器** (Video Player) | Desktop media player with playback controls | `QMediaPlayer`, `QVideoWidget` |
| 💬 **局域网聊天工具** (LAN Chat) | Local area network instant messaging tool | `QTcpSocket`, `QTcpServer`, `QUdpSocket` |
| 🛒 **商品管理系统** (Product Management) | CRUD-based goods/inventory management system | `QSqlDatabase`, `QTableView`, `QSqlTableModel` |
| 📝 **文档编辑器** (Document Editor) | Rich-text document editor with formatting support | `QTextEdit`, `QToolBar`, `QFileDialog` |
| 📐 **布局管理** (Layout Demo) | Demonstration of Qt layout managers and widgets | `QHBoxLayout`, `QVBoxLayout`, `QGridLayout` |
| 🔌 **tcpserverpross** | TCP server with multi-client connection handling | `QTcpServer`, `QThread` |

---

## 🛠️ Requirements

- **Qt** 5.x or 6.x
- **Qt Creator** (recommended IDE)
- **C++11** or later
- For weather app: A valid weather API key (e.g., OpenWeatherMap)
- For product management system: SQLite (bundled with Qt)

---

## 🚀 Getting Started

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/qt-projects-showcase.git
   cd qt-projects-showcase
   ```

2. **Open a project in Qt Creator**
   - Launch Qt Creator
   - Click **File → Open File or Project**
   - Navigate to the desired project folder and open the `.pro` file

3. **Build & Run**
   - Select your target kit (Desktop Qt 5/6)
   - Press **Ctrl+R** to build and run

---

## 📁 Project Structure

```
qt-projects-showcase/
├── 俄罗斯方块/          # Tetris game
├── 五子棋/              # Gomoku board game
├── 天气预报系统/         # Weather forecast app
├── 视频播放器/           # Video media player
├── 局域网聊天工具软件/    # LAN chat application
├── 商品管理系统/         # Product management system
├── 文档编辑器/           # Document text editor
├── 布局管理/             # Layout manager demo
└── tcpserverpross/      # TCP server example
```

Each subdirectory is a self-contained Qt project with its own `.pro` file.

---

## 🎯 Learning Goals

These projects are designed to help you learn:

- Qt Widget application development
- Event-driven programming and signal/slot mechanism
- Network programming with `QTcpSocket` / `QUdpSocket`
- Database integration using `Qt SQL`
- Multimedia handling with `Qt Multimedia`
- 2D graphics rendering with `QPainter`
- GUI layout design and responsive interfaces

---

## 📄 License

This repository is for educational and learning purposes. Feel free to use and modify the code for your own projects.

---

## 🙌 Contributing

Pull requests are welcome! If you find bugs or want to improve any project, feel free to open an issue or submit a PR.
