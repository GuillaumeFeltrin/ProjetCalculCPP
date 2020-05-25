#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"

class Variable : public Expression
{
    public:
        Variable();
        virtual ~Variable();
        Variable(char c, float valeur);
        float calcul();
        void set_valeur(float c);
        void affichageClassique();
        void affichagePolonaiseInversee();

        char _csteV;
        float _valeur;
        Variable* next;

    protected:

    private:
};

#endif // VARIABLE_H



