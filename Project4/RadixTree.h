#ifndef RADIX_TREE_H
#define RADIX_TREE_H

#include <string>
#include <unordered_map>

template <typename ValueType>
class RadixTree {
public:
	RadixTree() {
		m_map = new std::unordered_map<std::string, ValueType>;
	}
	~RadixTree() {
		delete m_map;
	}

	/**
	* Inserts pair into tree
	* Replaces value with new value if key is already in map
	*/
	void insert(std::string key, const ValueType& value) {
		m_map->insert_or_assign(key, value);
	}

	/**
	* Returns pointer to value of specified key
	* Returns nullptr if no key in tree
	*/
	ValueType* search(std::string key) const {
		return &(*(m_map->find(key))).second;
	}
private:
	//TODO: implement
	std::unordered_map<std::string, ValueType>* m_map;
};

#endif