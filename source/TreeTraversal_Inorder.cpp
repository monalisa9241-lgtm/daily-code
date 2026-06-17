// Inorder Traversal (Left, Root, Right)
// time complexity: O(n) where n is the number of nodes in the tree, as each node is visited once.
// Space complexity: O(h) where h is the height of the tree, due to the recursive call stack. In the worst case (a skewed tree), this can be O(n).

// using stack minimizes the space complexity to O(h) in the worst case,
// Iterative approach using stack is often preferred in practice to avoid potential stack overflow issues with deep recursion,
// especially in cases of skewed trees.

// for inorder traversal, we need to push the left child to stack first, then push the root and right child to stack.

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

vector<int> inorderTraversal_iterative(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	TreeNode* curr = root;	

	while (curr || !st.empty())
	{
		while (curr) {
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		res.push_back(curr->val);
		curr = curr->right;
	}
	return res;	
}

void inorderTraversal_recursion(TreeNode* root)
{
	if (!root) return;
	inorderTraversal_recursion(root->left);
	cout << root->val << " ";
	inorderTraversal_recursion(root->right);
}