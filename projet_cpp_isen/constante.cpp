#include "constante.h"

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
    cout << _valeur;
}

void Constante::affichagePolonaiseInversee(){
    cout << _valeur;
}


float Constante :: calcul(){
    return _valeur;
}
