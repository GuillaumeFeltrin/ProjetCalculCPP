#include "variable.h"
#include <iostream>

using namespace std;

Variable::Variable()
{
    _csteV = 'c';
    _valeur = 1;
    next = NULL;
}

Variable::Variable(char c)
{
    _csteV = c;
    _valeur = 1;
    next = NULL;
}

Variable::Variable(char c, float nb)
{
    _csteV = c;
    this->setValeur(nb);
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

void Variable::setValeur(float c)
{
    _valeur = c;
}

char Variable::getCsteV() {
    return _csteV;
}

float Variable::getValeur(){
    return _valeur;
}

void Variable::affichageClassique()
{
    cout << _csteV ;
}

void Variable::affichagePolonaiseInversee()
{
    cout << _csteV ;
}


std::string Variable::affichageClassiqueStr() {
    std::string str = std::string(&_csteV);
    return str;
}

std::string Variable::affichagePolonaiseInverseeStr() {
    std::string str = std::string(&_csteV);
    return str;
}

Expression* Variable::simplifier(){
    Variable* var = new Variable(_csteV, _valeur);
    return var;
}

bool Variable::isConstante(){
    return false;
}
