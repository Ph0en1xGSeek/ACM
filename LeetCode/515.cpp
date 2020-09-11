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
    vector<int> largestValues(TreeNode* root) {
        vector<int> mx;
        dfs(root, 0, mx);
        return mx;
    }

    void dfs(TreeNode *cur, int depth, vector<int> &mx) {
        if(cur == nullptr) {
            return;
        }
        if(depth >= mx.size()) {
            mx.push_back(INT_MIN);
        }
        if(cur->val > mx[depth]) {
            mx[depth] = cur->val;
        }
        dfs(cur->left, depth + 1, mx);
        dfs(cur->right, depth + 1, mx);
    }
};