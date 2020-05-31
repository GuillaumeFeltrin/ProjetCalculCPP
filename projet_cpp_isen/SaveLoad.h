#ifndef SAVELOAD
#define SAVELOAD

#include <string>

#include "operation.h"
#include "constante.h"

std::string GetFromFile(std::string filepath);

void SaveToFile(std::string toSave);

std::string InfixToReversePolish(std::string toModify);

#endif