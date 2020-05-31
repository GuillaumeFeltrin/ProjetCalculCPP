#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>

using namespace std;


class Expression
{
    private:

    protected:

    public:
        Expression() {}
        virtual float calcul() { return 0; }
        virtual void affichageClassique() {}
        virtual void affichagePolonaiseInversee() {}
        virtual std::string affichageClassiqueStr() { return ""; }
        virtual std::string affichagePolonaiseInverseeStr() { return ""; }
        virtual Expression* simplifier() = 0;
        virtual bool isConstante() = 0;
        virtual std::string ToString() =0;
};

#endif
