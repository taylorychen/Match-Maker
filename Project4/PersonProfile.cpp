#include "PersonProfile.h"
#include "provided.h"
#include <string>

using namespace std;

PersonProfile::PersonProfile(std::string name, std::string email)
	: m_name(name), m_email(email), m_numPairs(0) {}

PersonProfile::~PersonProfile() {
	/*int size = m_sets.size();
	for(int i = size - 1; i >= 0; i--) {
		delete m_sets[i];
		m_sets.pop_back();
	}*/
}

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
	set<string>* values = m_indices.search(attribute);

	//if no set, then attribute not in map
	if (values == nullptr) {
		set<string>* s = new set<string>;
		s->insert(value);
		m_indices.insert(attribute, *s);		//this seems sus
		m_pairs.push_back(attval);
		m_numPairs++;
		delete s;
		//m_sets.push_back(s);
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