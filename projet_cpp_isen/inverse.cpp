#include "inverse.h"

Inverse::Inverse(Expression *_terme) :
    OperationUnaire(_terme)  {}

float Inverse :: calcul() {
  return 1 / _terme->calcul();
 }

void Inverse :: affichageClassique(){
    std::cout << "( 1 / ";
    _terme->affichageClassique();
    std::cout << ")";}

void Inverse :: affichagePolonaiseInversee(){
    _terme->affichagePolonaiseInversee();
    cout<<" 1 / ";}
