#include "interactionutilisateur.h"

using namespace std;

InteractionUtilisateur::InteractionUtilisateur(QList<QString> *listStr)
{
    _table = new Symboletable();
    initialiseInteraction(listStr);
}

InteractionUtilisateur::InteractionUtilisateur(QList<QString> *listStr, Symboletable* table){
    _table = table;
    initialiseInteraction(listStr);
}

void InteractionUtilisateur::initialiseInteraction(QList<QString> *listStr){
    for(int i(0); i < listStr->size() - 1; i++) {
        analyseElement(listStr->at(i).toStdString());
    }
}


void InteractionUtilisateur::analyseElement(string str){
    if(isdigit(str[0]) || isdigit(str[1])){
        Constante* e = new Constante(stof(str));
//        _pile.push(str);
        _pileExpression.push(e);
    }else if(str == _sum){
        gestionSomme();
    }else if(str == _sous)
        gestionSoustraction();
    else if(str == _mult)
        gestionMultiplication();
    else if(str == _div)
        gestionDivision();
    else if(isalpha(str[0]))
        gestionVariable(str[0]);
}

void InteractionUtilisateur::gestionSomme(){

    //Depile _pileExpression
    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();
    Expression* expression1 = _pileExpression.top();
    _pileExpression.pop();

    //creation Operation
    Addition *a = new Addition(expression1, expression2);
    _pile.push(to_string(a->calcul()));
    _pileExpression.push(a);
}

void InteractionUtilisateur::gestionDivision(){

    //Depile
    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();
    Expression* expression1 = _pileExpression.top();
    _pileExpression.pop();

    //creation Operation
    Division* d = new Division(expression1,expression2);
    _pile.push(to_string(d->calcul()));
    _pileExpression.push(d);
}

void InteractionUtilisateur::gestionSoustraction(){

    //Depile
    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();
    Expression* expression1 = _pileExpression.top();
    _pileExpression.pop();

    //creation Operation
    Soustraction* s = new Soustraction(expression1,expression2);
    _pile.push(to_string(s->calcul()));
    _pileExpression.push(s);
}

void InteractionUtilisateur::gestionMultiplication(){

    //Depile
    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();
    Expression* expression1 = _pileExpression.top();
    _pileExpression.pop();

    //creation Operation
    Multiplication* m = new Multiplication(expression1,expression2);
    _pile.push(to_string(m->calcul()));
    _pileExpression.push(m);
}

void InteractionUtilisateur::gestionVariable(char str){
    //Recherche de la variable dans la table des symboles
    if(_table->find(str) == -1){ //Variable non trouvé
        //Creation d'une nouvelle variable et insertion dans le tableau
        Variable* var = new Variable(str);

        _table->insert(var->getCsteV(), var->getValeur());
        _pileExpression.push(var);
    }else{
        //recherche de la variable dans la table
        int index = _table->hashf(str);
        Variable* start = _table->list[index];
        while (start != NULL) {
            if (start->getCsteV() == str) {
                _pileExpression.push(start);
            }

            start = start->next;
        }
    }
}

