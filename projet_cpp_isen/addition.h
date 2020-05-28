#ifndef ADDITION_H
#define ADDITION_H

#include "operation.h"


class Addition : public Operation
{
public:
    virtual ~Addition(){}
    Addition(Expression *_terme1, Expression *_terme2);
    virtual ~Addition() {}
    float calcul();
    bool isConstante();
    Expression* simplifier();
    void affichageClassique();
    void affichagePolonaiseInversee();
    std::string affichageClassiqueStr();
    std::string affichagePolonaiseInverseeStr();

};

#endif // ADDITION_H
