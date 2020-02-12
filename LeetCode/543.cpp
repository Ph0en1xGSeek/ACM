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
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode *cur) {
        if(cur == nullptr) {
            return -1;
        }
        int l_deep = dfs(cur->left);
        int r_deep = dfs(cur->right);
        ans = max(ans, l_deep + r_deep + 2);
        return max(l_deep, r_deep) + 1;
    }
private:
    int ans = 0;
};