#include "valeurabsolue.h"

ValeurAbsolue::ValeurAbsolue(Expression *_terme) : OperationUnaire(_terme) {}

float ValeurAbsolue ::calcul()
{
    return std::abs(_terme->calcul());
}

void ValeurAbsolue ::affichageClassique()
{
    std::cout << "ABS(";
    _terme->affichageClassique();
    std::cout << ")";
}

void ValeurAbsolue ::affichagePolonaiseInversee()
{
    _terme->affichagePolonaiseInversee();
    cout << " ABS ";
}
