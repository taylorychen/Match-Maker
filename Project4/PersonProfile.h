#ifndef PERSON_PROFILE_H
#define PERSON_PROFILE_H

#include "RadixTree.h"
#include "provided.h"
#include <string>
#include <set>
#include <vector>

struct AttValPair;

class PersonProfile
{
public:
	PersonProfile(std::string name, std::string email);
	~PersonProfile();

	std::string GetName() const;
	std::string GetEmail() const;

	/**
	* adds new attribute-value pair to profile. If profile already
	* has same exact pair, does nothing. More than one pair can
	* have same attribute as long as values are different
	*/
	void AddAttValPair(const AttValPair& attval);

	/**
	* Returns total number of distinct attribute value pairs
	*/
	int GetNumAttValPairs() const;

	/**
	* Gets the attribute-value pair specified by attribute_num
	* (where 0 <= attribute_num < GetNumAttValPairs()) and places
	* it in the attval parameter.
	* Returns true if it successfully retrieves an attribute;
	* otherwise, it returns false and leaves attval unchanged.
	*/
	bool GetAttVal(int attribute_num, AttValPair& attval) const;

private:
	std::string m_name;
	std::string m_email;
	int m_numPairs;
	RadixTree<std::set<std::string>> m_Att_to_Val;
	std::vector<AttValPair> m_pairs;
};


#endif