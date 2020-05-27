#include "constante.h"

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


float Constante :: calcul(){
    return _valeur;
}
