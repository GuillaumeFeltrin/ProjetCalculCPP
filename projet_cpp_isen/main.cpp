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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 

    // GROUPE 5
    MainWindow M;

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



    // exécution application
    return app.exec();
}
