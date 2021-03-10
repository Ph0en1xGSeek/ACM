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
    bool dfs(TreeNode *cur, TreeNode *target, vector<TreeNode*> &path) {
        path.push_back(cur);
        if(cur == target) {
            return true;
        }
        if(cur->left && dfs(cur->left, target, path)) {
            return true;
        }
        if(cur->right && dfs(cur->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        dfs(root, p, path1);
        dfs(root, q, path2);
        int i;
        for(i = 0; i < path1.size() && i < path2.size(); ++i) {
            if(path1[i] != path2[i]) {
                break;
            }
        }
        return path1[i-1];
    }
};