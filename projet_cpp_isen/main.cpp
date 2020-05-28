#include <QCoreApplication>
#include <string>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "iostream"
#include "SaveLoad.h"

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

    std::string validation;
    std::cout << "Voulez vous charger un fichier? y/n" << std::endl;
    std::cin >> validation;
    if ((validation == "y")||(validation == "Y")) {
        std::string equation = GetFromFile("./save");
        if(equation != "") {
            //Chargement depuis la string vers les classes adaptées
        }
    }
    else {
        Multiplication result(new Addition(new Constante(2.1), new Constante(4)), new Constante(3));
        std::cout << result.ToString() << " = " << result.calcul() << std::endl;
        SaveToFile(result.ToString());
        std::cout << "Equation sauvegardée !"  << std::endl;
    }


    // exécution application
    return a.exec();
}
