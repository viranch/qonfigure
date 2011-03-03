#ifndef SELECTDEVICES_H
#define SELECTDEVICES_H

#include <QDialog>
#include <QList>

namespace Ui {
    class SelectDevices;
}

class SelectDevices : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDevices(QWidget *parent = 0);
    QList<bool> give();
    ~SelectDevices();

private:
    Ui::SelectDevices *ui;
};

#endif // SELECTDEVICES_H

