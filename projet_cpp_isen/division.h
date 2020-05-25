#ifndef DIVISION_H
#define DIVISION_H

#include "operation.h"

class Division : Operation
{
public:
    Division(Expression *_terme1, Expression *_terme2);
    float calcul();
    Expression * simplifier();
    bool isConstante();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // DIVISION_H
