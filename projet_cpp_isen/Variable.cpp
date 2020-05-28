#include "variable.h"
#include "iostream"
using namespace std;

Variable::Variable()
{
    //ctor
}

Variable::Variable(char c, float nb)
{
    _const = c;
    _valeur = nb;
}

float Variable :: calcul() {
  return _valeur;
 }

bool Variable :: isConstante()
{
    return false;
}

Expression* Variable :: simplifier()
{
    Variable *var = new Variable(_const, _valeur);
    return var;
}

void Variable :: affichageClassique()
{
    cout << _const; //<<"("<< _valeur<<")";
}

void Variable :: affichagePolonaiseInversee()
{
    cout << _const <<"("<< _valeur<<")";
}

Variable::~Variable()
{
    //dtor
}
