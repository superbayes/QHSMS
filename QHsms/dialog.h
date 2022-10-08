#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPair>
#include "B3HsmsHostSim.h"
#include "B3HsmsEQP.h"
#include <QDebug>
struct PANELINFO
{
    QString RTCODE;
    QString EQPID;
    QString UNITID;
    QString PNLID;
    QString MODULEID;
    QString FGCODE;
    QString WORKORDER;
    QString PNLJUDGE;
    QString PNLGRADE;
    QString REASONCODE;
    QString CURRENTSTEP;
    QString GROUPID;
    QString INSPFILENAME;
    QString INSPFILEPATH;
    QString REVISION;
    QString CELLGRADE;
    QString WOGRADE;
    QString OPERATORID;
    QString AUTHORITYCODE;
};

namespace Ui {
class Dialog;
}

//QDialog
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void log(QString str);
private slots:
    void connected();
    void disconnected();
    void connectToEQP();

    void on_pushButtonDeselectReq_clicked();

private:
    Ui::Dialog *ui;
    PANELINFO m_panelInfo;
    B3HsmsHostSim m_host;
    B3HsmsEQP m_eqp;

};

#endif // DIALOG_H
