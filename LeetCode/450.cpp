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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur = root, *pre = nullptr;
        while(cur != nullptr) {
            if(cur->val == key) {
                break;
            }else if(cur->val > key) {
                pre = cur;
                cur = cur->left;
            }else {
                pre = cur;
                cur = cur->right;
            }
        }
        if(cur != nullptr) {
            if(cur->left == nullptr && cur->right == nullptr) {
                if(pre == nullptr) {
                    root = nullptr;
                }else if(cur == pre->left){
                    pre->left = nullptr;
                }else if(cur == pre->right) {
                    pre->right = nullptr;
                }
                delete cur;
            }else if(cur->left == nullptr) {
                if(pre == nullptr) {
                    root = cur->right;
                }else if(cur == pre->left) {
                    pre->left = cur->right;
                }else if(cur == pre->right) {
                    pre->right = cur->right;
                }
                delete cur;
            }else if(cur->right == nullptr) {
                if(pre == nullptr) {
                    root = cur->left;
                }else if(cur == pre->left) {
                    pre->left = cur->left;
                }else if(cur == pre->right) {
                    pre->right = cur->left;
                }
                delete cur;
            }else {
                TreeNode *newcur = cur->left;
                pre = cur;
                while(newcur->right != nullptr) {
                    pre = newcur;
                    newcur = newcur->right;
                }
                cur->val = newcur->val;
                if(newcur == pre->left) {
                    pre->left = newcur->left;
                }else {
                    pre->right = newcur->left;
                }
                delete newcur;
            }
        }        
        return root;
    }
};