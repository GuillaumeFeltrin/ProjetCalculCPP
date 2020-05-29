#include "interactionutilisateur.h"

#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "multiplication.h"
#include "operation.h"
#include "variable.h"
#include "symboletable.h"
#include "logneperien.h"
#include "puissance.h"
#include "valeurabsolue.h"
#include "racinecarre.h"
#include "inverse.h"
#include "oppose.h"



using namespace std;

/**
  En créant un objet InteractionUtilisateur, on ouvre le dialogue avec l'utilsateur
    qui doit rentrer son expression en terminant par '*p'.
    A la fin de la connection, l'expression est stockée et est accessible par getExpression.
 * @brief InteractionUtilisateur::InteractionUtilisateur
 */
InteractionUtilisateur::InteractionUtilisateur()
{
    _table = new Symboletable();
    initialiseInteraction();
}

/**
  En créant un objet InteractionUtilisateur, on ouvre le dialogue avec l'utilsateur
    qui doit rentrer son expression en terminant par '*p'.
    A la fin de la connection, l'expression est stockée et est accessible par getExpression.
 * @brief InteractionUtilisateur::InteractionUtilisateur
 * @param table : une table de symbole si elle existe.
 */
InteractionUtilisateur::InteractionUtilisateur(Symboletable* table){
    _table = table;
    initialiseInteraction();
}


void InteractionUtilisateur::initialiseInteraction(){
    cout << "S'il vous plait, entrez votre Expression terme a terme et terminez par '*p' " << endl;
    string _str;
    do{
        cin >> _str;
        analyseElement(_str);
    }while(_str.compare("*p"));
}


void InteractionUtilisateur::analyseElement(string str){
    if(isdigit(str[0]) || isdigit(str[1])){
        Constante* e = new Constante(stof(str));
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
    _pileExpression.push(m);
}

void InteractionUtilisateur::gestionPuissance(){

    //Depile
    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();
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

    //creation Operation
    ValeurAbsolue* abs = new ValeurAbsolue(expression1);
    _pileExpression.push(abs);
}

void InteractionUtilisateur::gestionInverse(){

    //Depile
    Expression* expression2 = _pileExpression.top();
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
    _pileExpression.push(r);
}

void InteractionUtilisateur::gestionOppose(){

    //Depile
    Expression* expression2 = _pileExpression.top();
    _pileExpression.pop();

    //creation Operation
    Oppose* o = new Oppose(expression1);
    _pileExpression.push(o);
}

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
        _table->insert(var->_csteV, var->_valeur);
        _pileExpression.push(var);
    }else{
        //recherche de la variable dans la table
        int index = _table->hashf(str);
        Variable* start = _table->list[index];
        while (start != NULL) {

            if (start->_csteV == str) {
                _pileExpression.push(start);
            }

            start = start->next;
        }
    }
}
