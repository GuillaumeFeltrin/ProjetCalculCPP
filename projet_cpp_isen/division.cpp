#include "division.h"
#include "iostream"
using namespace std;
#include "constante.h"

Division::Division(Expression * terme1, Expression * terme2) {
    _terme1 = terme1;
    _terme2 = terme2;
}

float Division::calcul() {
    if (_terme2->calcul() != 0) {
        return (float) ( (float)_terme1->calcul() / (float)_terme2->calcul());
    }
    else {
        return 0;
    }
}

bool Division :: isConstante()
{
    return false;
}

Expression* Division :: simplifier()
{
    bool result1 = _terme1->isConstante();
    bool result2 = _terme2->isConstante();
    if (result1 && result2){
        Constante * cons = new Constante(_terme1->calcul() / _terme2->calcul());
        return cons;
    }
    else if (result1){
        Division *div = new Division(_terme1, _terme2->simplifier());
        return div;
    }
    else if (result2) {
        Division *div = new Division(_terme1->simplifier(), _terme2);
        return div;
    }
    else {
        Division * div = new Division(_terme1->simplifier(), _terme2->simplifier());
        return div;
    }
}

void Division::affichageClassique() {
    std::cout << " ( ";
    _terme1->affichageClassique();
    cout << " / ";
    _terme2->affichageClassique();
    std::cout << " ) ";;
}

void Division::affichagePolonaiseInversee() {
    _terme1->affichagePolonaiseInversee();
    std::cout << " ";
    _terme2->affichagePolonaiseInversee();
    std::cout << " / ";
}

std::string Division::affichageClassiqueStr() {
    return " ( " + _terme1->affichageClassiqueStr()
            + " / " + _terme2->affichageClassiqueStr() + " ) ";
}

std::string Division::affichagePolonaiseInverseeStr() {
    return _terme1->affichagePolonaiseInverseeStr()
           + " " + _terme2->affichagePolonaiseInverseeStr() + " / ";
}
