#include "MatchMaker.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"
#include "PersonProfile.h"
#include "provided.h"
#include "utility.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at)
	: m_database(&mdb), m_translator(&at) {}

MatchMaker::~MatchMaker() {

}

bool isWorseMatch(const EmailCount& a, const EmailCount& b);

std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email,
	int threshold) const {
	vector<EmailCount> out;

	//get person from database
	const PersonProfile* p = m_database->GetMemberByEmail(email);
	if (p == nullptr)
		return out;

	//create a set to store compatible attvalpairs
	unordered_set<string /*representing pair*/> allCompatibles;

	int numPairs = p->GetNumAttValPairs();
	AttValPair pair;
	//loop through all pairs
	for (int i = 0; i < numPairs; i++) {
		p->GetAttVal(i, pair);

		string att;
		string val;
		vector<AttValPair> compatible = m_translator->FindCompatibleAttValPairs(pair);
		for (auto i : compatible) {
			//convert to strings to put in hash
			pairToString(i, att, val);
			allCompatibles.insert(att + ',' + val);
		}
	}
	//create a map to store compatible members mapped to how many compatibles
	unordered_map<string /*email*/, int> compatibleCounts;

	//iterate through compatible traits to find members that have those traits
	for (unordered_set<string>::iterator i = allCompatibles.begin(); i != allCompatibles.end(); i++) {
		AttValPair av;
		stringToPair(*i, av);
		vector<string/*email*/> compMembers = m_database->FindMatchingMembers(av);

		//add compMembers to map, incrementing counts for number of matches
		for (int j = 0; j < compMembers.size(); j++) {
			unordered_map<string, int>::iterator m = compatibleCounts.find(*i);
			if (m == compatibleCounts.end()) { //email not in map
				std::pair<string, int> compMember(compMembers[j], 1);
				compatibleCounts.insert(compMember);
			}
			else {//email is in map so just increment
				(*m).second++;
			}
		}
	}
	vector<EmailCount> output;
	for (unordered_map<string, int>::iterator i = compatibleCounts.begin();
		i != compatibleCounts.end(); i++)
	{
		EmailCount e((*i).first, (*i).second);
		output.push_back(e);
	}
	sort(output.begin(), output.end(), isWorseMatch);


	return output;
}


/**
* Used to sort EmailCounts
* Highest # matches first, then alphabetical order
*/
bool isWorseMatch(const EmailCount& a, const EmailCount& b) {
	if (a.count < b.count)
		return true;
	else if (a.count == b.count)
		if (a.email < b.email)
			return true;
	return false;
}