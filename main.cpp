#include "widget.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(320, 240);
    w.show();
    w.setWindowTitle("Child widget");
    QPushButton *button = new QPushButton("Press me", &w);
    button->move(100, 100);
    button->show();
    return a.exec();
}
