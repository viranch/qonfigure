#include "mytabpage.h"
#include "ui_mytabpage.h"

myTabPage::myTabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTabPage)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(0);
}

QString myTabPage::getDevice_ID() { return ui->Device_ID->text(); }

QString myTabPage::getModel() { return ui->Model->text(); }

QMap<QString, QString> myTabPage::getCommonBox()
{
    commonBox["CommonSignal"] = ui->CommonSignal->text();
    commonBox["xvalue4"] = ui->xvalue4->text();
    commonBox["xvalue5"] = ui->xvalue5->text();
    commonBox["yvalue4"] = ui->yvalue4->text();
    commonBox["yvalue5"] = ui->yvalue5->text();
    commonBox["COMMON_SIGNAL_LENGTH"] = ui->COMMON_SIGNAL_LENGTH->text();
    commonBox["CMD_SIGNAL_LENGTH"] = ui->CMD_SIGNAL_LENGTH->text();

    return commonBox;
}

QMap<QString, timerField> myTabPage::getTimerBox()
{
    timerField* tmp = new timerField[7];

    tmp[0].time = ui->burstOnTime->value();
    tmp[0].unit = ui->burstOnUnit->currentIndex()==0 ? "MILLISEC":"MICROSEC";
    tmp[0].high = ui->burstOnHigh->text();
    tmp[0].low = ui->burstOnLow->text();
    timerBox["burstOn"] = tmp[0];

    tmp[1].time = ui->burstOffTime->value();
    tmp[1].unit = ui->burstOffUnit->currentIndex()==0 ? "MILLISEC":"MICROSEC";
    tmp[1].high = ui->burstOffHigh->text();
    tmp[1].low = ui->burstOffLow->text();
    timerBox["burstOff"] = tmp[1];

    tmp[2].time = ui->onPeriodTime->value();
    tmp[2].unit = ui->onPeriodUnit->currentIndex()==0 ? "MILLISEC":"MICROSEC";
    tmp[2].high = ui->onPeriodHigh->text();
    tmp[2].low = ui->onPeriodLow->text();
    timerBox["onPeriod"] = tmp[2];

    tmp[3].time = ui->offPeriodZeroTime->value();
    tmp[3].unit = ui->offPeriodZeroUnit->currentIndex()==0 ? "MILLISEC":"MICROSEC";
    tmp[3].high = ui->offPeriodZeroHigh->text();
    tmp[3].low = ui->offPeriodZeroLow->text();
    timerBox["offPeriodZero"] = tmp[3];

    tmp[4].time = ui->offPeriodOneTime->value();
    tmp[4].unit = ui->offPeriodOneUnit->currentIndex()==0 ? "MILLISEC":"MICROSEC";
    tmp[4].high = ui->offPeriodOneHigh->text();
    tmp[4].low = ui->offPeriodOneLow->text();
    timerBox["offPeriodOne"] = tmp[4];

    tmp[5].time = ui->WRONGBITTime->value();
    tmp[5].unit = ui->WRONGBITUnit->currentIndex()==0 ? "MILLISEC":"MICROSEC";
    tmp[5].high = ui->WRONGBITHigh->text();
    tmp[5].low = ui->WRONGBITLow->text();
    timerBox["WRONGBIT"] = tmp[5];

    tmp[6].time = ui->FLIPBITTime->value();
    tmp[6].unit = ui->FLIPBITUnit->currentIndex()==0 ? "MILLISEC":"MICROSEC";
    tmp[6].high = ui->FLIPBITHigh->text();
    tmp[6].low = ui->FLIPBITLow->text();
    timerBox["FLIPBIT"] = tmp[6];

    return timerBox;
}

QMap<QString, QString> myTabPage::getMiscBox()
{
    miscBox["REPEAT_XP"] = ui->REPEAT_XP->text();
    miscBox["REPEAT_XM"] = ui->REPEAT_XM->text();
    miscBox["REPEAT_YP"] = ui->REPEAT_YP->text();
    miscBox["REPEAT_YM"] = ui->REPEAT_YM->text();
    miscBox["FLIP_POSITION_IN_DATA1"] = ui->FLIP_POSITION_IN_DATA1->text();
    miscBox["FLIP_POSITION_IN_DATA2"] = ui->FLIP_POSITION_IN_DATA2->text();
    miscBox["FLIP_POSITION_IN_DATA3"] = ui->FLIP_POSITION_IN_DATA3->text();
    miscBox["WRONG_POSITION_IN_DATA1"] = ui->WRONG_POSITION_IN_DATA1->text();

    return miscBox;
}

myTabPage::~myTabPage()
{
    delete ui;
}
