// Morris Traversal (Inorder)
// Time : O(n)
// Space : O(1)

// temporarily link predecessor

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

vector<int> morris_traversal_inorder(TreeNode* root)
{
	vector<int> res;
	TreeNode* curr = root;

	while (curr)
	{
		if (!curr->left) {
			res.push_back(curr->val);
			curr = curr->right;
		} else {
			TreeNode* predecessor = curr->left;
			while (predecessor->right && predecessor->right != curr) {
				predecessor = predecessor->right;
			}
			if (!predecessor->right) {
				predecessor->right = curr; // create a temporary link
				curr = curr->left;
			} else {
				predecessor->right = NULL; // remove the temporary link
				res.push_back(curr->val);
				curr = curr->right;
			}
		}
	}
}