#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operation.h"
#include <iostream>

class Multiplication : public Operation
{
    private:

    protected:

    public:
        Multiplication(Expression * terme1, Expression * terme2) {
            _terme1 = terme1;
            _terme2 = terme2;
        }

        virtual ~Multiplication() {}

        float calcul() {
            return (float) ( (float) _terme1->calcul() * (float) _terme2->calcul());
        }

        void affichageClassique() {
            std::cout << " ( ";
            _terme1->affichageClassique();
            std::cout << " * ";
            _terme2->affichageClassique();
            std::cout << " ) ";;
        }

        void affichagePolonaiseInversee() {
            _terme1->affichagePolonaiseInversee();
            std::cout << " ";
            _terme2->affichagePolonaiseInversee();
            std::cout << " * ";
        }
};

#endif // MULTIPLICATION_H
