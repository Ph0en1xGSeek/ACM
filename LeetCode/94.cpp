/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursion O(N), O(N)
class Solution {
public:
    void dfs(TreeNode* node, vector<int>& result){
        if(node->left != NULL){
            dfs(node->left, result);
        }
        result.push_back(node->val);
        if(node->right != NULL){
            dfs(node->right, result);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        dfs(root, result);
        return result;
    }
};



// stack O(N), O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode *cur = root;
        if(cur == nullptr) {
            return ret;
        }
        stack<TreeNode*> s;
        while(cur || !s.empty()) {
            if(cur) {
                s.push(cur);
                cur = cur->left;
            }else {
                cur = s.top();
                s.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};


// thread binary tree O(N), O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    cur = cur->left;
                }else {
                    pre->right = nullptr;
                    ret.push_back(cur->val);
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