#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "operation.h"

class Soustraction : Operation
{
public:
    Soustraction(Expression *_terme1, Expression *_terme2);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // SOUSTRACTION_H
