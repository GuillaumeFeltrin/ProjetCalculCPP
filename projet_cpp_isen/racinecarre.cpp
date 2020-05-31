#include "racinecarre.h"

RacineCarre::RacineCarre(Expression *_terme) :
    OperationUnaire(_terme)  {}

float RacineCarre :: calcul() {
  return std::sqrt(_terme->calcul()) ;
 }

void RacineCarre :: affichageClassique(){
    std::cout << "SQRT(";
    _terme->affichageClassique();
    std::cout << ")";}

void RacineCarre :: affichagePolonaiseInversee(){
    _terme->affichagePolonaiseInversee();
    cout<<" SQRT ";}
