#ifndef MEMBER_DATABASE_H
#define MEMBER_DATABASE_H
#include "RadixTree.h"
#include <string>
#include <set>
#include <vector>

struct AttValPair;
class PersonProfile;

class MemberDatabase
{
public:
	MemberDatabase();
	~MemberDatabase();

	/**
	* Loads member database from data file specified by filename
	* Returns true if file was successfully loaded, false otherwise
	*/
	bool LoadDatabase(std::string filename);

	/**
	* Returns a vector containing email addresses of members with 
	* specified AttValPair
	*/
	std::vector<std::string> FindMatchingMembers(
		const AttValPair& input) const;

	/**
	* Returns pointer to member with inputted email, nullptr if
	* member doesn't exist
	*/
	const PersonProfile* GetMemberByEmail(std::string email) const;

private:
	RadixTree<PersonProfile*> m_Email_to_Person; //maps emails to PersonProfiles
	
	std::vector<PersonProfile*> m_ppersons; //vector of pointers for deletion

	RadixTree<std::set<std::string>> m_AV_to_Emails;	//maps AttVal Pairs to emails
};

#endif