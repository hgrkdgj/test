#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include<QString>


namespace Ui {
class Logwidget;
}

class Logwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Logwidget(QWidget *parent = nullptr);
    ~Logwidget();

    void from_init();

    void read_json(); //读json
    void write_json();//写json
    void message_init(QString flag1,QString flag2);//根据json内容决定是否填充输入框
    void close_mainwindow();
signals:
        void login(); //登录主界面信号
        void close_window(); //关闭登录界面信号
public slots:
    void btn_clear_clicked(); //重置按钮按下后触发的事件
    void btn_log_clicked(); //登录按钮按下后触发的事件
private:
    Ui::Logwidget *ui;
    QString m_username;  // 自己设定的账号
    QString m_password;  // 自己设定的密码
};

#endif // LOGWIDGET_H
