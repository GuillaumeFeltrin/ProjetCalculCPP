#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operation.h"

class Multiplication : Operation
{
public:
    Multiplication(Expression *_terme1, Expression *_terme2);
    float calcul();
    Expression * simplifier();
    bool isConstante();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // MULTIPLICATION_H
