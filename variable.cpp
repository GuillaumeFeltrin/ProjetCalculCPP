#include "Expression.h"
#include "variable.h"
#include <iostream>

using namespace std;

Variable::Variable()
{
    _csteV = 'c';
    _valeur = 1;
     next = NULL;
}

Variable::Variable(char c, float nb)
{
    _csteV = c;
    _valeur = nb;
     next = NULL;
}


Variable::~Variable()
{
    //dtor
}

float Variable::calcul()
{
    return _valeur;
}

void Variable::set_valeur(float c)
{
    _valeur = c;
}

void Variable::affichageClassique()
{
    cout << _csteV ;
}

void Variable::affichagePolonaiseInversee()
{
    cout << _csteV ;
}
