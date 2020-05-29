#include <string>

#include "addition.h"
#include "constante.h"
#include "iostream"
using namespace std;

Addition::Addition(Expression * terme1, Expression * terme2) {
    _terme1 = terme1;
    _terme2 = terme2;
    //_symbol = "+";
}

float Addition::calcul() {
    return (float)((float) _terme1->calcul() + (float) _terme2->calcul());
}


bool Addition :: isConstante()
{
    return false;
}

Expression* Addition :: simplifier()
{
    bool result1 = _terme1->isConstante();
    bool result2 = _terme2->isConstante();
    if (result1 && result2){
        Constante * cons = new Constante(_terme1->calcul() +  _terme2->calcul());
        return cons;
    }
    else if (result1){
        Addition *add = new Addition(_terme1, _terme2->simplifier());
        return add;
    }
    else if (result2) {
        Addition *add = new Addition(_terme1->simplifier(), _terme2);
        return add;
    }
    else {
        Addition * add = new Addition(_terme1->simplifier(), _terme2->simplifier());
        return add;
    }
}

void Addition::affichageClassique() {
    std::cout << " ( ";
    _terme1->affichageClassique();
    cout << " + ";
    _terme2->affichageClassique();
    std::cout << " ) ";;
}

void Addition :: affichagePolonaiseInversee(){
    _terme1->affichagePolonaiseInversee();
    cout << " ";
    _terme2->affichagePolonaiseInversee();
    cout<<" + ";}
