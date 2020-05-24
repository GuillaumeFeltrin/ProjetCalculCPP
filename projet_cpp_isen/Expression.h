#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

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
};

#endif // EXPRESSION_H
