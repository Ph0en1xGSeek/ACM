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
    
    void dfs(TreeNode *cur, int deep, int &mx_deep, int &ans) {
        if(cur->left == nullptr && cur->right == nullptr) {
            if(deep > mx_deep) {
                ans = cur->val;
                mx_deep = deep;
            }
            return;
        }
        if(cur->left != nullptr) {
            dfs(cur->left, deep+1, mx_deep, ans);
        }
        if(cur->right != nullptr) {
            dfs(cur->right, deep+1, mx_deep, ans);
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int mx_deep = -1;
        int ans = 0;
        dfs(root, 0, mx_deep, ans);
        return ans;
    }
};