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
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        TreeNode *pre = nullptr;
        TreeNode *cur = root;
        while(cur != nullptr) {
            TreeNode *tmp = cur->left;
            if(tmp != nullptr) {
                while(tmp->right != nullptr && tmp->right != cur) {
                    tmp = tmp->right;
                }
                if(tmp->right == cur) {
                    tmp->right = nullptr;
                    if(pre != nullptr && pre->val >= cur->val) {
                        flag = false;
                    }
                    pre = cur;
                    cur = cur->right;
                }else {
                    tmp->right = cur;
                    cur = cur->left;
                }
            }else {
                if(pre != nullptr && pre->val >= cur->val) {
                    flag = false;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return flag;
    }
};