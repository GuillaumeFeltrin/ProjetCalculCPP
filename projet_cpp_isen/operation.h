#ifndef OPERATION_H
#define OPERATION_H

#include <string>

#include "Expression.h"
#include <iostream>

class Operation : public Expression
{
    private:

    protected:
        Expression * _terme1;
        Expression * _terme2;

    public:

        std::string ToString();
};

#endif // OPERATION_H
