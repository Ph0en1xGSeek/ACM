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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) {
            return false;
        }
        if (check(A, B)) {
            return true;
        }
        if (isSubStructure(A -> left, B)) {
            return true;
        }
        if (isSubStructure(A -> right, B)) {
            return true;
        }
        return false;
    }

    bool check(TreeNode *A, TreeNode *B) {
        if (B == nullptr) {
            return true;
        } else if (A == nullptr) {
            return false;
        }
        if (A -> val != B -> val) {
            return false;
        }
        if (!check(A -> left, B -> left)) {
            return false;
        }
        if (!check(A -> right, B -> right)) {
            return false;
        }
        return true;
    }
};