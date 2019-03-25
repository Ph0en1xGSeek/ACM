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
    void dfs(TreeNode* node, int depth, vector<vector<int>>& result){
        if(node == NULL){
            return;
        }
        if(depth >= result.size()){
            result.push_back(vector<int>(0));
        }
        result[depth].push_back(node->val);
        dfs(node->left, depth+1, result);
        dfs(node->right, depth+1, result);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        dfs(root, 0, result);
        return result;
    }
};