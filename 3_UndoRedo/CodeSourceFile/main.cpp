#include <QApplication>
#include<absundoableedit.h>
#include<undomanager.h>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    UndoManager* undomng=new UndoManager();
    w.addUndoListener(undomng);
    w.show();

    return a.exec();
}
