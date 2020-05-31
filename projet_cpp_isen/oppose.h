#ifndef OPPOSE_H
#define OPPOSE_H

#include "operationunaire.h"

class Oppose : public OperationUnaire
{
    //c oppose
public:
    Oppose(Expression *_terme);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
};

#endif // OPPOSE_H
