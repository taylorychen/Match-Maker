#include "MatchMaker.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"
#include "PersonProfile.h"
#include "provided.h"
#include <string>
#include <vector>
using namespace std;

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) 
	: m_database(mdb), m_translator(at) {}

MatchMaker::~MatchMaker() {

}

std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email,
	int threshold) const {
	const PersonProfile* p = m_database.GetMemberByEmail(email);
	int numPairs = p->GetNumAttValPairs();
	AttValPair pair;
	for (int i = 0; i < numPairs; i++) {
		p->GetAttVal(i, pair);
		//insert into datastructure not allowing duplicates
	}
	 

	vector<EmailCount> v;
	return v;
}