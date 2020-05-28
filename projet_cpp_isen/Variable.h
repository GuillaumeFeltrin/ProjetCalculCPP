#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"


class Variable : public Expression
{
    public:
        Variable();
        Variable(char c, float nb);
        float calcul();
        bool isConstante();
        Expression* simplifier();
        void affichageClassique();
        void affichagePolonaiseInversee();
        virtual ~Variable();

    protected:

    private:
        char _const;
        float _valeur;
};

#endif // VARIABLE_H
