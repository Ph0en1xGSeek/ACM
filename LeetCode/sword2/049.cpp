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
private:
    int ans = 0;
public:
    void dfs(TreeNode *cur, int pre_sum) {
        if (cur == nullptr) {
            return;
        }
        int sum = pre_sum * 10 + cur -> val;
        if (cur -> left == nullptr && cur -> right == nullptr) {
            ans += sum;
            return;
        }
        dfs(cur -> left, sum);
        dfs(cur -> right, sum);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};