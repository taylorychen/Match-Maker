#include "PersonProfile.h"
#include <string>

using namespace std;

PersonProfile::PersonProfile(std::string name, std::string email)
	: m_name(name), m_email(email) {}

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
	return 0;
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
	return false;
}