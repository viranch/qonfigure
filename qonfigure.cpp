#include "qonfigure.h"
#include "mytabpage.h"
#include "ui_qonfigure.h"

Qonfigure::Qonfigure(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Qonfigure)
{
    ui->setupUi(this);

    this->on_actionNew_Device_triggered();
}

Qonfigure::~Qonfigure()
{
    delete ui;
}

void Qonfigure::on_actionNew_Device_triggered()
{
    ui->devices->addTab(new myTabPage(), "New Device");
}

void Qonfigure::removeTab(int index)
{
    ui->devices->removeTab(index);
}
