#ifndef FORM_EQP_H
#define FORM_EQP_H

#include <QWidget>
#include <QPair>
#include "B3HsmsHostSim.h"
#include "B3HsmsEQP.h"
#include "dialog.h"
#include <QDebug>

namespace Ui {
class Form_EQP;
}

class Form_EQP : public QWidget
{
    Q_OBJECT

public:
    explicit Form_EQP(QWidget *parent = nullptr);
    ~Form_EQP();

private slots:
//    void connected();
//    void disconnected();
    void connectToEQP();

private:
    PANELINFO m_panelInfo;
    B3HsmsHostSim m_host;
    B3HsmsEQP m_eqp;
private:
    Ui::Form_EQP *ui;
};

#endif // FORM_EQP_H
