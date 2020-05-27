#include "interactionutilisateur.h"

#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "multiplication.h"
#include "operation.h"
#include<string.h>
#include<stdio.h>
#include <typeinfo>
#include <iostream>
#include <algorithm>
using namespace std;

InteractionUtilisateur::InteractionUtilisateur()
{
    initialiseInteraction();
}

InteractionUtilisateur::InteractionUtilisateur(string str)
{
    initialiseInteraction(str);
}


void InteractionUtilisateur::initialiseInteraction(){
    cout << "S'il vous plait, entrez votre Expression terme a terme et terminez par 'p' " << endl;
    string _str = " 5 5 +";
     /*do{
        cin >> _str;
        analyseElement(_str);
    }while(_str.compare("p"));*/
    analyseElement(_str);

}

void InteractionUtilisateur::initialiseInteraction(string _str){

    do{
        analyseElement(_str);
    }while(_str.compare("p"));



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
