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
	vector<TreeNode *> dfs(int from, int to, vector<vector<vector<TreeNode*> > > &memo) {
		if(from > to) {
			return {nullptr};
		}
		if(!memo[from-1][to-1].empty()) {
			return memo[from-1][to-1];
		}
		vector<TreeNode *> ret;
		for(int i = from; i <= to; ++i) {
			vector<TreeNode *> left = dfs(from, i-1, memo);
			vector<TreeNode *> right = dfs(i+1, to, memo);
			for(auto left_ch: left) {
				for(auto right_ch: right) {
					TreeNode *node = new TreeNode(i);
					node->left = left_ch;
					node->right = right_ch;
					ret.push_back(node);
				}
			}
		}
		return (memo[from-1][to-1] = ret);
	}

	vector<TreeNode *> generateTrees(int n) {
		if(n <= 0) {
			return {nullptr};
		}
		vector<vector<vector<TreeNode*> > > memo(n, vector<vector<TreeNode*>>(n));
		return dfs(1, n, memo);
	}
};
