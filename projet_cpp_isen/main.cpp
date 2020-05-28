#include <QCoreApplication>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "variable.h"
#include "iostream"
using namespace std;

int main(int argc, char *argv[])
{
    // creation application
    QCoreApplication a(argc, argv);


//    // test affichage CONSTANTE
//    cout << "creation premiere constante: ";
//    Constante b(10);
//    b.affichageClassique();
//    cout << endl;
//    cout << "creation deuxieme constante: ";
//    Constante c(20);
//    c.affichageClassique();
//    cout << endl << endl;


//    // TEST ADDITION
//    Addition d(&b, &c);

//    cout << "affichage classique addition : ";
//    d.affichageClassique();
//    cout << endl;

//    cout <<"affichage polonaise inversee : ";
//    d.affichagePolonaiseInversee();
//    cout << endl;

//    cout << "affichage classique : ";
//    cout << d.calcul() << endl;
//    cout << endl;


//    // TEST SOUSTRACTION
//    Soustraction e(&b, &c);

//    cout << "affichage classique soustraction : ";
//    e.affichageClassique();
//    cout << endl;

//    cout <<"affichage polonaise inversee : ";
//    e.affichagePolonaiseInversee();
//    cout << endl;

//    cout << "affichage classique : ";
//    cout << e.calcul() << endl;
//    cout << endl;


//    // TEST MULTIPLICATION
//    Multiplication f(&b, &c);

//    cout << "affichage classique multiplication : ";
//    f.affichageClassique();
//    cout << endl;

//    cout <<"affichage polonaise inversee : ";
//    f.affichagePolonaiseInversee();
//    cout << endl;

//    cout << "affichage classique : ";
//    cout << f.calcul() << endl;
//    cout << endl;


//    // TEST MULTIPLICATION
//    Division g(&b, &c);

//    cout << "affichage classique division : ";
//    g.affichageClassique();
//    cout << endl;

//    cout <<"affichage polonaise inversee : ";
//    g.affichagePolonaiseInversee();
//    cout << endl;

//    cout << "affichage classique : ";
//    cout << g.calcul() << endl;
//    cout << endl;

    //TEST POUR LE GROUPE 8
    Constante c1 = Constante(3);
    Constante c2 = Constante(6);

    Variable v = Variable('v',3.0);

    Addition add1(&v, &c1);
    Addition add2(&c1,&c2);
    Addition add3(&add1,&add2);

    add1.simplifier()->affichageClassique();cout <<endl;
    add2.simplifier()->affichageClassique();cout <<endl;
    add3.simplifier()->affichageClassique();cout <<endl;

    Soustraction sous1(&v, &c1);
    Soustraction sous2(&c2,&c1);
    Soustraction sous3(&sous1,&sous2);

    sous1.simplifier()->affichageClassique();cout <<endl;
    sous2.simplifier()->affichageClassique();cout <<endl;
    sous3.simplifier()->affichageClassique();cout <<endl;

    Multiplication mult1(&v, &c1);
    Multiplication mult2(&c2,&c1);
    Multiplication mult3(&mult1,&mult2);

    mult1.simplifier()->affichageClassique();cout <<endl;
    mult2.simplifier()->affichageClassique();cout <<endl;
    mult3.simplifier()->affichageClassique();cout <<endl;

    Division div1(&v, &c1);
    Division div2(&c2,&c1);
    Division div3(&div1,&div2);

    div1.simplifier()->affichageClassique();cout <<endl;
    div2.simplifier()->affichageClassique();cout <<endl;
    div3.simplifier()->affichageClassique();cout <<endl;

    Division div = Division(&c2, &c1);
    Addition add = Addition(&v, &c1);

    Soustraction sous = Soustraction(&add, &div);

    Multiplication mult = Multiplication(&sous, &add);

    mult.simplifier()->affichageClassique();cout <<endl;




    // exécution application
    return a.exec();
}
