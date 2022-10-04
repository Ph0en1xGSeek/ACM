/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursion O(N), O(N)
class Solution {
public:
    void dfs(TreeNode *cur, vector<int> &res){
        res.push_back(cur->val);
        if(cur->left != NULL){
            dfs(cur->left, res);
        }
        if(cur->right != NULL){
            dfs(cur->right, res);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        dfs(root, res);
        return res;
    }
};


// stack O(N), O(N)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode *cur = root;
        if(cur == nullptr) {
            return ret;
        }
        stack<TreeNode*> s;
        while(cur || !s.empty()) {
            if(cur) {
                s.push(cur);
                ret.push_back(cur->val);
                cur = cur->left;
            }else {
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        return ret;
    }
};

// thread binary tree O(N), O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode *cur = root, *pre;
        if(cur == nullptr) {
            return ret;
        }
        while(cur) {
            if(cur->left != nullptr) {
                pre = cur->left;
                while(pre->right != nullptr && pre->right != cur) {
                    pre = pre->right;
                }
                if(pre->right == nullptr) {
                    pre->right = cur;
                    ret.push_back(cur->val);
                    cur = cur->left;
                }else {
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }else {
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};