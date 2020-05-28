#include "constante.h"
#include "iostream"
using namespace std;

Constante::Constante(float val)
{
    _valeur = val;
}

Expression* Constante :: simplifier()
{
    Constante *con = new Constante(_valeur);
    return con;
}

bool Constante:: isConstante()
{
    return true;
}

void Constante::affichageClassique(){
    std::cout << _valeur;
}

void Constante::affichagePolonaiseInversee(){
    std::cout << _valeur;
}


float Constante :: calcul(){
    return _valeur;
}

std::string Constante::affichageClassiqueStr() {
    std::string str = std::to_string(_valeur);
    return str;
}

std::string Constante::affichagePolonaiseInverseeStr() {
    std::string str = std::to_string(_valeur);
    return str;
}
