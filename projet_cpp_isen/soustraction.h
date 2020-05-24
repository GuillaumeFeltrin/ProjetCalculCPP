#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "operation.h"

class Soustraction : public Operation
{
public:
    Soustraction(Expression *_terme1, Expression *_terme2);
    virtual ~Soustraction() {}
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
    std::string affichageClassiqueStr();
    std::string affichagePolonaiseInverseeStr();
};

#endif // SOUSTRACTION_H
