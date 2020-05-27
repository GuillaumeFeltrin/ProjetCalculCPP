#ifndef ADDITION_H
#define ADDITION_H

#include "operation.h"


class Addition : public Operation
{
public:
    Addition(Expression *_terme1, Expression *_terme2);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();

};

#endif // ADDITION_H
