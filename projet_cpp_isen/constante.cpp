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

Expression* Constante :: simplifier()
{
    Constante *con = new Constante(_valeur);
    return con;
}

bool Constante:: isConstante()
{
    return true;
}

std::string Constante::affichageClassiqueStr() {
    std::string str = std::to_string(_valeur);
    return str;
}

std::string Constante::affichagePolonaiseInverseeStr() {
    std::string str = std::to_string(_valeur);
    return str;
}
