#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    qDebug()<<"==================Dialog::Dialog";
    connect(ui->pushButtonConnect, &QPushButton::clicked, this, &Dialog::connectToEQP);
    connect(ui->pushButtonLinkTest, &QPushButton::clicked, &m_host, &HsmsHost::sendLinkTestReq);
    connect(ui->pushButtonDeselectReq, &QPushButton::clicked, &m_host, &HsmsHost::sendDeselectReq);
    connect(ui->pushButtonSeparateReq, &QPushButton::clicked, &m_host, &HsmsHost::sendSeparateReq);
    connect(&m_host, SLOT(connected()), this, SLOT(connectedToEQP()));
    connect(&m_host, SLOT(disconnected()), this, SLOT(disconnectedFromEQP()));
    connect(ui->pushButtonS1F1, &QPushButton::clicked, &m_host, &HsmsHost::sendS1F1);
    connect(ui->pushButtonS1F5, SIGNAL(clicked()), &m_host, SLOT(sendS1F5()));
    connect(ui->pushButtonS3F6,&QPushButton::clicked,[&]{
        QString CEID = "1111111111111111";
        QString EQUIPMENTID = "eqp11111111";
        QString UNITID = "UNITID11";
        QString PRODUCTID = "PRODUCTID1111";
        QString RECIPEID = "RECIPEID1111";
        this->m_host.sendS6F3(CEID,EQUIPMENTID,UNITID,PRODUCTID,RECIPEID);
        //this->m_eqp.sendS6F207(CEID);
        qDebug()<<"ui->pushButtonS3F6";
        return;
    });
//    connect(ui->pushButtonPanelID, &QPushButton::clicked, this, &Dialog::sendPanelID);
//    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &Dialog::login);
}

void Dialog::connected()
{
    ui->pushButtonConnect->setText("Disconnect");
}

void Dialog::disconnected()
{
    ui->pushButtonConnect->setText("Connect");
}



void Dialog::connectToEQP()
{
    QString name = ui->pushButtonConnect->text();
    if(name == "Connect")
    {
        QString ip = ui->lineEditIP->text();
        uint16_t port = ui->lineEditPort->text().toInt();
        m_host.connectToEQP(ip, port);

    }
    else
    {
        m_host.disconnectFromEQP();
        ui->pushButtonConnect->setText("Connect");
    }

}

void Dialog::log(QString str)
{
    ui->textEditLog->append(str);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButtonDeselectReq_clicked()
{

}
