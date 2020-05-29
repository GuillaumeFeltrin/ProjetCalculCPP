#include "soustraction.h"
#include "constante.h"
#include "iostream"
using namespace std;

Soustraction::Soustraction(Expression * terme1, Expression * terme2) {
    _terme1 = terme1;
    _terme2 = terme2;
    _symbol = "-";
}

float Soustraction::calcul() {
    return (float) ((float)_terme1->calcul() - (float)_terme2->calcul());
}

bool Soustraction::isConstante()
{
    return false;
}

Expression* Soustraction :: simplifier()
{
    bool result1 = _terme1->isConstante();
    bool result2 = _terme2->isConstante();
    if (result1 && result2){
        Constante * cons = new Constante(_terme1->calcul() - _terme2->calcul());
        return cons;
    }
    else if (result1){
        Soustraction *sous = new Soustraction(_terme1, _terme2->simplifier());
        return sous;
    }
    else if (result2) {
        Soustraction *sous = new Soustraction(_terme1->simplifier(), _terme2);
        return sous;
    }
    else {
        Soustraction * sous = new Soustraction(_terme1->simplifier(), _terme2->simplifier());
        return sous;
    }
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
