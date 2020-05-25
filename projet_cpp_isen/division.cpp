#include "division.h"

Division::Division(Expression *_terme1, Expression *_terme2) :
    Operation(_terme1, _terme2)  {}

float Division :: calcul() {
  return _terme1->calcul() / _terme2->calcul();
 }

bool Division :: isConstante()
{
    return false;
}

Expression* Division :: simplifier()
{
    bool result1 = _terme1->isConstante();
    bool result2 = _terme2->isConstante();
    if (result1 && result2){
        Constante * cons = new Constante(_terme1->calcul() / _terme2->calcul());
        return cons;
    }
    else if (result1){
        Division *div = new Division(_terme1, _terme2->simplifier());
        return div;
    }
    else if (result2) {
        Division *div = new Division(_terme1->simplifier(), _terme2);
        return div;
    }
    else {
        Division * div = new Division(_terme1->simplifier(), _terme2->simplifier());
        return div;
    }
}

void Division :: affichageClassique(){
    std::cout << "(";
    _terme1->affichageClassique();
    std::cout << " / ";
    _terme2->affichageClassique();
    std::cout << ")";}

void Division :: affichagePolonaiseInversee(){
    _terme1->affichagePolonaiseInversee();
    cout << " ";
    _terme2->affichagePolonaiseInversee();
    cout<<" / ";}
