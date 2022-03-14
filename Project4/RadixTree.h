#ifndef RADIX_TREE_H
#define RADIX_TREE_H

#include <string>
#include <list>
#include <utility>
#include <unordered_map>

template <typename ValueType>
class RadixTree {
public:
	RadixTree() : m_root(nullptr) {
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
		insert(key, value, m_root);


		//ValueType v = value;
		//m_map->insert_or_assign(key, v);
	}

	/**
	* Returns pointer to value of specified key
	* Returns nullptr if no key in tree
	*/
	ValueType* search(std::string key) const {
		auto p = m_map->find(key);
		if (p == m_map->end())
			return nullptr;
		return &(*(p)).second;
	}
private:
	struct Node {
		Node() : m_key(""), isEnd(false), m_value(nullptr), m_parent(nullptr) {
			for (int i = 0; i < 127; i++)
				m_next[i] = nullptr;
		}
		Node(std::string k) : m_key(k), isEnd(true), m_value(nullptr), m_parent(nullptr) {
			for (int i = 0; i < 127; i++)
				m_next[i] = nullptr;
		}
		Node(std::string k, bool end) : m_key(k), isEnd(end), m_value(nullptr), m_parent(nullptr) {
			for (int i = 0; i < 127; i++)
				m_next[i] = nullptr;
		}
		std::string m_key;
		bool isEnd;

		ValueType* m_value;
		Node* m_next[127];
		Node* m_parent;
	};

	void insert(std::string key, const ValueType& value, Node*& curr) {
		if (curr == nullptr) {
			curr = new Node(key);
			curr->m_value = new ValueType(value);
			
			return;
		}
		std::string currKey = curr->m_key;
		int length = (key.size() >= currKey.size()) ? key.size() : currKey.size();
		for (int i = 0; i < length; i++) {
			//reach end of currKey
			if (i == currKey.size()) {

			}

			//reach end of inputted key
			if (i == key.size()) {
				//split off rest of currKey into child node
				curr->m_key = currKey.substr(0, i);
				currKey = currKey.substr(i + 1);
				insert(currKey.substr(i + 1), , curr->m_next[currKey[i + 1]]);
				curr->isEnd = true;	//this is now an end node
				curr->m_value = new ValueType(value);
			}

			//reach end of both at same time 
			//make curr node also an end node OR
			//means inputted key is already in tree

			//if neither is at end of string
			if (key[i] != currKey[i]) {
				//check if end node
				if (curr->isEnd == true) {
					curr->isEnd = false;
					ValueType* temp = curr->m_value;
					curr->m_value = nullptr;
					curr->m_key = currKey.substr(0, i);
					key = key.substr(i);

					insert(currKey.substr(i), *temp, curr->m_next[currKey[i]]);
					insert(key, value, curr->m_next[key[0]]);
				}
				else {
					curr->m_key = currKey.substr(0, i);
					key = key.substr(i);

					insert(currKey.substr(i), *temp, curr->m_next[currKey[i]]);
					insert(key, value, curr->m_next[key[0]]);
				}

				

				//check that not at end of string
				/*if ((i + 1) != currKey.size()) {
					insert(currKey.substr(i+1), value, curr->m_next[currKey[i + 1] - 'a']);
				}*/
				/*if (key.size() != 0) {
					insert(key, value, curr->m_next[key[i + 1] - 'a']);
				}*/
			 }
		}

	}

	Node* m_root;
	//TODO: implement
	std::unordered_map<std::string, ValueType>* m_map;
};



//template <typename ValueType>
//class RadixTree {
//public:
//	RadixTree() {
//		m_map = new std::unordered_map<std::string, ValueType>;
//	}
//	~RadixTree() {
//		delete m_map;
//	}
//
//	/**
//	* Inserts pair into tree
//	* Replaces value with new value if key is already in map
//	*/
//	void insert(std::string key, const ValueType& value) {
//		ValueType v = value;
//		m_map->insert_or_assign(key, v);
//		//m_map.insert_or_assign(key, &value);
//		//m_map->insert_or_assign(key, &value);
//	}
//
//	/**
//	* Returns pointer to value of specified key
//	* Returns nullptr if no key in tree
//	*/
//	ValueType* search(std::string key) const {
//		auto p = m_map->find(key);
//		if (p == m_map->end())
//			return nullptr;
//		return &(*(p)).second;
//		//return &(*(m_map->find(key))).second;
//
//
//		//return (*(m_map.find(key))).second;
//		//ValueType* out = &(*(m_map->find(key))).second;
//		//return out ;
//	}
//private:
//	//TODO: implement
//	std::unordered_map<std::string, ValueType>* m_map;
//	//std::unordered_map<std::string, ValueType*> m_map;
//	//std::unordered_map<std::string, ValueType*>* m_map;
//};

#endif