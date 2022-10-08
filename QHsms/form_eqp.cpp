#include "form_eqp.h"
#include "ui_form_eqp.h"

Form_EQP::Form_EQP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_EQP)
{
    ui->setupUi(this);
    connect(ui->pushButtonConnect, &QPushButton::clicked, this, &Form_EQP::connectToEQP);

}

Form_EQP::~Form_EQP()
{
    delete ui;
}

void Form_EQP::connectToEQP()
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
