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
    bool isConstante();
    Expression* simplifier();
};

#endif // RACINECAREE_H
