/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int height(TreeNode *node, bool &flag) {
		if(node == nullptr) {
			return 0;
		}
		int left_h = height(node->left, flag);
		if(!flag) {
			return 0;
		}
		int right_h = height(node->right, flag);
		if(flag && left_h - right_h <= 1 && left_h - right_h >= -1) {
			return max(left_h, right_h) + 1;
		}else {
			flag = false;
			return 0;
		}
	}

	bool isBalanced(TreeNode *root) {
		bool flag = true;
		height(root, flag);
		return flag;
	}
};