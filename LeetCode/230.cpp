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
    
    bool dfs(TreeNode *cur, int k, int &res, int &cnt) {
        if(cur == nullptr) {
            return false;
        }
        if(dfs(cur->left, k, res, cnt) == true) {
            return true;
        }
        ++cnt;
        if(cnt == k) {
            res = cur->val;
            return true;
        }
        if(dfs(cur->right, k, res, cnt) == true) {
            return true;
        }
        return false;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, res = 0;
        dfs(root, k, res, cnt);
        return res;
    }
};