#include <QCoreApplication>
#include <QApplication>
#include <QtWidgets>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "iostream"
using namespace std;

//Main
int main(int argc, char *argv[])
{
    // creation application
    /*QCoreApplication a(argc, argv);


    // test affichage CONSTANTE
    cout << "creation premiere constante: ";
    Constante b(10);
    b.affichageClassique();
    cout << endl;
    cout << "creation deuxieme constante: ";
    Constante c(20);
    c.affichageClassique();
    cout << endl << endl;


    // TEST ADDITION
    Addition d(&b, &c);

    cout << "affichage classique addition : ";
    d.affichageClassique();
    cout << endl;

    cout <<"affichage polonaise inversee : ";
    d.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << d.calcul() << endl;
    cout << endl;


    // TEST SOUSTRACTION
    Soustraction e(&b, &c);

    cout << "affichage classique soustraction : ";
    e.affichageClassique();
    cout << endl;

    cout <<"affichage polonaise inversee : ";
    e.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << e.calcul() << endl;
    cout << endl;


    // TEST MULTIPLICATION
    Multiplication f(&b, &c);

    cout << "affichage classique multiplication : ";
    f.affichageClassique();
    cout << endl;

    cout <<"affichage polonaise inversee : ";
    f.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << f.calcul() << endl;
    cout << endl;


    // TEST MULTIPLICATION
    Division g(&b, &c);

    cout << "affichage classique division : ";
    g.affichageClassique();
    cout << endl;

    cout <<"affichage polonaise inversee : ";
    g.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << g.calcul() << endl;
    cout << endl;


    // exécution application
    return a.exec();*/

    QApplication app(argc, argv);

    QWidget fenetre;

    // 1 : Créer le QTabWidget
    QTabWidget *onglets = new QTabWidget(&fenetre);
    onglets->setGeometry(50,50, 500, 400);

    // 2 : Créer les pages, en utilisant un widget parent pour contenir chacune des pages
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget; // Comme un QLabel est aussi un QWidget (il en hérite), on peut aussi s'en servir de page

    // 3 : Créer le contenu des pages de widgets

        // Page 1
            QLineEdit *saisie = new QLineEdit("Entrez votre expression");
            QPushButton *bouton1 = new QPushButton("Afficher l'expression");
            QPushButton *bouton2 = new QPushButton("Afficher la valeur ");
            QPushButton *bouton3 = new QPushButton("Simplifier l'expression ");

            QVBoxLayout *vbox1 = new QVBoxLayout;
            vbox1->addWidget(saisie);
            vbox1->addWidget(bouton1);
            vbox1->addWidget(bouton2);
            vbox1->addWidget(bouton3);

            page1->setLayout(vbox1);


        //Ajouter les fonctions du groupe 2

        // Page 2

        // Page 3


    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(page1, "Affichage de l'expression ");
    onglets->addTab(page2, "Graphique 2D et 3D");
    onglets->addTab(page3, "Sauvegarde");

    fenetre.show();

    return app.exec();
}
