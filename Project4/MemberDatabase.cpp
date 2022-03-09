#include "MemberDatabase.h"
#include "provided.h"
#include "RadixTree.h"
#include "PersonProfile.h"
#include "utility.h"
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
	int size = m_ppersons.size();
	for(int i = size - 1; i >= 0; i--) {
		delete m_ppersons[i];
		m_ppersons.pop_back();
	}
}

bool MemberDatabase::LoadDatabase(std::string filename) {
	//looks in folder with source files
	ifstream infile(filename);
	if (!infile) {
		cerr << "couldn't find file\n";
		return false;
	}

	string name;
	string email;
	string numAttStr;
	int numAtt;
	string newLine; //should always be a newline character
	while (getline(infile, name)) {
		//if (!getline(infile, name)) {
		//	cerr << "couldn't get name\n";
		//	return false;
		//}
		if (!getline(infile, email)) {
			cerr << "couldn't get email\n";
			return false;
		}
		if (!getline(infile, numAttStr)) {
			cerr << "couldn't get number of attributes\n";
			return false;
		}
		//cerr << name << "\n" << email << "\n";

		PersonProfile* p = new PersonProfile(name, email);
		m_ppersons.push_back(p);

		numAtt = stoi(numAttStr);
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
			//cerr << attribute << ',' << value << "\n";

			//insert pair into PersonProfile
			AttValPair av;
			stringToPair(attribute + ',' + value, av);
			p->AddAttValPair(av);

			//insert email 
			//points to set of emails for given avpair key
			set<string>* emailsWithAtt = m_AV_to_Emails.search(attribute + ',' + value);
			
			//if no set, then attribute not in map
			if (emailsWithAtt == nullptr) {
				set<string> e;
				e.insert(email);
				m_AV_to_Emails.insert(attribute + ',' + value, e);
			}
			//if set exists but doesn't contain value, add value
			else if (emailsWithAtt->find(email) == emailsWithAtt->end()) {
				emailsWithAtt->insert(email);
			}
		}
		m_Email_to_Person.insert(email, p);
		getline(infile, newLine);
		if (newLine != "") {
			cerr << "something is wrong\n";
		}
		//cerr << "\n";
	}

	return true;
}
std::vector<std::string> MemberDatabase::FindMatchingMembers(
	const AttValPair& input) const {
	vector<string> output;
	string att = input.attribute;
	string val = input.value;

	set<string>* emailsWithAtt = m_AV_to_Emails.search(att + ',' + val);
	//check if this avpair maps to any emails
	if (emailsWithAtt != nullptr) {
		for (auto i : *emailsWithAtt) 
		{
			output.push_back(i);
		}
	}
	return output;
}

const PersonProfile* MemberDatabase::GetMemberByEmail(
	std::string email) const {
	PersonProfile** p = m_Email_to_Person.search(email);

	return *p;
}