#ifndef ADDITION_H
#define ADDITION_H

#include <string>

#include "operation.h"
#include "Expression.h"


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
    std::string affichageClassiqueStr();
    std::string affichagePolonaiseInverseeStr();
        Addition(Expression *_terme1, Expression *_terme2);

};

#endif // ADDITION_H
