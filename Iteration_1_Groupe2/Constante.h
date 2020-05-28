#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"
#include <iostream>

class Constante : public Expression
{
    private:
        float _valeur;

    protected:

    public:
        Constante(float valeur) {
            _valeur = valeur;
        }
        virtual ~Constante() {}
        float calcul() {
            return _valeur;
        }
        void affichageClassique() {
            std::cout << _valeur;
        }
        void affichagePolonaiseInversee() {
            std::cout << _valeur;
        }
};

#endif // CONSTANTE_H
