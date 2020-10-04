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
    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> path;
        if(root == nullptr) {
            ans.push_back(path);
            return ans;
        }
        list<TreeNode*> candidate;
        dfs(root, candidate, path, ans);
        return ans;
    }

    void dfs(TreeNode *cur, list<TreeNode*> &candidate, vector<int> &path, vector<vector<int>> &ans) {
        path.push_back(cur->val);
        int cnt = 0;
        if(cur->left != nullptr) {
            ++cnt;
            candidate.push_back(cur->left);
        }
        if(cur->right != nullptr) {
            ++cnt;
            candidate.push_back(cur->right);
        }
        int size = candidate.size();
        if(size == 0) {
            ans.push_back(path);
        }else {
            for(int i = 0; i < size; ++i) {
                TreeNode *nex = candidate.front();
                candidate.pop_front();
                dfs(nex, candidate, path, ans);
                candidate.push_back(nex);
            }
        }

        for(int i = 0; i < cnt; ++i) {
            candidate.pop_back();
        }
        path.pop_back();
    }
};