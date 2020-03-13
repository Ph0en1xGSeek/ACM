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
	void recoverTree(TreeNode *root) {
		if(root == nullptr) {
			return;
		}
		TreeNode *cur = root, *pre = nullptr, *start = nullptr, *tail = nullptr;
		while(cur != nullptr) {
			if(cur->left != nullptr) {
				TreeNode *tmp = cur->left;
				while(tmp->right != nullptr && tmp->right != cur) {
					tmp = tmp->right;
				}
				if(tmp->right == cur) {
                    tmp->right = nullptr;
					if(pre != nullptr && pre->val > cur->val) {
						if(start == nullptr) {
							start = pre;
						}
						tail = cur;
					}
					pre = cur;
                    cur = cur->right;
				}else {
					tmp->right = cur;
					cur = cur->left;
				}
			}else {
				if(pre != nullptr && pre->val > cur->val) {
					if(start == nullptr) {
						start = pre;
					}
					tail = cur;
				}
				pre = cur;
                cur = cur->right;
			}
		}
		swap(start->val, tail->val);
	}
};