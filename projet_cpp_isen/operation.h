#ifndef OPERATION_H
#define OPERATION_H

#include <string>

#include "Expression.h"


class Operation : public Expression
{
    protected:
        std::string _symbol;
        Expression* _terme1;
        Expression* _terme2;

    public:
        Operation(Expression* a, Expression* b);
        std::string ToString();
};

#endif // OPERATION_H
