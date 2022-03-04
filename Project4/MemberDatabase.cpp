#include "MemberDatabase.h"
#include "provided.h"
#include "PersonProfile.h"

#include <string>
#include <vector>

using namespace std;

MemberDatabase::MemberDatabase() {

}
MemberDatabase::~MemberDatabase() {

}

bool MemberDatabase::LoadDatabase(std::string filename) {
	return false;
}
std::vector<std::string> MemberDatabase::FindMatchingMembers(
	const AttValPair& input) const {


	vector<string> v;
	return v;
}

const PersonProfile* MemberDatabase::GetMemberByEmail(
	std::string email) const {


	PersonProfile p("name", "email");
	const PersonProfile* out = &p;
	return out;
}