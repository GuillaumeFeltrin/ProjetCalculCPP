#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QtCharts>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>

#include "addition.h"
#include "multiplication.h"
#include "interactionutilisateur.h"
using namespace std;



MainWindow::MainWindow(QWidget *parent, float resultat, Window * window)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resultat_calcul = resultat;
    abscisseValue = new QLineEdit();
    _window = window;
    _inter = window->getInteractionUtilisateur();
    _exp = window->getInteractionUtilisateur()->getExpression();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderAbscisses_valueChanged(int value)
{
    //mouvement du slider et affichage de la valeur de l'échelle
    QString s = QString::number(value);
    ui->abscisseValue->setText(s);

}

void MainWindow::on_pushButton_clicked()
{
    //récupération des variables
    abscisse = ui->abscisseValue->text().toInt();
    affichage_graphique(_exp);

}

void MainWindow::affichage_graphique()
{
    QLineSeries *series = new QLineSeries();
     Constante terme1(-3);
     Constante terme2(0);

     //création des séries avec notre expression (terme1*x+terme2), en attendant le code du groupe 2
     for (int i=-(abscisse); i<(abscisse)+1 ; i++)
     {
      Constante x(i);
      Multiplication multiplication(&terme1,&x);
      Constante resultat(multiplication.calcul());
      Addition add(&resultat, &terme2);
      series->append(i, add.calcul());
     }

     //affichage des séries
     QChart *chart = new QChart();
     chart->update();
     chart->addSeries(series);
     chart->createDefaultAxes();
     chart->setTitle("line chart example");


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->verticalFrame_2);
    chartView->show();
}

//affiche l'expression passée en paramètre
void MainWindow::affichage_graphique(Expression *exp){

    QLineSeries *series = new QLineSeries();
    string expStr = exp->affichageClassiqueStr();
    QString qstr = QString::fromStdString(expStr);

    //Compte le nombre de variable dans l'expression créée dans le code.
    int nbVariableExp=0;
    char c;
    for(int i=0;i<expStr.size();i++)
       if(isalpha(expStr[i])){
           c = expStr[i];
           nbVariableExp++;
        }
    //si il n'y a pas de variable
    if(nbVariableExp == 0){
        for (int i=-(abscisse); i<(abscisse)+1 ; i++)
        {
            series->append(i, exp->calcul());
        }

    //si il y a une variable
    }else if(nbVariableExp == 1){
        Symboletable *tab = _inter->getSymboleTable();
        QList<QString> elements = _window->getElements();
        for (int i=-(abscisse); i<(abscisse)+1 ; i++)
        {
            cout << c << endl;
            tab->modify(c, i);// on modifie la table
            _inter = new InteractionUtilisateur(&elements, tab);
            exp = _inter->getExpression();
            cout << exp->calcul() << endl;
            series->append(i,exp->calcul());
        }

    }


    //affichage des séries
    QChart *chart = new QChart();
    chart->update();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(QString::fromStdString(expStr));


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->verticalFrame_2);
    chartView->show();



}
