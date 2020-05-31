#include "operationunaire.h"
#include "constante.h"

OperationUnaire::OperationUnaire(Expression* a)
{
    _terme = a;
}

std::string OperationUnaire::ToString() {
    return("( " + _terme->ToString()+ " )");
}

bool OperationUnaire :: isConstante()
{
    return false;
}

Expression* OperationUnaire :: simplifier()
{
    bool result = _terme->isConstante();
    if (result != 0){
        Constante * cons = new Constante(_terme->calcul() +  _terme->calcul());
        return cons;
    }
    else {
        return 0;
    }
}
