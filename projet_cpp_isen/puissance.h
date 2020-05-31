#ifndef PUISSANCE_H
#define PUISSANCE_H

#include "operation.h"
#include "Expression.h"
#include <cmath>

class Puissance : public Operation
{
public:
    Puissance(Expression *_terme1, Expression *_terme2);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
    bool isConstante();
    Expression* simplifier();
};

#endif // PUISSANCE_H
