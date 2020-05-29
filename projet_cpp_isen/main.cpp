#include <QCoreApplication>
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "variable.h"
#include "symboletable.h"
#include "iostream"
#include "window.h"
#include "mainwindow.h"
#include "SaveLoad.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 

    // GROUPE 5
    MainWindow M;
    
    // GROUPE 3
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

    // GROUPE 2 & 1
    // Objet de la class Window qui hérite de QWidget
    Window window;
    // exécution application
    window.show();
        
    //GROUPE 6
    cout << " \n x prend la valeur 2 et y prend la valeur 3" << endl;
    Constante c1(10);
    Constante c2(2);

    //Creation d'une variable 'x'
    Variable x1('x',2);

    Multiplication m2(&c2,&x1);
    Constante c5(5);
    Constante c6(3);

    Variable y1('y',3);

    Multiplication m3(&c6,&y1);
    Addition add1(&m2,&c5);
    Addition add2(&add1,&m3);
    add2.affichageClassique();
    cout << "      ";
    add2.affichagePolonaiseInversee();
    cout << "      = "<< add2.calcul() << endl;

    cout << "\non change les valeurs de x et y : x prend la valeur 4 et y prend la valeur 10" << endl;
    x1.setValeur(4);
    y1.setValeur(10);
    Multiplication m4(&c6,&y1);
    Addition add3(&m2,&c5);
    Addition add4(&add1,&m3);
    add4.affichageClassique();
    cout << "      ";
    add4.affichagePolonaiseInversee();
    cout << "      = "<< add4.calcul() << endl;

    // TEST TABLE DES SYMBOLES
    Symboletable st;
    char check;
    cout << "**** EXEMPLE SYMBOL_TABLE ****\n";

    // insert 'x' = 4
    if (st.insert('x', 4))
        cout << "creation success \n\n";
    else
        cout << "\nFailed to insert.\n";

    // insert 'y' = 5
    if (st.insert('y', 5))
        cout << " creation success \n\n";
    else
        cout << "\nFailed to insert\n";

    // find 'x'
    check = st.find('x');
    if (check != -1)
        cout << "Variable Is present\n";
    else
        cout << "\nVariable Not Present\n";

    // delete 'x'
    if (st.deleteRecord('x'))
        cout << "x variable is deleted\n";
    else
        cout << "\nFailed to delete\n";

    // modify 'y'
    if (st.modify( 'y', 10))
        cout << "\n Number Identifier modified\n";

    // find and print 'number'
    int value=0;
    value = st.find('y');
    if (check != -1)
        cout << "Variable y value: " << value;
    else
        cout << "\nVariable not Present";


    //GROUPE 8
    Constante c1_8 = Constante(3);
    Constante c2_8 = Constante(6);

    Variable v = Variable('v',3.0);

    Addition add1_8(&v, &c1);
    Addition add2_8(&c1,&c2);
    Addition add3_8(&add1,&add2);

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
    return app.exec();
}
