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
		//insert into data structures
		//m_pairs.insert(srcAtt+srcVal, )
	}

	return true;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(
	const AttValPair& source) const {

	vector<AttValPair> v;
	return v;
}