#include "window.h"
#include "mainwindow.h"

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Objet de la class Window qui hérite de QWidget
   Window window;
    //MainWindow w;

    window.show();
    //w.show();
    return app.exec();
}
