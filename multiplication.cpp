#include "multiplication.h"

Multiplication::Multiplication(Expression *_terme1, Expression *_terme2):
    Operation(_terme1, _terme2)  {}

float Multiplication :: calcul() {
  return _terme1->calcul() * _terme2->calcul();
 }

void Multiplication :: affichageClassique(){
    std::cout << "(";
    _terme1->affichageClassique();
    std::cout << " x ";
    _terme2->affichageClassique();
    std::cout << ")";}

void Multiplication :: affichagePolonaiseInversee(){
    _terme1->affichagePolonaiseInversee();
    cout << " ";
    _terme2->affichagePolonaiseInversee();
    cout<<" x ";}
