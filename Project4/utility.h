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

/**
* converts AttValPair to attribute and value strings
* returns false if av has a ',' in either of its data members and leaves
* values of att and val unchanged
*/
bool pairToString(const AttValPair av, std::string& att, std::string& val);

#endif