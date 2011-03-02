#ifndef MYTABPAGE_H
#define MYTABPAGE_H

#include <QWidget>
#include <QLineEdit>
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
    field* getFields() { return m_fields; }
    int getFieldSize() { return m_fields_size; }
    value* getValues() { return m_values; }
    int getValueSize() { return m_values_size; }
    ~myTabPage();

private:
    Ui::myTabPage *ui;
    field *m_fields;
    int m_fields_size;
    value *m_values;
    int m_values_size;
};

#endif // MYTABPAGE_H
