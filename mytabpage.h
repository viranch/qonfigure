#ifndef MYTABPAGE_H
#define MYTABPAGE_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QComboBox>

namespace Ui {
    class myTabPage;
}

struct field {
    QString label;
    QDoubleSpinBox *time;
    QComboBox *unit;
    QLineEdit *hex;
};

struct value {
    QString label;
    QLineEdit *value;
};

class myTabPage : public QWidget
{
    Q_OBJECT

public:
    explicit myTabPage(QWidget *parent = 0);
    QString getDevice_ID();
    QString getModel();
    QString getCommonSignal();
    QString getCOMMON_SIGNAL_LENGTH();
    QString getCMD_SIGNAL_LENGTH();
    field getField(int i);
    value getValue(int i);
    ~myTabPage();

private:
    Ui::myTabPage *ui;
    field *m_fields;
    value *m_values;
};

#endif // MYTABPAGE_H
