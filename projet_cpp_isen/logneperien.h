#ifndef LOGNEPERIEN_H
#define LOGNEPERIEN_H

#include "operationunaire.h"

class LogNeperien : public OperationUnaire
{
public:
    LogNeperien(Expression *_terme);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
    bool isConstante();
    Expression* simplifier();
};

#endif // LOGNEPERIEN_H
