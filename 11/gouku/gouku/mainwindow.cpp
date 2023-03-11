#include "mainwindow.h"
#include<QLabel>
#include<QGridLayout>
#include<QMenuBar>
#include<QAction>
#include<QObject>
#include <QFileDialog>
#include <QTextStream>
#include "mainwindow.h"
#include <QFileDialog>  //增加头文件
#include <QFile>     //增加头文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{





    // 通过指针创建登录界面类的对象
        m_log = new Logwidget;
        // 调用登录窗口的show()函数显示登录界面
        m_log->show();

        //创建按钮

         file =new QPushButton(this);
         //file->setFlat(true);
         file->setText("打开本地音乐");
         file->setFixedSize(100,50);
         file->move(0,710);


         connect(file,&QPushButton::clicked,this,&MainWindow::file_open);
         //创建显示歌曲界面
         QLabel * label = new QLabel(this);
         label->setAlignment(Qt::AlignHCenter);
         textEdit = new QTextEdit(this);
         textEdit->setGeometry(320,100,260,250);

         //暂停
         pause=new QPushButton(this);
         pause->move(350,400);
         pause->setText("暂停");
         connect(pause,&QPushButton::clicked,this,&MainWindow::m_pause);



//         p = new QProcess(this);
//         this->pause->setEnabled(false);


        // 建立信号槽，到接收到登录界面发来的login()信号后，调用主窗口的show()函数。
        connect(m_log,SIGNAL(login()),this,SLOT(show()));

        QMenuBar *bar=menuBar();//创建菜单栏，只能有一个
        this->setMenuBar(bar);//将菜单栏放入窗口中
        QMenu *QuitMenu =bar->addMenu("开始");
        //添加菜单里的选项
        QAction *Newaction=QuitMenu->addAction("退出");
        QAction *Raction=QuitMenu->addAction("刷新");
        QAction *Re_start=QuitMenu->addAction("返回主界面");

        //添加分割线
         QuitMenu->addSeparator();
         connect(Newaction,SIGNAL(triggered()),this,SLOT(S_quit()));
         connect(Raction,SIGNAL(triggered()),this,SLOT(refresh()));
         //connect(Re_start,&QAction::triggered,this,&MainWindow::my_start);//返回主界面

         // 触发返回登录按钮的信号槽连接
        connect(Re_start,&QAction::triggered,this,&MainWindow::my_start);



}


void MainWindow::my_start()
{
    this->hide();
    m_log->show();





}
void MainWindow::file_open()
{


    QString path;   //定义
        path = QFileDialog::getOpenFileName(this,"open file","C:\\");//打开C盘文件夹
        if(path.isEmpty()==false)
            if(QMediaPlayer::PausedState!=player->state())
        {
            this ->textEdit->setText(path);  //将path获取的路径填入lineEdit 控件中，控件名要保持一致
            QFile file(path);
            player = new QMediaPlayer;
            player->setMedia(QUrl::fromLocalFile(path));
            player->play();
        }
}


void MainWindow::m_pause()
{

    if(QMediaPlayer:: PlayingState == player->state())
    {
         player->pause();

    }
    else{
         player->play();

    }

}
void MainWindow::S_quit()
{
    this->close();
}
void MainWindow::refresh()
{
    //this->refresh();

}
MainWindow::~MainWindow()
{

}
