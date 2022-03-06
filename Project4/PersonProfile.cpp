#include "PersonProfile.h"
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
	
}

int PersonProfile::GetNumAttValPairs() const {
	return m_numPairs;
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
	if(attribute_num < 0 || attribute_num >= m_numPairs)
		return false;



	return true;
}