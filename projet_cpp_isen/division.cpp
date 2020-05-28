#include "division.h"

Division::Division(Expression *_terme1, Expression *_terme2) :
    Operation(_terme1, _terme2)  {}

float Division :: calcul() {
  return _terme1->calcul() / _terme2->calcul();
 }

void Division :: affichageClassique(){
    std::cout << "(";
    _terme1->affichageClassique();
    std::cout << " / ";
    _terme2->affichageClassique();
    std::cout << ")";}

void Division :: affichagePolonaiseInversee(){
    _terme1->affichagePolonaiseInversee();
    cout << " ";
    _terme2->affichagePolonaiseInversee();
    cout<<" / ";}
