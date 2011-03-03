#include "selectdevices.h"
#include "ui_selectdevices.h"

SelectDevices::SelectDevices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDevices)
{
    ui->setupUi(this);
}

QList<bool> SelectDevices::give()
{
    QList<bool> res;
    res.append( ui->checkBox->isChecked() );
    res.append( ui->checkBox_2->isChecked() );
    res.append( ui->checkBox_3->isChecked() );
    res.append( ui->checkBox_4->isChecked() );
    return res;
}

SelectDevices::~SelectDevices()
{
    delete ui;
}
