#include "division.h"

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

void Division::affichageClassique() {
    std::cout << " ( ";
    _terme1->affichageClassique();
    std::cout << " / ";
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
