#include "soustraction.h"


Soustraction::Soustraction(Expression *_terme1, Expression *_terme2) :
    Operation(_terme1, _terme2)  {}

float Soustraction :: calcul() {
  return _terme1->calcul() - _terme2->calcul();
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

