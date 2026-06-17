// Postorder Traversal (Left, Right, Root)
// time complexity: O(n) where n is the number of nodes in the tree, as each node is visited once.
// Space complexity: O(h) where h is the height of the tree, due to the recursive call stack. In the worst case (a skewed tree), this can be O(n).

// iterative approach using stack is often preferred in practice to avoid potential stack overflow issues with deep recursion, 
// especially in cases of skewed trees.
// Postorder traversal is a bit more complex than preorder and inorder because
// we need to ensure that we process the root node after processing both left and right subtrees.

// track last visited node to determine when to process the root node after processing both left and right subtrees.

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

vector<int> postOrder_iterative(TreeNode* root)
{
	vector<int> res;
	stack<TreeNode*> st;
	TreeNode* lastVisited = NULL;
	while (root || !st.empty()) {
		while (root) {
			st.push(root);
			root = root->left;
		}
		TreeNode* node = st.top();
		if (node->right && lastVisited != node->right) {
			root = node->right;
		} else {
			res.push_back(node->val);
			lastVisited = node;
			st.pop();
		}
	}
	return res;
}