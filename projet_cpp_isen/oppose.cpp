#include "oppose.h"

Oppose::Oppose(Expression *_terme) :
    OperationUnaire(_terme)  {}

float Oppose :: calcul() {
  return -(_terme->calcul()) ;
 }

void Oppose :: affichageClassique(){
    std::cout << "OPPOSITE(";
    _terme->affichageClassique();
    std::cout << ")";}

void Oppose :: affichagePolonaiseInversee(){
    _terme->affichagePolonaiseInversee();
    cout<<" OPPOSITE ";}
