#include "addition.h"

Addition::Addition(Expression * terme1, Expression * terme2) {
    _terme1 = terme1;
    _terme2 = terme2;
}

float Addition::calcul() {
    return (float)((float) _terme1->calcul() + (float) _terme2->calcul());
}

void Addition::affichageClassique() {
    std::cout << " ( ";
    _terme1->affichageClassique();
    std::cout << " + ";
    _terme2->affichageClassique();
    std::cout << " ) ";;
}

void Addition::affichagePolonaiseInversee() {
    _terme1->affichagePolonaiseInversee();
    std::cout << " ";
    _terme2->affichagePolonaiseInversee();
    std::cout << " + ";
}

std::string Addition::affichageClassiqueStr() {
    return " ( " + _terme1->affichageClassiqueStr()
            + " + " + _terme2->affichageClassiqueStr() + " ) ";
}

std::string Addition::affichagePolonaiseInverseeStr() {
    return _terme1->affichagePolonaiseInverseeStr()
           + " " + _terme2->affichagePolonaiseInverseeStr() + " + ";
}
