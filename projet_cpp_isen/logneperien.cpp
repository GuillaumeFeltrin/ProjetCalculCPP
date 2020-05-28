#include "logneperien.h"

LogNeperien::LogNeperien(Expression *_terme) :
    OperationUnaire(_terme)  {}

float LogNeperien :: calcul() {
  return std::log(_terme->calcul());
 }

void LogNeperien :: affichageClassique(){
    std::cout << "LOG(";
    _terme->affichageClassique();
    std::cout << ")";}

void LogNeperien :: affichagePolonaiseInversee(){
    _terme->affichagePolonaiseInversee();
    cout<<" LOG ";}
