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
        void set_valeur(float c);
        void affichageClassique();
        void affichagePolonaiseInversee();
        std::string affichageClassiqueStr();
        std::string affichagePolonaiseInverseeStr();

        char _csteV;
        float _valeur;
        Variable* next;

    protected:

    private:
};

#endif // VARIABLE_H



