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
    vector<int> dp(TreeNode *node) {
        if(node == nullptr) {
            return vector<int>({0, 0});
        }
        vector<int> ret(2);
        vector<int> from_left = dp(node->left);
        vector<int> from_right = dp(node->right);
        ret[0] = from_left[1] + from_right[1] + node->val;
        ret[1] = max(from_left[0], from_left[1]) + max(from_right[0], from_right[1]);
        return ret;
    }
    
    int rob(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        vector<int> ans = dp(root);
        return max(ans[0], ans[1]);
    }
};