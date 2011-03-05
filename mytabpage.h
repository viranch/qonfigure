#ifndef MYTABPAGE_H
#define MYTABPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QMap>

namespace Ui {
    class myTabPage;
}

struct timerField {
    QString time;
    QString high;
    QString low;
};

class myTabPage : public QWidget
{
    Q_OBJECT

public:
    explicit myTabPage(QWidget *parent = 0);

    QString getDevice_ID();
    QString getModel();

    QMap<QString, QString> getCommonBox();
    QMap<QString, timerField*> getTimerBox();
    QMap<QString, QString> getMiscBox();

    void on_actionPrevGroup_triggered();
    void on_actionNextGroup_triggered();

    ~myTabPage();

private:
    Ui::myTabPage *ui;
    QMap<QString, QString> commonBox;
    QMap<QString, timerField*> timerBox;
    QMap<QString, QString> miscBox;

public slots:
    void focusWidget(int index);
};

#endif // MYTABPAGE_H
