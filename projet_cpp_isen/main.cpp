#include <QCoreApplication>
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "iostream"
#include "window.h"
#include "mainwindow.h"


using namespace std;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 

    // GROUPE 5
    MainWindow M;

    // GROUPE 2 & 1
        // Objet de la class Window qui hérite de QWidget
        Window window;
        // exécution application
        window.show();

    
    return app.exec();
}
