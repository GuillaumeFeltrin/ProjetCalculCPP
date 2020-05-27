#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operation.h"

class Multiplication : public Operation
{
public:
    Multiplication(Expression *_terme1, Expression *_terme2);
    float calcul();
    void affichageClassique();
    void affichagePolonaiseInversee();
    std::string affichageClassiqueStr();
    std::string affichagePolonaiseInverseeStr();

};

#endif // MULTIPLICATION_H
