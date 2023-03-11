#include "logwidget.h"
#include "ui_logwidget.h"
#include<QMessageBox>
#include<QDebug>
#include<QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include<QPainter>
#include<QPixmap>
#include"mainwindow.h"
#include<QAction>
Logwidget::Logwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logwidget)
{
    ui->setupUi(this);


    //ui图片
    QPixmap pixmap(":/image/gouku_image/1.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, pixmap);
    this->setPalette(palette);







    // connect 3个信号槽
        // 触发重置按钮的信号槽连接
        connect(ui->clear,SIGNAL(clicked()),this,SLOT(btn_clear_clicked()));
        // 触发登录按钮的信号槽连接
        connect(ui->enter,SIGNAL(clicked()),this,SLOT(btn_log_clicked()));
        // 发出信号后关闭登录窗口的信号槽连接
        connect(this,SIGNAL(close_window()),this,SLOT(close()));
        this->resize(650,400);


        this->setWindowTitle("登录界面");

        ui->password->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点
        m_username = "Hao";
        m_password = "Hao";
        read_json();




}
void Logwidget::read_json()
{
    QFile file(QApplication::applicationDirPath()+"/config.json");
    qDebug()<<QApplication::applicationDirPath()+"/config.json";
    if(!file.open(QIODevice::ReadOnly)) {
            qDebug() << "File open failed!";
        } else {
            qDebug() <<"File open successfully!";
        }
        QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
        QJsonObject obj = jdc.object();
        QString save_name_flag=obj.value("SAVE_NAME").toString();
        QString save_password_flag=obj.value("SAVE_PASSWORD").toString();
        message_init(save_name_flag,save_password_flag);


}

void Logwidget::write_json()
{
    QFile file(QApplication::applicationDirPath()+"/config.json");
        if(!file.open(QIODevice::WriteOnly)) {
            qDebug() << "File write failed!";
        } else {
            qDebug() <<"File write successfully!";
        }
        QJsonObject obj;
        bool flag = ui->check_name->isChecked();
        if(flag == true)
        {
            obj["SAVE_NAME"] = "1";
        }
        else
            obj["SAVE_NAME"] = "0";
        flag = ui->checkBox_pw->isChecked();
        if(flag == true)
        {
            obj["SAVE_PASSWORD"] = "1";
        }
        else
            obj["SAVE_PASSWORD"] = "0";
        QJsonDocument jdoc(obj);
        file.write(jdoc.toJson());
        file.flush();

}
void Logwidget::message_init(QString flag1,QString flag2)
{
    if(flag1=="1")
    {
        ui->accountant->setText("Hao");
        ui->check_name->setChecked(true);
    }
    if(flag2 == "1")
        {
            ui->password->setText("Hao");
            ui->checkBox_pw->setChecked(true);
        }

}
Logwidget::~Logwidget()
{
    delete ui;
}
void Logwidget::from_init()
{
   // ui->label->setGeometry(120,25,160,25);


}
// 清理输入栏
void Logwidget::btn_clear_clicked()
{
    ui->accountant->clear();
    ui->password->clear();
}

// 登录按钮触发事件
void Logwidget::btn_log_clicked()
{

    QString name=ui->accountant->text();
    QString password=ui->password->text();

    if(true||name==m_username&&password==m_password)
    {
        // 发出登录信号
        emit(login());
        write_json();
       // 发出关闭窗口信号
        emit(close_window());

    }
    else {
         QMessageBox::warning(this, tr("Waring"),
                                    tr("密码或者账号输入错误！"), QMessageBox::Abort);


    }

}

