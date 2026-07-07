// Given the root of a binary tree, return the sum of all left leaves.
// A leaf is a node with no children.A left leaf is a leaf that is the left child of another node.

#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

class solution {
public: 
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root) return 0;
		int sum = 0;
		dfs(root, false, sum);
		return sum;
	}
private:
		void dfs(TreeNode* node, bool isLeft, int& sum) {
		if (!node) return;
		if (!node->left && !node->right && isLeft) {
			sum += node->val;
		}
		dfs(node->left, true, sum);
		dfs(node->right, false, sum);
	}

};

