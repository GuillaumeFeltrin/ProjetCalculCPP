#include "puissance.h"
#include "constante.h"

Puissance::Puissance(Expression *terme1, Expression *terme2){
    _terme1 = terme1;
    _terme2 = terme2;
}

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

bool Puissance :: isConstante()
{
    return false;
}

Expression* Puissance :: simplifier()
{
    bool result1 = _terme1->isConstante();
    bool result2 = _terme2->isConstante();
    if (result1 && result2){
        Constante * cons = new Constante(_terme1->calcul() +  _terme2->calcul());
        return cons;
    }
    else if (result1){
        Puissance *add = new Puissance(_terme1, _terme2->simplifier());
        return add;
    }
    else if (result2) {
        Puissance *add = new Puissance(_terme1->simplifier(), _terme2);
        return add;
    }
    else {
        Puissance * add = new Puissance(_terme1->simplifier(), _terme2->simplifier());
        return add;
    }
}
