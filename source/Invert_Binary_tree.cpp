//Given the root of a binary tree, invert the tree, and return its root.
// if root = nullptr, return nullptr.

// Iterative approach using DFS with a stack
// Time complexity: O(n), where n is the number of nodes in the tree.
// Space complexity: O(h), where h is the height of the tree (stack space).

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root)
{
	if (root == nullptr)
		return root;
	std::stack<TreeNode*> nodeStack;
	nodeStack.push(root);

	while (!nodeStack.empty())
	{
		TreeNode* current = nodeStack.top();
		nodeStack.pop();

		if (current->left)
			nodeStack.push(current->left);
		if (current->right)
			nodeStack.push(current->right);

		std::swap(current->left, current->right);
	}

	return root;
}

//Using recursion
// Time complexity: O(n), where n is the number of nodes in the tree.
// Space complexity: O(h), where h is the height of the tree (recursive call stack space).

TreeNode* invertTreeRecursive(TreeNode* root)
{
	if (root == nullptr)
		return root;
	TreeNode* leftInverted = invertTreeRecursive(root->left);
	TreeNode* rightInverted = invertTreeRecursive(root->right);
	root->left = rightInverted;
	root->right = leftInverted;
	return root;
}