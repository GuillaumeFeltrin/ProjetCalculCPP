#ifndef INVERSE_H
#define INVERSE_H

#include "operationunaire.h"

class Inverse : public OperationUnaire
{
public:
    Inverse(Expression *_terme);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // INVERSE_H
