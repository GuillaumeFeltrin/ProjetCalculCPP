#include "multiplication.h"

Multiplication::Multiplication(Expression * terme1, Expression * terme2) {
    _terme1 = terme1;
    _terme2 = terme2;
}

float Multiplication::calcul() {
    return (float) ( (float) _terme1->calcul() * (float) _terme2->calcul());
}

void Multiplication::affichageClassique() {
    std::cout << " ( ";
    _terme1->affichageClassique();
    std::cout << " * ";
    _terme2->affichageClassique();
    std::cout << " ) ";;
}

void Multiplication::affichagePolonaiseInversee() {
    _terme1->affichagePolonaiseInversee();
    std::cout << " ";
    _terme2->affichagePolonaiseInversee();
    std::cout << " * ";
}

std::string Multiplication::affichageClassiqueStr() {
    return " ( " + _terme1->affichageClassiqueStr()
            + " * " + _terme2->affichageClassiqueStr() + " ) ";
}

std::string Multiplication::affichagePolonaiseInverseeStr() {
    return _terme1->affichagePolonaiseInverseeStr()
           + " " + _terme2->affichagePolonaiseInverseeStr() + " * ";
}
