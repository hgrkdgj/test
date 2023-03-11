/********************************************************************************
** Form generated from reading UI file 'logwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWIDGET_H
#define UI_LOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logwidget
{
public:
    QPushButton *enter;
    QPushButton *clear;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *accountant;
    QLineEdit *password;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *check_name;
    QCheckBox *checkBox_pw;

    void setupUi(QWidget *Logwidget)
    {
        if (Logwidget->objectName().isEmpty())
            Logwidget->setObjectName(QString::fromUtf8("Logwidget"));
        Logwidget->resize(657, 299);
        enter = new QPushButton(Logwidget);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setGeometry(QRect(190, 240, 93, 28));
        clear = new QPushButton(Logwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(320, 240, 93, 28));
        groupBox = new QGroupBox(Logwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 20, 471, 201));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(150, 60, 151, 97));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        accountant = new QLineEdit(verticalLayoutWidget);
        accountant->setObjectName(QString::fromUtf8("accountant"));

        verticalLayout->addWidget(accountant);

        password = new QLineEdit(verticalLayoutWidget);
        password->setObjectName(QString::fromUtf8("password"));

        verticalLayout->addWidget(password);

        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(70, 70, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        check_name = new QCheckBox(groupBox);
        check_name->setObjectName(QString::fromUtf8("check_name"));
        check_name->setGeometry(QRect(110, 170, 91, 19));
        checkBox_pw = new QCheckBox(groupBox);
        checkBox_pw->setObjectName(QString::fromUtf8("checkBox_pw"));
        checkBox_pw->setGeometry(QRect(210, 170, 91, 19));

        retranslateUi(Logwidget);

        QMetaObject::connectSlotsByName(Logwidget);
    } // setupUi

    void retranslateUi(QWidget *Logwidget)
    {
        Logwidget->setWindowTitle(QApplication::translate("Logwidget", "Form", nullptr));
        enter->setText(QApplication::translate("Logwidget", "\347\231\273\345\275\225", nullptr));
        clear->setText(QApplication::translate("Logwidget", "\346\270\205\347\251\272", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Logwidget", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Logwidget", "\345\257\206\347\240\201", nullptr));
        check_name->setText(QApplication::translate("Logwidget", "\350\256\260\344\275\217\350\264\246\345\217\267", nullptr));
        checkBox_pw->setText(QApplication::translate("Logwidget", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Logwidget: public Ui_Logwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
