#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"logwidget.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include<QPushButton>
#include<QLabel>
#include<QTextEdit>
#include<QProcess>
#include<QtMultimedia/QMediaPlayer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPushButton *file;
    QPushButton *pause;
    QPushButton *start;

    QProcess *p;



//返回登录界面代码实现

signals:
        void M_login(); //登录主界面信号
        void close_Mwindow(); //关闭登录界面信号





public slots:
    void S_quit();
    void refresh();
    void file_open();
    void m_pause();
    //void m_start();
    void my_start();//返回主界面触发的事件


private:
        // 登录界面类的对象作为指针
        Logwidget * m_log;

        QMediaPlayer *player;   //播放者
        QString musicpath;      //本地音乐路径
        bool isplay=false;      //bool类型的播放判断变量
        QTextEdit *textEdit;


};

#endif // MAINWINDOW_H
