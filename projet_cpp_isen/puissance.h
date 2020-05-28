#ifndef PUISSANCE_H
#define PUISSANCE_H

#include "operation.h"
#include <cmath>

class Puissance : Operation
{
public:
    Puissance(Expression *_terme1, Expression *_terme2);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // PUISSANCE_H
