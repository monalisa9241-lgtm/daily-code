// BFS or Breadth First Search is a tree traversal algorithm that explores all the nodes at the present depth level before moving on to the nodes at the next depth level. 
// It can be implemented using a queue. 
// find the shortest path to a specific destination in a tree
// to process the tree level by level, which can be useful for certain applications like printing the tree in a level order format or finding the maximum width of the tree at any level.
// Time complexity: O(n) where n is the number of nodes in the tree, as each node is visited once.
// Space complexity: O(w) where w is the maximum width of the tree, which is the maximum number of nodes at any level. 
// In the worst case (a complete binary tree), this can be O(n/2) = O(n).


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void BFS(TreeNode* root) {
	if (root == NULL) return;
	queue<TreeNode*> q;
	while (!q.empty()) {
		TreeNode* current = q.front();
		q.pop();
		// Process the current node (for example, print its value)
		cout << current->val << " ";
		// Enqueue left child if it exists
		if (current->left != NULL) {
			q.push(current->left);
		}
		// Enqueue right child if it exists
		if (current->right != NULL) {
			q.push(current->right);
		}
	}
}