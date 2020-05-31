#ifndef RACINECAREE_H
#define RACINECAREE_H

#include "operationunaire.h"

class RacineCarre : public OperationUnaire
{
public:
    RacineCarre(Expression *_terme);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // RACINECAREE_H
