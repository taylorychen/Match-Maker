#ifndef MATCH_MAKER_H
#define MATCH_MAKER_H

#include "provided.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"
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
	const MemberDatabase* m_database;
	const AttributeTranslator* m_translator;
};

#endif