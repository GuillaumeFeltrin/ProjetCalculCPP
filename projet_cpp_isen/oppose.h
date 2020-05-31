#ifndef OPPOSE_H
#define OPPOSE_H

#include "operationunaire.h"

class Oppose : public OperationUnaire
{
public:
    Oppose(Expression *_terme);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
    bool isConstante();
    Expression* simplifier();
};

#endif // OPPOSE_H
