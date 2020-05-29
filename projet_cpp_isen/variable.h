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

        Variable* next;

    protected:

    private:
        char _csteV;
        float _valeur;
};

#endif // VARIABLE_H

