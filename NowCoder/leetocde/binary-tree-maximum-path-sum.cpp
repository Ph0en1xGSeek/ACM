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
    int dfs(TreeNode *node, int &ans) {
        if(node == nullptr) {
            return 0;
        }
        int left_sum = dfs(node->left, ans);
        int right_sum = dfs(node->right, ans);
        ans = max(ans, left_sum + right_sum + node->val);
        return max(max(left_sum, right_sum) + node->val, 0);
    }
    
    int maxPathSum(TreeNode *root) {
        if(root == nullptr) {
            return 0;
        }
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};