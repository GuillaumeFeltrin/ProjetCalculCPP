#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "iostream"
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
};

#endif // EXPRESSION_H
