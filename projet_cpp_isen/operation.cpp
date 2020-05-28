#include "operation.h"

Operation::Operation(Expression* a, Expression* b)
{
    _terme1 = a;
    _terme2 = b;
}

bool Operation::isConstante()
{
    return false;
}
