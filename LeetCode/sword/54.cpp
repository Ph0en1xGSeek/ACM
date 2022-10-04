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
    int kthLargest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }
        int ans = -1;
        dfs(root, k, ans);
        return ans;
    }

    void dfs(TreeNode *cur, int &k, int &ans) {
        if (cur -> right != nullptr) {
            dfs(cur -> right, k, ans);
            if (k == 0) {
                return;
            }
        }
        --k;
        if (k == 0) {
            ans = cur -> val;
            return;
        }
        if (cur -> left != nullptr) {
            dfs(cur -> left, k, ans);
            if (k == 0) {
                return;
            }
        }
    }
};