#include "multiplication.h"
#include "iostream"
using namespace std;
#include "constante.h"

Multiplication::Multiplication(Expression * terme1, Expression * terme2) {
    _terme1 = terme1;
    _terme2 = terme2;
    _symbol = "*";
}

float Multiplication::calcul() {
    return (float) ( (float) _terme1->calcul() * (float) _terme2->calcul());
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

void Multiplication::affichageClassique() {
    std::cout << " ( ";
    _terme1->affichageClassique();
    std::cout << " * ";
    _terme2->affichageClassique();
    std::cout << " ) ";;
}

void Multiplication::affichagePolonaiseInversee() {
    _terme1->affichagePolonaiseInversee();
    std::cout << " ";
    _terme2->affichagePolonaiseInversee();
    std::cout << " * ";
}

std::string Multiplication::affichageClassiqueStr() {
    return " ( " + _terme1->affichageClassiqueStr()
            + " * " + _terme2->affichageClassiqueStr() + " ) ";
}

std::string Multiplication::affichagePolonaiseInverseeStr() {
    return _terme1->affichagePolonaiseInverseeStr()
           + " " + _terme2->affichagePolonaiseInverseeStr() + " * ";
}
