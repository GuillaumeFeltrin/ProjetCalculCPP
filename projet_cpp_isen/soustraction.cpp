#include "soustraction.h"


Soustraction::Soustraction(Expression * terme1, Expression * terme2) {
    _terme1 = terme1;
    _terme2 = terme2;
}

float Soustraction::calcul() {
    return (float) ((float)_terme1->calcul() - (float)_terme2->calcul());
}

void Soustraction::affichageClassique() {
    std::cout << " ( ";
    _terme1->affichageClassique();
    std::cout << " - ";
    _terme2->affichageClassique();
    std::cout << " ) ";
}

void Soustraction::affichagePolonaiseInversee() {
    _terme1->affichagePolonaiseInversee();
    std::cout << " ";
    _terme2->affichagePolonaiseInversee();
    std::cout << " - ";
}

std::string Soustraction::affichageClassiqueStr() {
    return " ( " + _terme1->affichageClassiqueStr()
            + " - " + _terme2->affichageClassiqueStr() + " ) ";
}

std::string Soustraction::affichagePolonaiseInverseeStr() {
    return _terme1->affichagePolonaiseInverseeStr()
           + " " + _terme2->affichagePolonaiseInverseeStr() + " - ";
}
