#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QtCharts>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <iostream>
#include "addition.h"
#include "multiplication.h"
#include <list>
#include <sstream>

using namespace std;

//Cette fonction permet de tracer une fonction affine
QLineSeries * createAffineFunction(float pa, float pb){
    QLineSeries *series = new QLineSeries();
    Constante a(pa);
    Constante b(pb);
    for(int i = 0; i < 10; i++){
        Constante x(i);
        Multiplication multi(&a, &x);
        Constante res_multi(multi.calcul());
        Addition add(&res_multi, &b);
        series->append(x.calcul(), add.calcul());
        add.affichageClassique();
        cout << endl;

    }
    return series;
}

//Cette fonction permet de tracer un polynome de 2nd degré
QLineSeries * create2ndPolynomeFunction(float pa, float pb, float pc){
    QLineSeries *series = new QLineSeries();
    Constante a(pa);
    Constante b(pb);
    Constante c(pc);
    for(int i = 0; i < 10; i++){
        Constante x(i);
        Multiplication x_sqrt(&x, &x);
        Constante cst_x_sqrt(x_sqrt.calcul());
        Addition a(&cst_x_sqrt, &b);
        Constante cst_a(a.calcul());
        Addition res(&cst_a, &c);
        series->append(x.calcul(), res.calcul());

    }
    return series;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->error_msg->hide();
    abscisseValue = new QLineEdit();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sliderAbscisses_valueChanged(int value)
{
    //mouvement du slider et affichage de la valeur de l'échelle
    QString s = QString::number(value);
    //ui->abscisseValue->setText(s);

}


void MainWindow::on_pushButton_clicked()
{
    //récupération des variables
    //abscisse = ui->abscisseValue->text().toInt();
    _minX = ui->minXValue->text().toInt();
    _minY = ui->minYValue->text().toInt();
    _maxX = ui->maxXValue->text().toInt();
    _maxY = ui->maxYValue->text().toInt();

    cout << abscisse << endl;
    expression = ui->expressionValue->text();

    //Traitement de l'expression
    string str_expression = expression.toUtf8().constData(); //Convertion du QString en string
    str_expression.erase(std::remove_if(str_expression.begin(), str_expression.end(), ::isspace), str_expression.end());//suppression des ' '

    int nbVariable=0;
    for(int i=0;i<str_expression.size();i++)
       if(isalpha(str_expression[i])) nbVariable++;
    cout<<"Nombre de Variable:"<<nbVariable <<endl;

    /*
    cout << str_expression <<endl;


    list<string> liste;
    string nombre;
    for (int i = 0; i < str_expression.size(); i++){
        if(str_expression[i] != '+' && !isalpha(str_expression[i])){
            nombre += str_expression[i];
        }
        else{
            if(nombre != ""){
                liste.insert(liste.end(),nombre);
                nombre ="";
            }

        }
    }
    liste.insert(liste.end(),nombre);

    float nbTab[liste.size()];
    int i = 0;
    for (string n : liste) {
        float f = stof(n);
        nbTab[i] = f;
    }
*/

    /*QLineSeries * series;
    if(nbVariable == 1 ){
        cout << "Expression affine!" << endl;
       series = createAffineFunction(nbTab[0], nbTab[1]);
    }
    if(nbVariable == 1 ){
        cout << "Expression 2nd degres!" << endl;
       series = create2ndPolynomeFunction(nbTab[0], nbTab[1], nbTab[2]);
    }*/


    //Test avec une expression construite par code
    Constante a(1);
    Constante b(4);
    Addition add(&a,&b);
    if(expression != NULL && _minX != NULL && _maxX != NULL && _minY != NULL && _maxY != NULL){
        affichage_graphique(&add);
        ui->error_msg->hide();

    }else{
        ui->error_msg->show();
    }

}

//affiche l'expression passée en paramètre
void MainWindow::affichage_graphique(Expression *exp){

    QLineSeries *series = new QLineSeries();
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();


    for (int i=_minX; i<(_maxX)+1 ; i++)
    {
     series->append(i, exp->calcul());
    }

    QChart *chart = new QChart();
    axisX->setRange(_minX, _maxX);
    axisY->setRange(_minY, _maxY);
    chart->update();
    chart->addSeries(series);
    chart->setTitle(expression);

    QChartView *chartView = new QChartView(chart);
    chartView->chart()->setAxisX(axisX, series);
    chartView->chart()->setAxisY(axisY, series);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->verticalFrame_2);
    chartView->show();

}


void MainWindow::affichage_graphique()
{
     QLineSeries *series = new QLineSeries();
     Constante terme1(-3);
     Constante terme2(0);


     //création des séries avec notre expression (terme1*x+terme2), en attendant le code du groupe 2
     QValueAxis *axisX = new QValueAxis();
     QValueAxis *axisY = new QValueAxis();

     for (int i=_minX; i<(_maxX)+1 ; i++)
     {


      Constante x(i);
      Multiplication multiplication(&terme1,&x);
      Constante resultat(multiplication.calcul());
      Addition add(&resultat, &terme2);
      series->append(i, add.calcul());
      }

     QChart *chart = new QChart();
     chart->update();
     chart->addSeries(series);
     axisX->setRange(_minX, _maxX);
     axisY->setRange(_minY, _maxY);


     chart->setTitle(expression);


    QChartView *chartView = new QChartView(chart);
    chartView->chart()->setAxisX(axisX, series);
    chartView->chart()->setAxisY(axisY, series);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->verticalFrame_2);
    chartView->show();
}
