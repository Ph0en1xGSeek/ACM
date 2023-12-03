/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findTargetNode(TreeNode* root, int cnt) {
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur != nullptr) {
            TreeNode *tmp = cur -> right;
            if (tmp != nullptr) {
                while (tmp -> left != nullptr && tmp -> left != cur) {
                    tmp = tmp -> left;
                }
                if (tmp -> left == nullptr) {
                    tmp -> left = cur;
                    cur = cur -> right;
                } else {
                    tmp -> left = nullptr;
                    if (cnt) {
                        --cnt;
                        pre = cur;
                    }
                    cur = cur -> left;
                }
            } else {
                if (cnt) {
                    --cnt;
                    pre = cur;
                }
                cur = cur -> left;
            }
        }
        return pre -> val;
    }
};