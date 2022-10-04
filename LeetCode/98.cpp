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
    long long mx_val = -0x7fffffffffff;
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        if(!isValidBST(root->left)){
            return false;
        }
        if(mx_val >= root->val){
            return false;
        }
        mx_val = root->val;
        return isValidBST(root->right);
    }
};