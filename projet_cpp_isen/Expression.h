#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>

using namespace std;

class Expression
{
    public:
        Expression(){}
        ~Expression(){}
        virtual float calcul() = 0;
        virtual void affichageClassique() = 0;
        virtual void affichagePolonaiseInversee() = 0;
        virtual std::string ToString() = 0;
    
};

#endif
