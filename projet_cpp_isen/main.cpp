#include <QCoreApplication>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "carre.h"
#include "inverse.h"
#include "logneperien.h"
#include "puissance.h"
#include "racinecarre.h"
#include "valeurabsolue.h"
#include "oppose.h"
#include "iostream"
using namespace std;

//Main
int main(int argc, char *argv[])
{
    // creation application
    QCoreApplication a(argc, argv);
    //QApplication app(argc, argv);

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


    // TEST CARRE
    Carre h(&b);

    cout << "affichage classique carre : ";
    h.affichageClassique();
    cout << endl;

    cout <<"affichage polonaise inversee : ";
    h.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << h.calcul() << endl;
    cout << endl;

    // TEST INVERSE
    Inverse i(&b);

    cout << "affichage classique inverse : ";
    i.affichageClassique();
    cout << endl;

    cout <<"affichage polonaise inversee : ";
    i.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << i.calcul() << endl;
    cout << endl;

    // TEST LOGN
    LogNeperien j(&b);

    cout << "affichage classique logn() : ";
    j.affichageClassique();
    cout << endl;

    cout << "affichage polonaise inversee : ";
    j.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << j.calcul() << endl;
    cout << endl;

    // TEST OPPOSE
    Oppose k(&b);

    cout << "affichage classique oppose : ";
    k.affichageClassique();
    cout << endl;

    cout << "affichage polonaise inversee : ";
    k.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << k.calcul() << endl;
    cout << endl;

    // TEST RACINE
    RacineCarre l(&b);

    cout << "affichage classique racine : ";
    l.affichageClassique();
    cout << endl;

    cout << "affichage polonaise inversee : ";
    l.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << l.calcul() << endl;
    cout << endl;

    // TEST ABSOLUE
    ValeurAbsolue m(&b);

    cout << "affichage classique val absolue : ";
    m.affichageClassique();
    cout << endl;

    cout << "affichage polonaise inversee : ";
    m.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << m.calcul() << endl;
    cout << endl;

    // TEST PUISSANCE
    Puissance n(&b, &c);

    cout << "affichage classique puissance : ";
    n.affichageClassique();
    cout << endl;

    cout << "affichage polonaise inversee : ";
    n.affichagePolonaiseInversee();
    cout << endl;

    cout << "affichage classique : ";
    cout << n.calcul() << endl;
    cout << endl;

    // exécution application
    //return a.exec();
}
