#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QtCharts>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>

#include "addition.h"
#include "multiplication.h"

using namespace std;



MainWindow::MainWindow(QWidget *parent, float resultat, InteractionUtilisateur * inter)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->parametres->setFont(QFont("Arial", 10));
    resultat_calcul = resultat;
    abscisseValue = new QLineEdit();
    _inter = inter;
    _exp = inter->getExpression();

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

    //Compte le nombre de variable dans l'expression créée dans le code.
    int nbVariableExp=0;
    for(int i=0;i<expStr.size();i++)
       if(isalpha(expStr[i])) nbVariableExp++;

    if(nbVariableExp == 0){
        for (int i=-(abscisse); i<(abscisse)+1 ; i++)
        {
            series->append(i, exp->calcul());
        }
    }else if(nbVariableExp == 1){
        Variable *var = new Variable();
        Symboletable *tab = _inter->getSymboleTable();
        tab->find('x');
        for (int i=-(abscisse); i<(abscisse)+1 ; i++)
        {
            var->setValeur(i);
            cout << "[" << var->calcul()<<","<< exp->calcul()*var->calcul() << "]" <<endl;
            series->append(var->calcul(),exp->calcul());
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
