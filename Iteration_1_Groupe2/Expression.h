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
};

#endif // EXPRESSION_H
