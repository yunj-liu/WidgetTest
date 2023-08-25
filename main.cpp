#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(320, 240);
    w.show();
    //w.setWindowTitle(
    //    QApplication::translate("toplevel", "Top-level widget"));
    // QT_VERSION_MAJOR in the qconfig.h
    w.setWindowTitle(QString::number(QT_VERSION_MAJOR)+ "-" + QT_VERSION_STR);
    return a.exec();
}
