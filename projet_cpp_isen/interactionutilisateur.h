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
    const srting _abs = "||";
    const string _sqrt = "sqrt";
    const string _log = "log";
    const string _opp = "opp";
    const string _inv = "inv";
    const string _pow = "pow";



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
    void gestionPuissance();
    void gestionRacine();
    void gestionLog();
    void gestionOppose();
    void gestionAbsolue();
    void gestionInverse();

    stack<Expression*> _pileExpression;
    Symboletable* _table;

};

#endif // INTERACTIONUTILISATEUR_H
