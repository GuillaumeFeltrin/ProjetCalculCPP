#include "puissance.h"

Puissance::Puissance(Expression *_terme1, Expression *_terme2):
    Operation(_terme1, _terme2)  {}

float Puissance :: calcul() {
  return std::pow(_terme1->calcul(), _terme2->calcul());
 }

void Puissance :: affichageClassique(){
    std::cout << "(";
    _terme1->affichageClassique();
    std::cout << " ^ ";
    _terme2->affichageClassique();
    std::cout << ")";}

void Puissance :: affichagePolonaiseInversee(){
    _terme1->affichagePolonaiseInversee();
    cout << " ";
    _terme2->affichagePolonaiseInversee();
    cout<<" ^ ";}
