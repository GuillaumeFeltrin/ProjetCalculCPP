#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "Expression.h"


class Constante : public Expression
{
private:
    float _valeur;
public:
    Constante(float val);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // CONSTANTE_H
