#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"

class Variable : public Expression
{
    public:
        Variable();
        virtual ~Variable();
        Variable(char c, float valeur);
        Variable(char c);
        float calcul();
        void setValeur(float c);
        char getCsteV();
        float getValeur();
        void affichageClassique();
        void affichagePolonaiseInversee();
        std::string affichageClassiqueStr();
        std::string affichagePolonaiseInverseeStr();
        Expression* simplifier();
        bool isConstante();
        std::string ToString();

        Variable* next;

    protected:

    private:
        char _csteV;
        float _valeur;
        std::string _symbol;
};

#endif // VARIABLE_H

