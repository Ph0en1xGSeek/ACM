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
    void dfs(TreeNode *cur, int deep, vector<int> &right_most){
        if(deep + 1 > right_most.size()){
            right_most.push_back(cur->val);
        }else{
            right_most[deep] = cur->val;
        }
        if(cur->left != nullptr){
            dfs(cur->left, deep+1, right_most);
        }
        if(cur->right != nullptr){
            dfs(cur->right, deep+1, right_most);
        }
        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_most;
        if(root == nullptr){
            return right_most;
        }
        dfs(root, 0, right_most);
        return right_most;
    }
};