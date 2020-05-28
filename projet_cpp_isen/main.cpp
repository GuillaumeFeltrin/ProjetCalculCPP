#include <QCoreApplication>
#include <QApplication>
#include <QtWidgets>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "mainwindow.h"
#include "iostream"
using namespace std;

//Main
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow M;

    return app.exec();
}
