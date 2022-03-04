#define TEST_TREE
#ifdef TEST_TREE

#include "RadixTree.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
	RadixTree<double> t;
	t.insert("A", 1.5);
	assert(*(t.search("A")) == 1.5);
	t.insert("A", 1.5);
	assert(*(t.search("A")) == 1.5);
	t.insert("A", 100);
	assert(*(t.search("A")) == 100);

	cerr << "RadixTree tests Passed" << endl;
}

#endif