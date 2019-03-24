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
    long long mx_val = -0x7fffffffffff;
    TreeNode *pre, *start, *tail;

    void isValidBST(TreeNode* root) {
        if(root == NULL){
            return;
        }
        isValidBST(root->left);
        if(mx_val >= root->val){
            if(start == NULL){
                start = pre;
            }
            tail = root;
        }
        pre = root;
        mx_val = root->val;
        isValidBST(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL){
            return;
        }
        isValidBST(root);
        swap(start->val, tail->val);
    }
};

