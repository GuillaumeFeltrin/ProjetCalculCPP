#include <string>
#include <sstream>

#include "constante.h"
#include "iostream"
using namespace std;

Constante::Constante(float val)
{
    _valeur = val;
}

void Constante::affichageClassique(){
    cout << _valeur;
}

void Constante::affichagePolonaiseInversee(){
    cout << _valeur;
}

float Constante :: calcul() {
    return _valeur;
}

std::string Constante::ToString() {
    std::ostringstream string;
    string << _valeur;
    return(std::string(string.str()));
}
