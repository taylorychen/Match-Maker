#include "MemberDatabase.h"
#include "provided.h"
#include "PersonProfile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

MemberDatabase::MemberDatabase() {

}
MemberDatabase::~MemberDatabase() {

}

bool MemberDatabase::LoadDatabase(std::string filename) {
	//looks in folder with source files
	ifstream infile(filename);
	if (!infile) {
		cerr << "couldn't find file\n";
		return false;
	}

	//
	string name;
	string email;
	int numAtt;
	if (!getline(infile, name)) {
		cerr << "couldn't get name\n";
		return false;
	}
	if (!getline(infile, email)) {
		cerr << "couldn't get email\n";
		return false;
	}
	if (!(infile >> numAtt)) {
		cerr << "couldn't get number of attributes\n";
		return false;
	}
	infile.get();
	string attribute;
	string value;
	for (int i = 0; i < numAtt; i++) {
		if (!getline(infile, attribute, ',')) {
			cerr << "couldn't get attribute\n";
			return false;
		}
		if (!getline(infile, value)) {
			cerr << "couldn't get value\n";
			return false;
		}
	}
	/*string line;
	while (getline(infile, line)) {

	}*/
	return true;
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