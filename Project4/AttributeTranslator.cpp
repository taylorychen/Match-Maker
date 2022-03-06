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

	return false;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(
	const AttValPair& source) const {
	vector<AttValPair> v;
	return v;
}