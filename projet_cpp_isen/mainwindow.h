#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QtWidgets>


class MainWindow : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT                    // Nécessaire pour créer un slot maison
    QWidget fenetre;

    public:
    MainWindow();                // Constructeur (forcément pubic)

    public slots:               // Slots maison
    void Redirect();
    void ouvrirFonctionSaisie();
    void ouvrirFonctionShowVal();
    void ouvrirFonctionShowExpress();
    void ouvrirFonctionSimplify();
    void ouvrirExpClassique();
    void ouvrirExpPolo();


    private:

    QTabWidget *onglets = new QTabWidget(&fenetre);

    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;

    QLineEdit *saisie = new QLineEdit("Entrez votre expression");
    QPushButton *showExpress = new QPushButton("Afficher l'expression");
    QPushButton *showVal = new QPushButton("Afficher la valeur");
    QPushButton *simplify = new QPushButton("Simplifier l'expression");

     QPushButton *classique = new QPushButton("Afficher l'expression classique");
     QPushButton *polo = new QPushButton("Afficher l'expression polonaise inversée");

    QVBoxLayout *vbox1 = new QVBoxLayout;
    QVBoxLayout *vbox2 = new QVBoxLayout;

    QPushButton *m_bouton;      // Attribut (forcément privé)
                                // pointeur --> il faudra le construire dynamiquement (new)

};

#endif
