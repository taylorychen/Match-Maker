#include "AttributeTranslator.h"
#include "provided.h"
#include <string>

using namespace std;


AttributeTranslator::AttributeTranslator() {

}

AttributeTranslator::~AttributeTranslator() {

}

bool AttributeTranslator::Load(string filename) {
	return false;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(
	const AttValPair& source) const {
	vector<AttValPair> v;
	return v;
}