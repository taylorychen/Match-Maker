#ifndef ATTRIBUTE_TRANSLATOR_H
#define ATTRIBUTE_TRANSLATOR_H

#include <string>
#include <set>
#include <vector>
#include "RadixTree.h"
#include "provided.h"

class AttributeTranslator
{
public:
	AttributeTranslator();
	~AttributeTranslator();

	/**
	* Loads the attribute-value translation data from the
	* data file specified by the filename parameter.
	* Returns true if the file was successfully loaded
	* and false otherwise.
	*/
	bool Load(std::string filename);

	/**
	* Identifies all compatible attribute-value pairs for the
	* specified source attributevalue pair and returns a vector
	* containing them (no duplicates). If there are no compatible
	* pairs, the vector returned is empty.
	*/
	std::vector<AttValPair> FindCompatibleAttValPairs(
		const AttValPair& source) const;

private:
	//maps source attributes to compatible attributes
	RadixTree<std::set<std::string>> m_Src_to_Comp;

};

#endif