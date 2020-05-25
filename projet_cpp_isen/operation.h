#ifndef OPERATION_H
#define OPERATION_H

#include "Expression.h"


class Operation : public Expression
{
protected:
    Expression* _terme1;
    Expression* _terme2;

public:
    Operation(Expression* a, Expression* b);
    bool isConstante();
};

#endif // OPERATION_H
