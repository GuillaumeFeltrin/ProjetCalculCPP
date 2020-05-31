#ifndef OPERATIONSUNAIRES_H
#define OPERATIONSUNAIRES_H

#include "Expression.h"
#include <cmath>

class OperationUnaire: public Expression
{
protected:
    Expression* _terme;


public:
    OperationUnaire(Expression* a);
};

#endif // OPERATIONSUNAIRES_H
