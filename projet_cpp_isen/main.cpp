#include <QCoreApplication>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "iostream"
using namespace std;

int main(int argc, char *argv[])
{
    // creation application
    QCoreApplication a(argc, argv);


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
    return a.exec();
}
