#define TEST_TREE
#ifdef TEST_TREE

#include "RadixTree.h"
#include "PersonProfile.h"
#include "AttributeTranslator.h"
#include <cassert>
#include <iostream>
using namespace std;

void testPP();

int main() {
	RadixTree<double> t;
	t.insert("A", 1.5);
	assert(*(t.search("A")) - 1.5 <= 0.001);
	t.insert("A", 1.5);
	assert(*(t.search("A")) == 1.5);
	t.insert("A", 100);
	assert(*(t.search("A")) == 100);

	cerr << "RadixTree tests Passed" << endl;

	AttributeTranslator at;
	at.Load("members.txt");

	
	testPP();

}

void testPP() {
	PersonProfile pp("jom", "jom@jom.com");
	assert(pp.GetNumAttValPairs() == 0);
	AttValPair pair1("dont", "change");
	AttValPair pair2("dont", "change");
	assert(!pp.GetAttVal(0, pair1));
	assert(pair1 == pair2);

	AttValPair av1("1", "1");
	AttValPair av2("2", "2");
	AttValPair av3("3", "3");
	AttValPair av4("4", "4");
	pp.AddAttValPair(av1);
	pp.AddAttValPair(av2);
	pp.AddAttValPair(av3);
	pp.AddAttValPair(av4);

	AttValPair av;
	assert(pp.GetNumAttValPairs() == 4);

	assert(pp.GetAttVal(0, av));
	assert(av == av1);

	assert(pp.GetAttVal(1, av));
	assert(av == av2);

	assert(pp.GetAttVal(2, av));
	assert(av == av3);

	assert(pp.GetAttVal(3, av));
	assert(av == av4);
	cerr << "PersonProfile tests passed" << endl;
}
#endif