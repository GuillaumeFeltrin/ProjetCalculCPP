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
    virtual std::string affichageClassiqueStr() { return ""; }
    virtual std::string affichagePolonaiseInverseeStr() { return ""; }

};

#endif // EXPRESSION_H
