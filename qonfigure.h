#ifndef QONFIGURE_H
#define QONFIGURE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include "mytabpage.h"
#include "selectdevices.h"

namespace Ui {
    class Qonfigure;
}

class Qonfigure : public QMainWindow
{
    Q_OBJECT

public:
    explicit Qonfigure(QWidget *parent = 0);
    ~Qonfigure();

private:
    Ui::Qonfigure *ui;
    QList<myTabPage*> m_pages;
    QString filename;
    SelectDevices* sd;

private slots:
    void on_actionSave_triggered();
};

#endif // QONFIGURE_H
