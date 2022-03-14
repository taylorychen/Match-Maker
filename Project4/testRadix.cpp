#define TEST_TREE
#ifdef TEST_TREE

#include "RadixTree.h"
#include "PersonProfile.h"
#include "AttributeTranslator.h"
#include "MemberDatabase.h"
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

void testTranslate();
void testDatabase();
void testPP();
void testTree();

int main() {
	


	testTree();
	//testPP();
	//testDatabase();
	//testTranslate();

}

void testTranslate() {
	AttributeTranslator at;
	assert(at.Load("translatorS.txt"));

	//test duplicates
	//only one way matching
	AttValPair att("favorite_food", "del taco");
	vector<AttValPair> result = at.FindCompatibleAttValPairs(att);
	if (!result.empty()) {
		std::cerr << "Compatible attributes and values:" << std::endl;
		for (const auto& p : result)
			std::cerr << p.attribute << " -> " << p.value << std::endl;
	}
	cerr << "\n";
	AttValPair att2("favorite_food", "taco bell");
	vector<AttValPair> result2 = at.FindCompatibleAttValPairs(att2);
	if (!result2.empty()) {
		std::cerr << "Compatible attributes and values:" << std::endl;
		for (const auto& p : result2)
			std::cerr << p.attribute << " -> " << p.value << std::endl;
	}
	cerr << "\n";
	//no matches
	AttValPair att3("favorite_food", "albertacos");
	vector<AttValPair> result3 = at.FindCompatibleAttValPairs(att3);
	assert(result3.empty());
}

void testDatabase() {
	MemberDatabase md;
	md.LoadDatabase("membersS.txt");

	AttValPair a("hobby", "painting");
	vector<string> vm = md.FindMatchingMembers(a);
	for (int i = 0; i < vm.size(); i++) {
		cerr << "(" << i+1 << ")\t" << vm[i] << "\n";
	}

	AttValPair every("hobby", "canyoneering");
	vector<string> vm2 = md.FindMatchingMembers(every);
	for (int i = 0; i < vm2.size(); i++) {
		cerr << "(" << i+1 << ")\t" << vm2[i] << "\n";
	}

	AttValPair none("trait", "zany");
	vector<string> vm3 = md.FindMatchingMembers(none);
	for (int i = 0; i < vm3.size(); i++) {
		cerr << "(" << i+1 << ")\t" << vm3[i] << "\n";
	}

	MemberDatabase empty;
	assert(empty.LoadDatabase("empty.txt"));


	assert((*md.GetMemberByEmail("LWall@sky.com")).GetName() == "Leon Wallace");
	assert((*md.GetMemberByEmail("EmiliTy3@charter.net")).GetName() == "Emilio Tyson");

	cerr << "MemberDatabase tests passed" << endl;
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

	assert(!pp.GetAttVal(5, av));

	pp.AddAttValPair(av1);
	assert(pp.GetNumAttValPairs() == 4);

	cerr << "Person Profile tests passed" << endl;
}

void testTree() {
	//RadixTree<double> t;
	//t.insert("AB", 1.2);
	//t.insert("AC", 1.3);
	//assert(*(t.search("A")) - 1.5 <= 0.001);
	//t.insert("A", 1.5);
	//assert(*(t.search("A")) == 1.5);
	//t.insert("A", 100);
	//assert(*(t.search("A")) == 100);

	//reach end of currKey
	//RadixTree<int> a;
	//a.insert("myA", 1);
	//a.insert("myfav", -1);
	//a.insert("myfav", 2); //replacing a value
	//a.insert("myfavA", 3); //existing key is a substring of key

	//same as above but testing on top node
	RadixTree<int> a2;
	a2.insert("fav", -1);
	a2.insert("fav", 2); //replacing a value
	a2.insert("favA", 3); //existing key is a substring of key

	//RadixTree<int> b;
	//b.insert("myA", 1);
	//b.insert("myfavA", 3);
	//b.insert("myfavB", 4); //key forces creation of 2 edges
	//b.insert("myfav", 2);
	//key is substring of existing key

	//same as above but testing on top node
	RadixTree<int> b2;
	b2.insert("favA", 3);
	b2.insert("favB", 4); //key forces creation of 2 edges
	b2.insert("fav", 2);
	//key is substring of existing key

	RadixTree<int> c;
	c.insert("myA", 1);
	c.insert("myfavA", 2);
	c.insert("myfavAB", 4);
	c.insert("myfavAC", 5);
	c.insert("myfavD", 3);	//forces creation of 2 edges, non-leaf node

	//same as above but testing on top node
	RadixTree<int> c2;
	c2.insert("favA", 2);
	c2.insert("favAB", 4);
	c2.insert("favAC", 5);
	c2.insert("favD", 3);	//forces creation of 2 edges, non-leaf node

	RadixTree<int> d;
	d.insert("ABC", 1);
	d.insert("XYZ", 9);	//no common letters

	RadixTree<int> e;
	e.insert("myfav", 2);
	e.insert("my", 1);	//key breaks a node in two

	cerr << "RadixTree tests Passed" << endl;
}


#endif