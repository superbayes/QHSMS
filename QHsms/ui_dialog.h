/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonConnect;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonLinkTest;
    QPushButton *pushButtonDeselectReq;
    QPushButton *pushButtonSeparateReq;
    QPushButton *pushButtonS1F1;
    QPushButton *pushButtonS1F5;
    QPushButton *pushButtonS3F6;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditOPERATORID;
    QLabel *label_5;
    QLineEdit *lineEditPASSWORD;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEditLog;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(774, 521);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditIP = new QLineEdit(Dialog);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        horizontalLayout->addWidget(lineEditIP);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditPort = new QLineEdit(Dialog);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        horizontalLayout->addWidget(lineEditPort);

        pushButtonConnect = new QPushButton(Dialog);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        horizontalLayout->addWidget(pushButtonConnect);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonLinkTest = new QPushButton(Dialog);
        pushButtonLinkTest->setObjectName(QString::fromUtf8("pushButtonLinkTest"));

        horizontalLayout_3->addWidget(pushButtonLinkTest);

        pushButtonDeselectReq = new QPushButton(Dialog);
        pushButtonDeselectReq->setObjectName(QString::fromUtf8("pushButtonDeselectReq"));

        horizontalLayout_3->addWidget(pushButtonDeselectReq);

        pushButtonSeparateReq = new QPushButton(Dialog);
        pushButtonSeparateReq->setObjectName(QString::fromUtf8("pushButtonSeparateReq"));

        horizontalLayout_3->addWidget(pushButtonSeparateReq);

        pushButtonS1F1 = new QPushButton(Dialog);
        pushButtonS1F1->setObjectName(QString::fromUtf8("pushButtonS1F1"));

        horizontalLayout_3->addWidget(pushButtonS1F1);

        pushButtonS1F5 = new QPushButton(Dialog);
        pushButtonS1F5->setObjectName(QString::fromUtf8("pushButtonS1F5"));

        horizontalLayout_3->addWidget(pushButtonS1F5);

        pushButtonS3F6 = new QPushButton(Dialog);
        pushButtonS3F6->setObjectName(QString::fromUtf8("pushButtonS3F6"));

        horizontalLayout_3->addWidget(pushButtonS3F6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEditOPERATORID = new QLineEdit(Dialog);
        lineEditOPERATORID->setObjectName(QString::fromUtf8("lineEditOPERATORID"));
        lineEditOPERATORID->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(lineEditOPERATORID);

        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEditPASSWORD = new QLineEdit(Dialog);
        lineEditPASSWORD->setObjectName(QString::fromUtf8("lineEditPASSWORD"));
        lineEditPASSWORD->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(lineEditPASSWORD);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        textEditLog = new QTextEdit(Dialog);
        textEditLog->setObjectName(QString::fromUtf8("textEditLog"));

        verticalLayout->addWidget(textEditLog);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog", "IP \345\234\260\345\235\200\357\274\232", nullptr));
        lineEditIP->setText(QApplication::translate("Dialog", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        lineEditPort->setText(QApplication::translate("Dialog", "5000", nullptr));
        pushButtonConnect->setText(QApplication::translate("Dialog", "Connect", nullptr));
        pushButtonLinkTest->setText(QApplication::translate("Dialog", "LinkTest", nullptr));
        pushButtonDeselectReq->setText(QApplication::translate("Dialog", "DeselectReq", nullptr));
        pushButtonSeparateReq->setText(QApplication::translate("Dialog", "SeparateReq", nullptr));
        pushButtonS1F1->setText(QApplication::translate("Dialog", "AreYouHere", nullptr));
        pushButtonS1F5->setText(QApplication::translate("Dialog", "S1F5", nullptr));
        pushButtonS3F6->setText(QApplication::translate("Dialog", "S3F6", nullptr));
        label_4->setText(QApplication::translate("Dialog", "OPERATORID", nullptr));
        lineEditOPERATORID->setText(QApplication::translate("Dialog", "30145149", nullptr));
        label_5->setText(QApplication::translate("Dialog", "PASSWORD", nullptr));
        lineEditPASSWORD->setText(QApplication::translate("Dialog", "BOEHF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
