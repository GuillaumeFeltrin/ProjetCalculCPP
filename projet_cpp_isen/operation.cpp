#include <string>

#include "operation.h"

/*Operation::Operation(Expression* a, Expression* b) {
    _terme1 = a;
    _terme2 = b;
}*/

std::string Operation::ToString() {
    return("( " + _terme1->ToString() + " " + _symbol + " " + _terme2->ToString() + " )");
}
