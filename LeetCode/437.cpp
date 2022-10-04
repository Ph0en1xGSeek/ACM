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
    void dfs1(TreeNode *cur, int sum, int &cnt) {
        if(cur == nullptr) {
            return;
        }
        dfs2(cur, sum, 0, cnt);
        
        dfs1(cur->left, sum, cnt);
        dfs1(cur->right, sum, cnt);
    }
    
    void dfs2(TreeNode *cur, int sum, int cur_sum, int &cnt) {
        if(cur == nullptr) {
            return;
        }
        if(sum == cur_sum + cur->val) {
            ++cnt;
        }
        dfs2(cur->left, sum, cur_sum + cur->val, cnt);
        dfs2(cur->right, sum, cur_sum + cur->val, cnt);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int cnt = 0;
        dfs1(root, sum, cnt);
        return cnt;
    }
};