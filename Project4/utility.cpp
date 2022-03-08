#include "utility.h"
#include "provided.h"

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

bool stringToPair(const std::string s, AttValPair& av) {
	if (s.find(',') == string::npos) {
		cerr << "unable to convert string to AV pair" << endl;
		return false;
	}
	string att;
	string val;
	istringstream iss(s);
	getline(iss, att, ',');
	getline(iss, val);
	av.attribute = att;
	av.value = val;

	return true;
}

bool pairToString(const AttValPair av, std::string& att, std::string& val) {
	//check for comma
	if (av.attribute.find(',') != string::npos && av.value.find(',') != string::npos) {
		cerr << "unable to convert AV pair to string" << endl;
		return false;
	}
	att = av.attribute;
	val = av.value;

	return true;
}