#include "carre.h"

Carre::Carre(Expression *_terme) :
    OperationUnaire(_terme)  {}

float Carre :: calcul() {
  return std::pow(_terme->calcul(),2);
 }

void Carre :: affichageClassique(){
    std::cout << "(";
    _terme->affichageClassique();
    std::cout << " ^ 2)";}

void Carre :: affichagePolonaiseInversee(){
    _terme->affichagePolonaiseInversee();
    cout<<" 2 ^ ";}
