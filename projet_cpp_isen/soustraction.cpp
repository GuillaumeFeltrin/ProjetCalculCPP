#include "soustraction.h"


Soustraction::Soustraction(Expression *_terme1, Expression *_terme2) :
    Operation(_terme1, _terme2)  {}

float Soustraction :: calcul() {
  return _terme1->calcul() - _terme2->calcul();
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

void Soustraction :: affichageClassique(){
    std::cout << "(";
    _terme1->affichageClassique();
    std::cout << " - ";
    _terme2->affichageClassique();
    std::cout << ")";}

void Soustraction :: affichagePolonaiseInversee(){
    _terme1->affichagePolonaiseInversee();
    cout << " ";
    _terme2->affichagePolonaiseInversee();
    cout<<" - ";}

