// DFS or Depth First Search is a tree traversal algorithm that explores as far as possible along each branch before backtracking. It can be implemented using recursion or an explicit stack. 
// Below is an example of how to implement DFS for a binary tree in C++.

// Preorder Traversal (Root, Left, Right)

// time complexity: O(n) where n is the number of nodes in the tree, as each node is visited once.
// Space complexity: O(h) where h is the height of the tree, due to the recursive call stack. In the worst case (a skewed tree), this can be O(n).

//using stack minimizes the space complexity to O(h) in the worst case, 
// which is more efficient than the recursive approach for skewed trees.

// iterative approach using stack is often preferred in practice to avoid potential stack overflow issues with deep recursion, 
// especially in cases of skewed trees.

// for preorder traversal push the root to stack first, then push the right child and left child to stack.

#include <iostream>
#include <stack>
#include <vector>	
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderTraversal_recursion(TreeNode* root)
{
	if (!root) return;
	cout << root->val << " ";
	preorderTraversal_recursion(root->left);
	preorderTraversal_recursion(root->right);
}

vector<int> preorderTraversal_iterative(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	if (root) st.push(root);

	while (!st.empty()) {
		TreeNode* node = st.top();	
		st.pop();
		res.push_back(node->val);

		if (node->right) st.push(node->right);
		if (node->left) st.push(node->left);
	}
	return res;
}