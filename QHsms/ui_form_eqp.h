/********************************************************************************
** Form generated from reading UI file 'form_eqp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_EQP_H
#define UI_FORM_EQP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_EQP
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonConnect;
    QTextEdit *textEditLog;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditOPERATORID;
    QLabel *label_5;
    QLineEdit *lineEditPASSWORD;
    QSpacerItem *horizontalSpacer_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonLinkTest;
    QPushButton *pushButtonDeselectReq;
    QPushButton *pushButtonSeparateReq;
    QPushButton *pushButtonS1F1;
    QPushButton *pushButtonS1F5;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Form_EQP)
    {
        if (Form_EQP->objectName().isEmpty())
            Form_EQP->setObjectName(QString::fromUtf8("Form_EQP"));
        Form_EQP->resize(497, 519);
        layoutWidget = new QWidget(Form_EQP);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 469, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditIP = new QLineEdit(layoutWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        horizontalLayout->addWidget(lineEditIP);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditPort = new QLineEdit(layoutWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        horizontalLayout->addWidget(lineEditPort);

        pushButtonConnect = new QPushButton(layoutWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        horizontalLayout->addWidget(pushButtonConnect);

        textEditLog = new QTextEdit(Form_EQP);
        textEditLog->setObjectName(QString::fromUtf8("textEditLog"));
        textEditLog->setGeometry(QRect(10, 120, 471, 380));
        layoutWidget_2 = new QWidget(Form_EQP);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 90, 471, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEditOPERATORID = new QLineEdit(layoutWidget_2);
        lineEditOPERATORID->setObjectName(QString::fromUtf8("lineEditOPERATORID"));
        lineEditOPERATORID->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(lineEditOPERATORID);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEditPASSWORD = new QLineEdit(layoutWidget_2);
        lineEditPASSWORD->setObjectName(QString::fromUtf8("lineEditPASSWORD"));
        lineEditPASSWORD->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(lineEditPASSWORD);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        layoutWidget_3 = new QWidget(Form_EQP);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 50, 471, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonLinkTest = new QPushButton(layoutWidget_3);
        pushButtonLinkTest->setObjectName(QString::fromUtf8("pushButtonLinkTest"));

        horizontalLayout_3->addWidget(pushButtonLinkTest);

        pushButtonDeselectReq = new QPushButton(layoutWidget_3);
        pushButtonDeselectReq->setObjectName(QString::fromUtf8("pushButtonDeselectReq"));

        horizontalLayout_3->addWidget(pushButtonDeselectReq);

        pushButtonSeparateReq = new QPushButton(layoutWidget_3);
        pushButtonSeparateReq->setObjectName(QString::fromUtf8("pushButtonSeparateReq"));

        horizontalLayout_3->addWidget(pushButtonSeparateReq);

        pushButtonS1F1 = new QPushButton(layoutWidget_3);
        pushButtonS1F1->setObjectName(QString::fromUtf8("pushButtonS1F1"));

        horizontalLayout_3->addWidget(pushButtonS1F1);

        pushButtonS1F5 = new QPushButton(layoutWidget_3);
        pushButtonS1F5->setObjectName(QString::fromUtf8("pushButtonS1F5"));

        horizontalLayout_3->addWidget(pushButtonS1F5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        retranslateUi(Form_EQP);

        QMetaObject::connectSlotsByName(Form_EQP);
    } // setupUi

    void retranslateUi(QWidget *Form_EQP)
    {
        Form_EQP->setWindowTitle(QApplication::translate("Form_EQP", "Form", nullptr));
        label->setText(QApplication::translate("Form_EQP", "IP \345\234\260\345\235\200\357\274\232", nullptr));
        lineEditIP->setText(QApplication::translate("Form_EQP", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("Form_EQP", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        lineEditPort->setText(QApplication::translate("Form_EQP", "5000", nullptr));
        pushButtonConnect->setText(QApplication::translate("Form_EQP", "Connect", nullptr));
        label_4->setText(QApplication::translate("Form_EQP", "OPERATORID", nullptr));
        lineEditOPERATORID->setText(QApplication::translate("Form_EQP", "30145149", nullptr));
        label_5->setText(QApplication::translate("Form_EQP", "PASSWORD", nullptr));
        lineEditPASSWORD->setText(QApplication::translate("Form_EQP", "BOEHF", nullptr));
        pushButtonLinkTest->setText(QApplication::translate("Form_EQP", "LinkTest", nullptr));
        pushButtonDeselectReq->setText(QApplication::translate("Form_EQP", "DeselectReq", nullptr));
        pushButtonSeparateReq->setText(QApplication::translate("Form_EQP", "SeparateReq", nullptr));
        pushButtonS1F1->setText(QApplication::translate("Form_EQP", "AreYouHere", nullptr));
        pushButtonS1F5->setText(QApplication::translate("Form_EQP", "S1F5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_EQP: public Ui_Form_EQP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_EQP_H
