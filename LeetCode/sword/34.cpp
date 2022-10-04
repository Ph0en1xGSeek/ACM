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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        dfs(root, target, cur, res);
        return res;
    }

    void dfs(TreeNode *node, int target, vector<int> &cur, vector<vector<int>> &res) {
        cur.push_back(node -> val);
        int subTarget = target - (node -> val);
        if (node -> left == nullptr && node -> right == nullptr) {
            if (subTarget == 0) {
                res.push_back(cur);
                cur.pop_back();
                return;
            }
        }
        if (node -> left != nullptr) {
            dfs(node -> left, subTarget, cur, res);
        }
        if (node -> right != nullptr) {
            dfs(node -> right, subTarget, cur, res);
        }
        cur.pop_back();
    }
};