#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "Expression.h"


class Constante : public Expression
{
private:
    float _valeur;
public:
    Constante(float val);
    virtual ~Constante() {}
    float calcul();
    bool isConstante();
    Expression* simplifier();
    void affichageClassique();
    void affichagePolonaiseInversee();
    std::string affichageClassiqueStr();
    std::string affichagePolonaiseInverseeStr();
};

#endif // CONSTANTE_H
