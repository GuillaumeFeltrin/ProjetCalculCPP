#ifndef CARE_H
#define CARE_H
#include "operationunaire.h"

class Carre : public OperationUnaire
{

public:
    Carre(Expression *_terme);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // CARE_H
