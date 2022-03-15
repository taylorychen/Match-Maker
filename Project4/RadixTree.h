#ifndef RADIX_TREE_H
#define RADIX_TREE_H

#include <string>
#include <list>
#include <utility>
#include <unordered_map>

const int NUM_CHARS = 127;

template <typename ValueType>
class RadixTree {
public:
	RadixTree() : m_root(nullptr) {}
	~RadixTree() {
		deleteTree(m_root);

		//delete m_map;
	}

	/**
	* Inserts pair into tree
	* Replaces value with new value if key is already in map
	*/
	void insert(std::string key, const ValueType& value) {
		Node* parent = nullptr;
		insert(key, value, m_root, parent);
	}

	/**
	* Returns pointer to value of specified key
	* Returns nullptr if no key in tree
	*/
	ValueType* search(std::string key) const {
		return search(key, m_root);
	}
private:
	struct Node {
		Node() : m_key(""), isEnd(false), m_value(nullptr), m_parent(nullptr) {
			for (int i = 0; i < NUM_CHARS; i++)
				m_next[i] = nullptr;
		}
		Node(std::string k, ValueType* v) : m_key(k), isEnd(true), m_value(v), m_parent(nullptr) {
			for (int i = 0; i < NUM_CHARS; i++)
				m_next[i] = nullptr;
		}
		Node(std::string k, bool end) : m_key(k), isEnd(end), m_value(nullptr), m_parent(nullptr) {
			for (int i = 0; i < NUM_CHARS; i++)
				m_next[i] = nullptr;
		}
		std::string m_key;
		bool isEnd;

		ValueType* m_value;
		Node* m_next[NUM_CHARS];
		Node* m_parent;
	};

	void insert(std::string key, const ValueType& value, Node*& curr, Node*& parent) {
		if (curr == nullptr) {
			curr = new Node(key, new ValueType(value));
			return;
		}
		
		std::string currKey = curr->m_key;

		for (int i = 0;; i++) {
			//reach end of currKey
			if (i == currKey.size()) {
				if (i != key.size())	//if key is longer, go to next node
					insert(key.substr(i), value, curr->m_next[key[i]], curr);

				else {	//if both end at same time
					if (curr->m_value != nullptr) {	//if a value already stored here, delete
						delete curr->m_value;
					}
					curr->m_value = new ValueType(value);
					curr->isEnd = true;
				}
				return;
			}

			//reach end of inputted key
			else if (i == key.size()) {
				//factor out common part into parent node
				//this node is an end node and maps to inputted value
				curr->m_key = currKey.substr(i);
				Node* commonNode = new Node(currKey.substr(0, i), new ValueType(value));

				commonNode->m_next[currKey[i]] = curr;	//have it point to current node

				//set parent to point to this node
				if (parent == nullptr)
					m_root = commonNode;
				else
					parent->m_next[currKey[0]] = commonNode;


				return;
			}

			//if neither is at end of string
			else if (key[i] != currKey[i]) {
				//factor out common part into a super node
				curr->m_key = currKey.substr(i);
				Node* commonNode = new Node(currKey.substr(0, i), false);

				commonNode->m_next[currKey[i]] = curr;	//have it point to current node
				//create new node off of commonNode with rest of inputted key
				commonNode->m_next[key[i]] = new Node(key.substr(i), new ValueType(value));

				//set parent to point to this node
				if (parent == nullptr)
					m_root = commonNode;
				else
					parent->m_next[currKey[0]] = commonNode;

				return;
			}
		}
	}

	ValueType* search(std::string key, Node* curr) const {
		if (curr == nullptr)
			return nullptr;
		std::string currKey = curr->m_key;
		for (int i = 0;; i++) {
			//reach end of currKey
			if (i == currKey.size()) {
				if (i != key.size())	//if key is longer, go to next node
					return search(key.substr(i), curr->m_next[key[i]]);

				else {	//if both end at same time
					//return value
					if (curr->isEnd)
						return curr->m_value;
					return nullptr;
				}
			}

			//reach end of inputted key or don't match
			else if (i == key.size() || key[i] != currKey[i]) {
				return nullptr;
			}
		}
	}

	void deleteTree(Node*& curr) {
		for (int i = 0; i < NUM_CHARS; i++) {
			if (curr->m_next[i] != nullptr) {
				deleteTree(curr->m_next[i]);
			}
		}
		delete curr->m_value;
		delete curr;
	}

	Node* m_root;
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