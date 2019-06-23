#include "nesca_3.h"
#include <QApplication>
#include <qfontdatabase.h>
#include <QMessageBox>
#include <qpixmap.h>
#include "Utils.h"
#include "externData.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool isWM = false;


    QStringList list;
    list << "small_font.ttf";
    int fontID(-1);
    bool fontWarningShown(false);
    for (QStringList::const_iterator constIterator = list.constBegin(); constIterator != list.constEnd(); ++constIterator) {
        QFile res(":/nesca_3/" + *constIterator);
        if (res.open(QIODevice::ReadOnly) == false) {
            if (fontWarningShown == false) {
                fontWarningShown = true;
            }
        }
        else {
            fontID = QFontDatabase::addApplicationFontFromData(res.readAll());
            if (fontID == -1 && fontWarningShown == false) {
                fontWarningShown = true;
            }
        }
    }

    nesca_3 *gui = new nesca_3(isWM, 0);
    gui->showNormal();
    return a.exec();
}



