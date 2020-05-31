#include <string>
#include <iostream>
#include <fstream>
#include <stack>

#include "SaveLoad.h"
#include "Expression.h"
#include "operation.h"
#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "multiplication.h"

//Save and load
std::string GetFromFile(std::string filepath) {
    std::string equation;
    std::ifstream fileStream;
    fileStream.open(filepath);
    if (fileStream.is_open()) {
        std::getline(fileStream, equation);
        return equation;
    }
    else {
        std::cout << "Le fichier est introuvable !" << std::endl;
        return "";
    }
}

void SaveToFile(std::string toSave) {
    std::ofstream savefile ("./save");
    savefile << InfixToReversePolish(toSave);
    savefile.close();
    return;
}

std::string InfixToReversePolish(std::string toModify) {
    std::stack<std::string> formulaStack;
    std::string currentElement = "";
    std::string reversePolish = "";
    formulaStack.push("start");
    for (int index = 0; index < (int)toModify.length(); index++) {
        if (toModify[index] == '(') formulaStack.push("(");
        else if (toModify[index] == ')') {
            while ((formulaStack.top() != "start")&&(formulaStack.top() != "(")) {
                reversePolish = reversePolish + formulaStack.top()  + " ";
                formulaStack.pop();
            }
            if (formulaStack.top() == "(") formulaStack.pop();
        }
        else if (toModify[index] == ' ') {
            formulaStack.push(currentElement);
            currentElement = "";
        }
        else if ((toModify[index] == '+')||((toModify[index] == '-')&&((toModify[index + 1] == ' ')))||(toModify[index] == '*')||(toModify[index] == '/')) {
            while ((formulaStack.top() != "start") && (formulaStack.top() != "(") ) {
                reversePolish = reversePolish + formulaStack.top() + " ";
                formulaStack.pop();
            }
            formulaStack.push(std::string(1, toModify[index]));
        }
        else {
            currentElement = currentElement + toModify[index];
        }
    }
    while (formulaStack.top() != "start") {
        reversePolish = reversePolish + formulaStack.top() + " ";
        formulaStack.pop();
    }
    return reversePolish;
}



