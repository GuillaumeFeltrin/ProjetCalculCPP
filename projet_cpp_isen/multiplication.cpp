#include "multiplication.h"

Multiplication::Multiplication(Expression *_terme1, Expression *_terme2):
    Operation(_terme1, _terme2)  {}

float Multiplication :: calcul() {
  return _terme1->calcul() * _terme2->calcul();
 }

Expression* Multiplication :: simplifier()
{
   bool result1 = _terme1->isConstante();
   bool result2 = _terme2->isConstante();
   if (result1 && result2){
       Constante * cons = new Constante(_terme1->calcul() * _terme2->calcul());
       return cons;
   }
   else if (result1){
       Multiplication *mult = new Multiplication(_terme1, _terme2->simplifier());
       return mult;
   }
   else if (result2) {
       Multiplication *mult = new Multiplication(_terme1->simplifier(), _terme2);
       return mult;
   }
   else {
       Multiplication * mult = new Multiplication(_terme1->simplifier(), _terme2->simplifier());
       return mult;
   }
}

bool Multiplication :: isConstante()
{
    return false;
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
