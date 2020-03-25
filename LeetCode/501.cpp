/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void dfs(TreeNode *node, int &cnt, int &mx, TreeNode *&pre, vector<int> &ans) {
		if(node == nullptr) {
			return;
		}
		dfs(node->left, cnt, mx, pre, ans);
		if(pre == nullptr || pre->val == node->val) {
			++cnt;
		}else {
			if(cnt > mx) {
				ans.clear();
				ans.push_back(pre->val);
				mx = cnt;
			}else if(cnt == mx) {
				ans.push_back(pre->val);
			}
			cnt = 1;
		}
		pre = node;
		dfs(node->right, cnt, mx, pre, ans);
	}
 
	vector<int> findMode(TreeNode *root) {
		vector<int> ans;
		if(root == nullptr) {
			return ans;
		}
		int cnt = 0, mx = 0;
        TreeNode *pre;
		dfs(root, cnt, mx, pre, ans);
        if(cnt > mx) {
            ans.clear();
            ans.push_back(pre->val);
        }else if(cnt == mx) {
            ans.push_back(pre->val);
        }
		return ans;
	}
};