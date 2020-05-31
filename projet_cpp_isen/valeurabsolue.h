#ifndef VALEURABSOLUE_H
#define VALEURABSOLUE_H

#include "operationunaire.h"

class ValeurAbsolue : public OperationUnaire
{
public:
    ValeurAbsolue(Expression *_terme);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // VALEURABSOLUE_H
