#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operation.h"

class Multiplication : Operation
{
public:
    Multiplication(Expression *_terme1, Expression *_terme2);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // MULTIPLICATION_H
