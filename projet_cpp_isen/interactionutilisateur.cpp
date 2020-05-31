#include "interactionutilisateur.h"

#include "constante.h"
#include "addition.h"
#include "division.h"
#include "soustraction.h"
#include "multiplication.h"
#include "operation.h"
#include "variable.h"
#include "symboletable.h"
#include "logneperien.h"
#include "puissance.h"
#include "racinecarre.h"
#include "valeurabsolue.h"
#include "inverse.h"
#include "oppose.h"

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
    else if(str == _abs)
        gestionAbsolue();
    else if(str == _pow)
        gestionPuissance();
    else if(str == _sqrt)
        gestionRacine();
    else if(str == _log)
        gestionLog();
    else if(str == _opp)
        gestionOppose();
    else if(str == _inv)
        gestionInverse();
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

void InteractionUtilisateur::gestionPuissance(){

    //Depile
    _pileExpression.pop();
    Expression* expression2 = _pileExpression.top();
    Expression* expression1 = _pileExpression.top();
    _pileExpression.pop();

    //creation Operation
    Puissance* p = new Puissance(expression1,expression2);
    _pileExpression.push(p);
}

void InteractionUtilisateur::gestionAbsolue(){

    //Depile
    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();

    ValeurAbsolue* abs = new ValeurAbsolue(expression1);
    //creation Operation
    _pileExpression.push(abs);
}

void InteractionUtilisateur::gestionInverse(){

    Expression* expression2 = _pileExpression.top();
    //Depile
    _pileExpression.pop();

    //creation Operation
    Inverse* i = new Inverse(expression1);
    _pileExpression.push(i);
}

void InteractionUtilisateur::gestionRacine(){
    //Depile

    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();

    //creation Operation
    RacineCarre* r = new RacineCarre(expression1);
}
    _pileExpression.push(r);

void InteractionUtilisateur::gestionOppose(){

    Expression* expression2 = _pileExpression.top();
    //Depile
    _pileExpression.pop();
    //creation Operation

    Oppose* o = new Oppose(expression1);
}
    _pileExpression.push(o);

void InteractionUtilisateur::gestionLog(){

    //Depile
    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();

    //creation Operation
    LogNeperien* l = new LogNeperien(expression1);
    _pileExpression.push(l);
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




    
