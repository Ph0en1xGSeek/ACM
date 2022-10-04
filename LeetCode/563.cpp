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
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode *cur, int &tilt) {
        if(cur == nullptr) {
            return 0;
        }
        int l_sum = dfs(cur->left, tilt);
        int r_sum = dfs(cur->right, tilt);
        tilt += abs(l_sum - r_sum);
        return l_sum + r_sum + cur->val;
    }
};