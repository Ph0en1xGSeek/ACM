/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        TreeNode *cur = root;
        while(cur != nullptr) {
            if(cur->left != nullptr) {
                TreeNode *tmp = cur->left;
                while(tmp->right != nullptr && tmp->right != cur) {
                    tmp = tmp->right;
                }
                if(tmp->right == cur) {
                    tmp->right = nullptr;
                    cur = cur->right;
                }else {
                    tmp->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                }
            }else {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};