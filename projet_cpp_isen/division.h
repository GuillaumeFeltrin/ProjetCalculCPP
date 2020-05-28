#ifndef DIVISION_H
#define DIVISION_H

#include "operation.h"

class Division : public Operation
{
public:
    Division(Expression *_terme1, Expression *_terme2);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // DIVISION_H
