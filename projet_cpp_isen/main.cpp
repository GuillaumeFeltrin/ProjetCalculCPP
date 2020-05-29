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

    std::string validation;
    std::cout << "Voulez vous charger un fichier? y/n" << std::endl;
    std::cin >> validation;
    if ((validation == "y")||(validation == "Y")) {
        std::string equation = GetFromFile("./save");
        if(equation != "") {
            //Chargement depuis la string vers les classes adaptees
        }
    }
    else {
        Multiplication result(new Addition(new Constante(2.1), new Constante(4)), new Constante(3));
        std::cout << result.ToString() << " = " << result.calcul() << std::endl;
        SaveToFile(result.ToString());
        std::cout << "Equation sauvegardee !"  << std::endl;
    }


    // exécution application
    return a.exec();
}
