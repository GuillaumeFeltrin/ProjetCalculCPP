#ifndef INTERACTIONUTILISATEUR_H
#define INTERACTIONUTILISATEUR_H

#include <stack>
#include "Expression.h"
#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "multiplication.h"
#include "operation.h"
#include "variable.h"
#include "symboletable.h"

#include <QList>
#include <QString>

using namespace std;
class InteractionUtilisateur
{
    const string _sum = "+";
    const string _sous = "-";
    const string _mult = "*";
    const string _div = "/";
    const string _abs = "||";
    const string _sqrt = "sqrt";
    const string _log = "log";
    const string _opp = "opp";
    const string _inv = "inv";
    const string _pow = "pow";

public:
    InteractionUtilisateur(QList<QString> *listStr);
    InteractionUtilisateur(QList<QString> *listStr, Symboletable *table);
    Expression* getExpression(){return _pileExpression.top();}
    Symboletable* getSymboleTable(){return _table;}
private:
    void initialiseInteraction(QList<QString> *listStr);
    void analyseElement(string str);
    void gestionSomme();
    void gestionSoustraction();
    void gestionMultiplication();
    void gestionDivision();
    void gestionPuissance();
    void gestionRacine();
    void gestionLog();
    void gestionOppose();
    void gestionAbsolue();
    void gestionInverse();
    void gestionVariable(char str);

    stack<string> _pile;
    stack<Expression*> _pileExpression;
    Symboletable* _table;

};

#endif // INTERACTIONUTILISATEUR_H
