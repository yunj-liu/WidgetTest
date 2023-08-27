#include "widget.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QLabel *queryLabel = new QLabel("Query:");
    QLineEdit *queryEdit = new QLineEdit();
    QTableView *resultView = new QTableView();

    QHBoxLayout *queryLayout = new QHBoxLayout();
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);
    w.setLayout(mainLayout);

    // Set up the model and configure the view...
    QStandardItemModel model;
    model.setHorizontalHeaderLabels({"Name", "Office"});
    const QStringList rows[] = {
        QStringList{ QStringLiteral("Verne Nilsen"), QStringLiteral("123") },
        QStringList{ QStringLiteral("Carlos Tang"), QStringLiteral("77") },
        QStringList{ QStringLiteral("Bronwyn Hawcroft"), QStringLiteral("119") },
        QStringList{ QStringLiteral("Alessandro Hanssen"), QStringLiteral("32") },
        QStringList{ QStringLiteral("Andrew John Bakken"), QStringLiteral("54") },
        QStringList{ QStringLiteral("Vanessa Weatherley"), QStringLiteral("85") },
        QStringList{ QStringLiteral("Rebecca Dickens"), QStringLiteral("17") },
        QStringList{ QStringLiteral("David Bradley"), QStringLiteral("42") },
        QStringList{ QStringLiteral("Knut Walters"), QStringLiteral("25") },
        QStringList{ QStringLiteral("Andrea Jones"), QStringLiteral("34") }
    };

    QList<QStandardItem *> items;
    for(const QStringList &row:rows){ //rows is array like QList<QString>[10], row fetch every member of rows. every member is a QList<QString>, include 2 QString items, like "Verne Nilsen", "123"
        items.clear();
        for(const QString &text:row)  // row is a QList<QString>, text fetch every item of row
            items.append(new QStandardItem(text)); // assemble one items from two QString
        model.appendRow(items);
    }
    resultView->setModel(&model);
    //resultView->verticalHeader()->hide();  // not hide will display row's number in fronter
    resultView->horizontalHeader()->setStretchLastSection(true);

    w.setWindowTitle("Nested layouts");
    w.show();
    return a.exec();
}
