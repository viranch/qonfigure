#ifndef QONFIGURE_H
#define QONFIGURE_H

#include <QMainWindow>

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

private slots:
    void on_actionNew_Device_triggered();
    void removeTab(int);
};

#endif // QONFIGURE_H
