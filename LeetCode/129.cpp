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
    void dfs(TreeNode* cur, long long curSum, long long& ans){
        if(cur->left == NULL && cur->right == NULL){
            ans += curSum;
            return;
        }
        if(cur->left != NULL){
            dfs(cur->left, curSum*10 + cur->left->val, ans);
        }
        if(cur->right != NULL){
            dfs(cur->right, curSum*10 + cur->right->val, ans);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        long long ans = 0;
        if(root == NULL){
            return 0;
        }
        dfs(root, root->val, ans);
        return ans;
    }
};