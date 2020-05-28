#include <QCoreApplication>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "interactionutilisateur.h"
#include "symboletable.h"
#include "iostream"
using namespace std;

//Main
int main(int argc, char *argv[])
{

    // creation application
    QCoreApplication a(argc, argv);

/*
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
*/
    cout << "--------TEST INSERTION TABLE SYMBOLE--------" << endl;
    Symboletable* table = new Symboletable();
    Variable* var = new Variable('y',4);
    table->insert(var->_csteV, var->_valeur);
    cout << endl;

    cout << "--------TEST INTERACTION UTILISATEUR--------" << endl;
    InteractionUtilisateur* inter = new InteractionUtilisateur(table);
    Expression* expression = inter->getExpression();
    cout << "Affichage Polonaise Inversee :";
    expression->affichagePolonaiseInversee();
    cout << endl << "Affichage Classique :";
    expression->affichageClassique();
    cout << endl << "Resultat :" << expression->calcul() << endl;
    cout << "---------FIN DU TEST-----------" << endl;

    // exécution application
    return a.exec();
}
