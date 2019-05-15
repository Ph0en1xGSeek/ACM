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
    void dfs(TreeNode *cur, vector<string> &path, vector<string> &res) {
        path.push_back(to_string(cur->val));
        if(cur->left == nullptr && cur->right == nullptr) {
            string path_str = path[0];
            for(int i = 1; i < path.size(); ++i) {
                path_str += "->" + path[i];
            }
            res.push_back(path_str);
        }
        if(cur->left != nullptr) {
            dfs(cur->left, path, res);
        }
        if(cur->right != nullptr) {
            dfs(cur->right, path, res);
        }
        path.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr) {
            return res;
        }
        vector<string> path;
        dfs(root, path, res);
        return res;
    }
};