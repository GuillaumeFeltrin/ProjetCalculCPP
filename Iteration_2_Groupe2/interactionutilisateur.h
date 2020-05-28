#ifndef INTERACTIONUTILISATEUR_H
#define INTERACTIONUTILISATEUR_H

#include <stack>
#include "Expression.h"
#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"
#include "Operation.h"
#include <QList>
#include <QString>

using namespace std;
class InteractionUtilisateur
{
    const string _sum = "+";
    const string _sous = "-";
    const string _mult = "*";
    const string _div = "/";

public:
    InteractionUtilisateur(QList<QString> *listStr);
    Expression* getExpression(){return _pileExpression.top();}

private:
    void initialiseInteraction(QList<QString> *listStr);
    void analyseElement(string str);
    void gestionSomme();
    void gestionSoustraction();
    void gestionMultiplication();
    void gestionDivision();

    stack<string> _pile;
    stack<Expression*> _pileExpression;

};

#endif // INTERACTIONUTILISATEUR_H
