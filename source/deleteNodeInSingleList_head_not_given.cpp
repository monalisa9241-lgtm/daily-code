//There is a singly-linked list head and we want to delete a node node in it.

//You are given the node to be deleted node.You will not be given access to the first node of head.

//All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

//Delete the given node.Note that by deleting the node, we do not mean removing it from memory.We mean :

//The value of the given node should not exist in the linked list.
//The number of nodes in the linked list should decrease by one.
//All the values before node should be in the same order.
//All the values after node should be in the same order.

// Approach : Data Overwriting

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Overwrite data of next node on current node.
        node->val = node->next->val;
        // Make current node point to next of next node.
        node->next = node->next->next;
    }
};