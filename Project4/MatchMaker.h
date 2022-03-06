#ifndef MATCH_MAKER_H
#define MATCH_MAKER_H

#include "provided.h"
#include <string>
#include <vector>

class MemberDatabase;
class AttributeTranslator;

class MatchMaker
{
public:
	MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
	~MatchMaker();

	std::vector<EmailCount> IdentifyRankedMatches(std::string email,
		int threshold) const;

private:
	//unordered set?
};

#endif