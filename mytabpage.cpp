#include "mytabpage.h"
#include "ui_mytabpage.h"

myTabPage::myTabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTabPage)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(0);
    focusWidget(0);
}

QString myTabPage::getDevice_ID() { return ui->Device_ID->text().trimmed().simplified(); }

QString myTabPage::getModel() { return ui->Model->text().trimmed().simplified(); }

QMap<QString, QString> myTabPage::getCommonBox()
{
    commonBox["CommonSignal"] = ui->CommonSignal->text().trimmed();
    commonBox["xvalue4"] = ui->xvalue4->text().trimmed();
    commonBox["xvalue5"] = ui->xvalue5->text().trimmed();
    commonBox["yvalue4"] = ui->yvalue4->text().trimmed();
    commonBox["yvalue5"] = ui->yvalue5->text().trimmed();
    commonBox["COMMON_SIGNAL_LENGTH"] = ui->COMMON_SIGNAL_LENGTH->text().trimmed();
    commonBox["CMD_SIGNAL_LENGTH"] = ui->CMD_SIGNAL_LENGTH->text().trimmed();

    return commonBox;
}

QString varname(double value, int unit)
{
    QString var = QString("%1").arg( (int)value );
    if (value != (int)value) {
        var += QString("_%1").arg( (value-(int)value)*10 );
    }
    var += unit ? "MICROSEC" : "MILLISEC";

    return var;
}

QMap<QString, timerField*> myTabPage::getTimerBox()
{
    timerBox["burstOn"] = new timerField;
    timerBox["burstOn"]->time = varname (ui->burstOnTime->value(), ui->burstOnUnit->currentIndex());
    timerBox["burstOn"]->high = ui->burstOnHigh->text().trimmed().toLower();
    timerBox["burstOn"]->low = ui->burstOnLow->text().trimmed().toLower();

    timerBox["burstOff"] = new timerField;
    timerBox["burstOff"]->time = varname (ui->burstOffTime->value(), ui->burstOffUnit->currentIndex());
    timerBox["burstOff"]->high = ui->burstOffHigh->text().trimmed().toLower();
    timerBox["burstOff"]->low = ui->burstOffLow->text().trimmed().toLower();

    timerBox["onPeriod"] = new timerField;
    timerBox["onPeriod"]->time = varname (ui->onPeriodTime->value(), ui->onPeriodUnit->currentIndex());
    timerBox["onPeriod"]->high = ui->onPeriodHigh->text().trimmed().toLower();
    timerBox["onPeriod"]->low = ui->onPeriodLow->text().trimmed().toLower();

    timerBox["offPeriodZero"] = new timerField;
    timerBox["offPeriodZero"]->time = varname (ui->offPeriodZeroTime->value(), ui->offPeriodZeroUnit->currentIndex());
    timerBox["offPeriodZero"]->high = ui->offPeriodZeroHigh->text().trimmed().toLower();
    timerBox["offPeriodZero"]->low = ui->offPeriodZeroLow->text().trimmed().toLower();

    timerBox["offPeriodOne"] = new timerField;
    timerBox["offPeriodOne"]->time = varname (ui->offPeriodOneTime->value(), ui->offPeriodOneUnit->currentIndex());
    timerBox["offPeriodOne"]->high = ui->offPeriodOneHigh->text().trimmed().toLower();
    timerBox["offPeriodOne"]->low = ui->offPeriodOneLow->text().trimmed().toLower();

    timerBox["WRONGBIT"] = new timerField;
    timerBox["WRONGBIT"]->time = varname (ui->WRONGBITTime->value(), ui->WRONGBITUnit->currentIndex());
    timerBox["WRONGBIT"]->high = ui->WRONGBITHigh->text().trimmed().toLower();
    timerBox["WRONGBIT"]->low = ui->WRONGBITLow->text().trimmed().toLower();

    timerBox["FLIPBIT"] = new timerField;
    timerBox["FLIPBIT"]->time = varname (ui->FLIPBITTime->value(), ui->FLIPBITUnit->currentIndex());
    timerBox["FLIPBIT"]->high = ui->FLIPBITHigh->text().trimmed().toLower();
    timerBox["FLIPBIT"]->low = ui->FLIPBITLow->text().trimmed().toLower();

    return timerBox;
}

QMap<QString, QString> myTabPage::getMiscBox()
{
    miscBox["REPEAT_XP"] = ui->REPEAT_XP->text().trimmed();
    miscBox["REPEAT_XM"] = ui->REPEAT_XM->text().trimmed();
    miscBox["REPEAT_YP"] = ui->REPEAT_YP->text().trimmed();
    miscBox["REPEAT_YM"] = ui->REPEAT_YM->text().trimmed();
    miscBox["FLIP_POSITION_IN_DATA1"] = ui->FLIP_POSITION_IN_DATA1->text().trimmed();
    miscBox["FLIP_POSITION_IN_DATA2"] = ui->FLIP_POSITION_IN_DATA2->text().trimmed();
    miscBox["FLIP_POSITION_IN_DATA3"] = ui->FLIP_POSITION_IN_DATA3->text().trimmed();
    miscBox["WRONG_POSITION_IN_DATA1"] = ui->WRONG_POSITION_IN_DATA1->text().trimmed();

    return miscBox;
}

void myTabPage::on_actionPrevGroup_triggered()
{
    int curr = ui->toolBox->currentIndex();
    if (curr)
        ui->toolBox->setCurrentIndex(curr-1);
    else
        ui->toolBox->setCurrentIndex(2);
}

void myTabPage::on_actionNextGroup_triggered()
{
    ui->toolBox->setCurrentIndex( (ui->toolBox->currentIndex()+1)%3 );
}

void myTabPage::focusWidget(int index)
{
    switch (index) {
    case 0:
        ui->Device_ID->setFocus();
        break;
    case 1:
        ui->burstOnTime->setFocus();
        break;
    case 2:
        ui->REPEAT_XP->setFocus();
        break;
    default:
        break;
    }

}

myTabPage::~myTabPage()
{
    delete ui;
}
