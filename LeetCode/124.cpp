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
    
    int dfs(TreeNode* cur, int& mx){
        if(cur == NULL){
            return 0;
        }
        int left = dfs(cur->left, mx);
        int right = dfs(cur->right, mx);
        int ret = max(left + cur->val, right + cur->val);
        if(ret < 0){
            ret = 0;
        }
        mx = max(mx, left + right + cur->val);
        return ret;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int mx = -0x7fffffff;
        dfs(root, mx);
        return mx;
    }
};