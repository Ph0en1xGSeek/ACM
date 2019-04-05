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
    void dfs(TreeNode *cur, vector<int> &res){
        res.push_back(cur->val);
        if(cur->left != NULL){
            dfs(cur->left, res);
        }
        if(cur->right != NULL){
            dfs(cur->right, res);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        dfs(root, res);
        return res;
    }
};