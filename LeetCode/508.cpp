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
	int dfs(TreeNode *node, int &mx, unordered_map<int, int> &mp, vector<int> &ans) {
		if(node == nullptr) {
			return 0;
		}
		int left_sum = dfs(node->left, mx, mp, ans);
		int right_sum = dfs(node->right, mx, mp, ans);
		int sum = left_sum + right_sum + node->val;
		++mp[sum];
		if(mp[sum] > mx) {
			mx = mp[sum];
			ans.clear();
			ans.push_back(sum);
		}else if(mp[sum] == mx) {
			ans.push_back(sum);
		}
		return sum;
	}
	vector<int> findFrequentTreeSum(TreeNode *root) {
		vector<int> ans;
		if(root == nullptr ) {
			return ans;
		}
		unordered_map<int, int> mp;
		int mx = 0;
		dfs(root, mx, mp, ans);
		return ans;
	}
};
