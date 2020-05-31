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
};

#endif // LOGNEPERIEN_H
