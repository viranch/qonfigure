#include <QtGui/QApplication>
#include "qonfigure.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qonfigure w;
    w.show();

    return a.exec();
}
