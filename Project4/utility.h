#ifndef UTILITY_H
#define UTILITY_H

#include "provided.h"
#include <string>


/**
* converts string with attribute and value separated by ',' to AttValPair
* returns false if invalid string, leaving value of av unchanged
* string must have a singular ',' separating attribute from value
*/
bool stringToPair(const std::string s, AttValPair& av);

#endif