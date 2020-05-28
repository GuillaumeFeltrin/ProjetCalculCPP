#ifndef DIVISION_H
#define DIVISION_H

#include "Operation.h"
#include <iostream>

class Division : public Operation
{
    private:

    protected:

    public:
        Division(Expression * terme1, Expression * terme2) {
            _terme1 = terme1;
            _terme2 = terme2;
        }
        virtual ~Division() {}
        float calcul() {
            if (_terme2->calcul() != 0) {
                return (float) ( (float)_terme1->calcul() / (float)_terme2->calcul());
            }
            else {
                return 0;
            }
        }
        void affichageClassique() {
            std::cout << " ( ";
            _terme1->affichageClassique();
            std::cout << " / ";
            _terme2->affichageClassique();
            std::cout << " ) ";;
        }
        void affichagePolonaiseInversee() {
            _terme1->affichagePolonaiseInversee();
            std::cout << " ";
            _terme2->affichagePolonaiseInversee();
            std::cout << " / ";
        }
};

#endif // DIVISION_H
