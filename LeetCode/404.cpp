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
    void cnt(TreeNode *cur, bool left, int &sum) {
        if(cur->left == nullptr && cur->right == nullptr) {
            if(left) {
                sum += cur->val;
            }
            return;
        }
        if(cur->left != nullptr) {
            cnt(cur->left, true, sum);
        }
        if(cur->right != nullptr) {
            cnt(cur->right, false, sum);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == nullptr) {
            return sum;
        }
        cnt(root, false, sum);
        return sum;
    }
};