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
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left != NULL){
                TreeNode* tmp = cur->left;
                while(tmp->right != NULL){
                    tmp = tmp->right;
                }
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};