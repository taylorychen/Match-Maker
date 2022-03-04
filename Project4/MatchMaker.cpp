#include "MatchMaker.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"
#include "provided.h"
#include <string>
#include <vector>
using namespace std;

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) {

}

MatchMaker::~MatchMaker() {

}

std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email,
	int threshold) const {
	vector<EmailCount> v;
	return v;
}