/**
 * Implement LRU cache implementation using doubly linked list. 
 * 
 * The idea is to use an doubly linked list.
 * Keep a fixed head pointer and a fixed tail pointer and a hash table of type <int, node*>
 * Whenever an already existing value is refered then remove is from the DLL and hash and insert it at front and store the new node address.
 * If a new value is inserted then always insert it at the front and store the new node address.
 * If the capacity of DLL is full then delete the last node (tail->prev) and erase it from hash table and then insert the new node.
 */
 

class LRUCache {
public:
	class node {
		public:
			int key;
			int val;
			node* next;
			node* prev;
			node(int _key, int _val) {
				key = _key;
				val = _val;
			}
	};

	node* head = new node(-1, -1);
	node* tail = new node(-1, -1);

	int capacity;
	unordered_map<int, node*> table;

	LRUCache(int capacity) {
		this.capacity = capacity;
		head->next = tail;
		tail->prev = head;
	}

	void addNode(node* newnode) {
		node* temp = head->next;
		head->next = newnode;
		newnode->prev = head;
		newnode->next = temp;
		temp->prev = newnode;
	}

	void deleteNode(node* delnode) {
		node* delprev = delnode->prev;
		node* delnext = delnode->next;
		delprev->next = delnext;
		delnext->prev = delprev;
		delete delnode;
	}

	int get(int key_) {
		if(table.find(key_) != table.end()) {
			node* resnode = table[key_];
			int value = resnode->val;
			
			// table.erase(key_);
			deleteNode(resnode);
			addNode(resnode);
			table[key_] = head->next;
			
			return value;
		}

		return -1;
	}

	void put(int key_, int value) {
		if(table.find(key_) != table.end()) {
			node* existingNode = table[key_];
			// table.erase(key_);
			deleteNode(existingNode); 
		}

		if(table.size() == capacity) {
			table.erase(tail->prev->key);
			deleteNode(tail->prev);
		}

		addNode(new node(key_, value));
		table[key_] = head->next;
	}
};

// ======================================================================================
   // An alternate solution using STL below
// ======================================================================================

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class lru{
	list<int> el;											//Doubly linked list to store the elements
	unordered_map<int, list<int>::iterator> ref;	//hashtable for storing the reference address
	int n;
	
	public:
	
		lru(int cap){
			n = cap;
		}

		void insert(int);
		void print();
};

void lru::insert(int val){
	
	if(ref.find(val) == ref.end()){	// if the value is not found in the list
		
		if(ref.size() == n){				//if the cache size is equal to the capacity
			
			int x = el.back();
			el.pop_back();					//removing the last element from the queue
         ref.erase(x); 					//erasing the key value pair from the hash table
		}
	}
	else{
		el.erase(ref[val]);	//if present erasing it (ref.find(val)->second)
	}
	
	el.push_front(val);		//adding the value to the front
	ref[val] = el.begin();		//storing the address in the hashtable
}

void lru::print(){
	
	for(auto it=el.begin(); it!=el.end(); it++)
		cout<<*it<<" ";
	
	cout<<endl;
}