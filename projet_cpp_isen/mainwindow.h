#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "constante.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }



QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_sliderAbscisses_valueChanged(int value);

    void on_pushButton_clicked();

    void affichage_graphique();
    void affichage_graphique(Expression *expression);



private:
    Ui::MainWindow *ui;
    QLineEdit *abscisseValue;
    QLineEdit *expressionValue;
    int abscisse;
    int _minX;
    int _maxX;
    int _minY;
    int _maxY;
    QString expression;
};
#endif // MAINWINDOW_H
