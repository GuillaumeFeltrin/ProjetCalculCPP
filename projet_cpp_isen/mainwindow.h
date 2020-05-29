#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "constante.h"
#include "window.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, float resultat = 0.0, Window * window = nullptr);
    ~MainWindow();

private slots:

    void on_sliderAbscisses_valueChanged(int value);

    void on_pushButton_clicked();

    void affichage_graphique();

    void affichage_graphique(Expression *exp);

private:
    Ui::MainWindow *ui;
    QLineEdit *abscisseValue;
    Expression *_exp;
    InteractionUtilisateur *_inter;
    Window * _window;
    int abscisse;
    float resultat_calcul;
};
#endif // MAINWINDOW_H
