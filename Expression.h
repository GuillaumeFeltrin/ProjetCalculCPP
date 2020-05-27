#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

using namespace std;

class Expression
{
public:
    Expression(){}
    virtual ~Expression(){}
    virtual float calcul() = 0;
    virtual void affichageClassique() = 0;
    virtual void affichagePolonaiseInversee() = 0;
};

#endif // EXPRESSION_H
