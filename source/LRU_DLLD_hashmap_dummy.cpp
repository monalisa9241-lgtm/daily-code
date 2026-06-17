// design a LRU cache using a double linked list and a hashmap , and dummy nodes to avoid edge cases
// Objective: need fast look up and ordered structure that supports O(1) updates
//vector : shifting elements is costly O(n) , but in DLL we can remove and insert nodes in O(1) time
// only hashmap: O(1) for get and put, but we need to maintain the order of usage, 
// so we use a DLL to keep track of the order of usage (LRU at head, MRU at tail)

//without dummy nodes, we need to handle edge cases when the list is empty or has only one node,
// Edge Cases:
// 1. When the cache is empty and we try to get a key, we need to check if the list is empty
// 2. When the cache has only one node, we need to handle the removal of that node carefully        
//with dummy nodes, we can avoid these edge cases and simplify the code
/*
1. Put(key, value)
1.1 - Remove a KV pair from LRU end of the cache
1.2 - Add a kv pair to the MRU end of the cache
2. get(key)
2.3 - Move KV pair to MRU end of the cache
2.4 - Access a value using its key
*/

#include <unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;

    Node* head; // dummy head (LRU side)
    Node* tail; // dummy tail (MRU side)

    // Remove node from DLL
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node at MRU position (just before tail)
    void insertToMRU(Node* node) {
        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
    }

    // Move existing node to MRU
    void moveToMRU(Node* node) {
        removeNode(node);
        insertToMRU(node);
    }

    // Remove LRU node (just after head)
    Node* removeLRU() {
        Node* lru = head->next;
        removeNode(lru);
        return lru;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0); // dummy
        tail = new Node(0, 0); // dummy

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        moveToMRU(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToMRU(node);
        }
        else {
            if ((int)cache.size() == capacity) {
                Node* lru = removeLRU();
                cache.erase(lru->key);
                delete lru;
            }

            Node* node = new Node(key, value);
            cache[key] = node;
            insertToMRU(node);
        }
    }

    // Destructor to avoid memory leaks
    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};