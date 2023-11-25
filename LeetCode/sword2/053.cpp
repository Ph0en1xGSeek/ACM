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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p == nullptr) {
            return nullptr;
        }
        TreeNode *cur = nullptr;
        if (p -> right != nullptr) {
            cur = p -> right;
            while (cur -> left != nullptr) {
                cur = cur -> left;
            }
            return cur;
        }
        int val = p -> val;
        cur = root;
        TreeNode *pre = nullptr;
        while (cur != nullptr) {
            if (cur -> val == val) {
                break;
            } else if (cur -> val > val) {
                pre = cur;
                cur = cur -> left;
            } else {
                cur = cur -> right;
            }
        }
        return pre;
    }
};