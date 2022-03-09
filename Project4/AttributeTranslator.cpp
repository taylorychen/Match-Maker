#include "AttributeTranslator.h"
#include "provided.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


AttributeTranslator::AttributeTranslator() {

}

AttributeTranslator::~AttributeTranslator() {

}

bool AttributeTranslator::Load(string filename) {
	//looks in folder with source files
	ifstream infile(filename);
	if (!infile) {
		cerr << "couldn't find file\n";
		return false;
	}

	string srcAtt;
	string srcVal;
	string compAtt;
	string compVal;

	string line;
	while (getline(infile, line)) {
		istringstream iss(line);
		if (!getline(iss, srcAtt, ','))
			cerr << "couldn't get source attribute\n";
		if (!getline(iss, srcVal, ','))
			cerr << "couldn't get source value\n";
		if (!getline(iss, compAtt, ','))
			cerr << "couldn't get compatible attribute\n";
		if (!getline(iss, compVal))
			cerr << "couldn't get compatible value\n";

		//cerr << srcAtt << "," << srcVal << "," << compAtt << "," << compVal << endl;
		//insert into map

		//points to set of compatible avpairs for given avpair key
		set<string>* compAVPairs = m_Src_to_Comp.search(srcAtt + "," + srcVal);

		//if no set, then compatible AVPair not in map
		if (compAVPairs == nullptr) {
			set<string> compAVPair;
			compAVPair.insert(compAtt + ',' + compVal);
			m_Src_to_Comp.insert(srcAtt + "," + srcVal, compAVPair);
		}
		//if set exists but doesn't contain compatible AVPair, add it
		else if (compAVPairs->find(srcAtt + "," + srcVal) == compAVPairs->end()) {
			compAVPairs->insert(compAtt + ',' + compVal);
		}
	}

	return true;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(
	const AttValPair& source) const {

	vector<AttValPair> output;

	string att = source.attribute;
	string val = source.value;
	set<string>* compToSource = m_Src_to_Comp.search(att + ',' + val);
	//check if these 

	//finish


	return output;
}