#include "mytabpage.h"
#include "ui_mytabpage.h"

myTabPage::myTabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTabPage)
{
    ui->setupUi(this);

    QStringList labels;
    labels << "burstOnHigh" << "burstOffHigh" << "onPeriodHigh" << "offPeriodZeroHigh" << "offPeriodOneHigh" << "burstOnLow"
     << "burstOffLow" << "onPeriodLow" << "offPeriodZeroLow" << "offPeriodOneLow" << "WRONGBIT_HIGH" << "WRONGBIT_LOW"
     << "FLIPBIT_HIGH" << "FLIPBIT_LOW";

    this->m_fields = new field[labels.size()];
    QGridLayout *grid = new QGridLayout;

    for (int i=0; i<labels.size(); i++) {
        m_fields[i].label = labels.at(i);
        grid->addWidget( new QLabel (labels.at(i) ), i, 0 );
        this->m_fields[i].time = new QDoubleSpinBox;
        this->m_fields[i].time->setDecimals(1);
        this->m_fields[i].time->setMaximum(10000.0);
        grid->addWidget(this->m_fields[i].time, i, 1);
        this->m_fields[i].unit = new QComboBox;
        this->m_fields[i].unit->addItem("ms", "MILLISEC");
        this->m_fields[i].unit->addItem("us", "MICROSEC");
        grid->addWidget(this->m_fields[i].unit, i, 2);
        this->m_fields[i].hex = new QLineEdit;
        grid->addWidget(this->m_fields[i].hex, i, 3);
    }
    ui->timesBox->setLayout(grid);
    m_fields_size = labels.size();

    QStringList vlabels;
    vlabels << "xvalue4" << "xvalue5" << "yvalue4" << "yvalue5" << "REPEAT_XP" << "REPEAT_XM" << "REPEAT_YP" <<
     "REPEAT_YM" << "FLIP_POSITION_IN_DATA1" << "FLIP_POSITION_IN_DATA2" << "FLIP_POSITION_IN_DATA3" <<
     "WRONG_POSITION_IN_DATA1";

    m_values = new value[vlabels.size()];
    grid = new QGridLayout;
    for (int i=0; i<vlabels.size(); i++) {
        m_values[i].label = vlabels.at(i);
        grid->addWidget( new QLabel (vlabels.at(i)), i, 0 );
        m_values[i].value = new QLineEdit;
        grid->addWidget(m_values[i].value, i, 1);
    }
    ui->miscBox->setLayout(grid);
    m_values_size = vlabels.size();
}

QString myTabPage::getDevice_ID() { return ui->Device_ID->text(); }

QString myTabPage::getModel() { return ui->Model->text(); }

QString myTabPage::getCommonSignal() { return ui->CommonSignal->text(); }

QString myTabPage::getCOMMON_SIGNAL_LENGTH() { return ui->COMMON_SIGNAL_LENGTH->text(); }

QString myTabPage::getCMD_SIGNAL_LENGTH() { return ui->CMD_SIGNAL_LENGTH->text(); }

myTabPage::~myTabPage()
{
    delete ui;
}
