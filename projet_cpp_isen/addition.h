#ifndef ADDITION_H
#define ADDITION_H

#include "operation.h"


class Addition : public Operation
{
public:
    virtual ~Addition(){}
    Addition(Expression *_terme1, Expression *_terme2);
    float calcul();
    bool isConstante();
    Expression* simplifier();
    void affichageClassique();
    void affichagePolonaiseInversee();

};

#endif // ADDITION_H
