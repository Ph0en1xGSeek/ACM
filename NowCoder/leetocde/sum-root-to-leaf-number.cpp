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
    void dfs(TreeNode *cur, int sum, int &ans) {
        sum = sum * 10 + cur->val;
        if(cur->left == nullptr && cur->right == nullptr) {
            ans += sum;
            return;
        }
        if(cur->left != nullptr)
            dfs(cur->left, sum, ans);
        if(cur->right != nullptr)
            dfs(cur->right, sum, ans);
    }
    
    int sumNumbers(TreeNode *root) {
        if(root == nullptr) {
            return 0;
        }
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};