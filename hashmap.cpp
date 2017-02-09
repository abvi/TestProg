#include <string>

class Hashmap {
public:
	const int NUM_CELLS = 1000;

	struct Node { int key; string val; Node *next; };
	Node *entries[NUM_CELLS];

	void set(int key, string val) {
		int index = hash(key);
		if (entries[index] == NULL) {
			Node *n = new Node;
			n->key = key;
			n->val = val;
			n->next = NULL;
			entries[index] = n;
		} else {
			// hash collision
			Node *nodePtr = entries[index];
			while (nodePtr->next && nodePtr->key != key) {
				nodePtr++;
			}

			if (nodePtr && nodePtr->key == key) {
				// replace it
				nodePtr->val = val;
			} else {
				// we've reached the end, add a new entry
				Node *n = new Node;
				n->key = key;
				n->val = val;
				n->next = NULL;
				nodePtr->next = n;
			}
		}
	}

	string get(int key) {
		int index = hash(key);
		if (entries[index] == NULL) {
			return NULL;
		}

		// iterate over the linked list attached to this entry
		Node *nodePtr = entries[index];
		while (nodePtr) {
			if (nodePtr->key == key) {
				return nodePtr->val;
			}
		}
		return NULL;
	}

private:
	int hash(int key) {
		return key % NUM_CELLS;
	}
};