#include "PersonProfile.h"
#include "provided.h"
#include "utility.h"
#include <string>

using namespace std;

PersonProfile::PersonProfile(std::string name, std::string email)
	: m_name(name), m_email(email), m_numPairs(0) {}

PersonProfile::~PersonProfile() {}

string PersonProfile::GetName() const {
	return m_name;
}

string PersonProfile::GetEmail() const {
	return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair& attval) {
	string attribute = attval.attribute;
	string value = attval.value;

	//points to set of values for given attribute key
	set<string>* values = m_Att_to_Val.search(attribute);

	//if no set, then attribute not in map
	if (values == nullptr) {
		set<string> s;
		s.insert(value);
		m_Att_to_Val.insert(attribute, s);		//this seems sus
		m_pairs.push_back(attval);
		m_numPairs++;
	}
	//if set exists but doesn't contain value, add value
	else if (values->find(value) == values->end()) {
		values->insert(value);
		m_pairs.push_back(attval);
		m_numPairs++;
	}
}

int PersonProfile::GetNumAttValPairs() const {
	return m_numPairs;
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
	if (attribute_num < 0 || attribute_num >= m_numPairs)
		return false;
	attval = m_pairs[attribute_num];
	return true;
}