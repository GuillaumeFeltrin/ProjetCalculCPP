#ifndef INTERACTIONUTILISATEUR_H
#define INTERACTIONUTILISATEUR_H

#include <stack>
#include "Expression.h"
#include "symboletable.h"

using namespace std;
class InteractionUtilisateur
{
    const string _sum = "+";
    const string _sous = "-";
    const string _mult = "*";
    const string _div = "/";



public:
    InteractionUtilisateur();
    InteractionUtilisateur(Symboletable* table);
    Expression* getExpression(){return _pileExpression.top();}

private:
    void initialiseInteraction();
    void analyseElement(string str);
    void gestionSomme();
    void gestionSoustraction();
    void gestionMultiplication();
    void gestionDivision();
    void gestionVariable(char str);

    stack<string> _pile;
    stack<Expression*> _pileExpression;
    Symboletable* _table;

};

#endif // INTERACTIONUTILISATEUR_H
