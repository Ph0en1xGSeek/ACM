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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return check(root -> left, root -> right);
    }

    bool check(TreeNode *nodeA, TreeNode *nodeB) {
        if (nodeA == nullptr && nodeB == nullptr) {
            return true;
        } else if (nodeA == nullptr) {
            return false;
        } else if (nodeB == nullptr) {
            return false;
        }
        if (nodeA -> val != nodeB -> val) {
            return false;
        }
        if (check(nodeA -> left, nodeB -> right) && check(nodeA -> right, nodeB -> left)) {
            return true;
        }
        return false;
    }
};