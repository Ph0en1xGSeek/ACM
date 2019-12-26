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
        if(cur->left != NULL){
            dfs(cur->left, res);
        }
        if(cur->right != NULL){
            dfs(cur->right, res);
        }
        
        res.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        dfs(root, res);
        return res;
    }
};

// stack O(N), O(N)
// postorder(left-right-root) = reverse(preorder(root-right-left))
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                cur = cur->right;
            }else {
                cur = s.top();
                s.pop();
                cur = cur->left;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// thread O(N), O(1)
// postorder(left-right-root) = reverse(preorder(root-right-left))
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode *cur = root, *pre;
        if(cur == nullptr) {
            return ret;
        }
        while(cur) {
            if(cur->right != nullptr) {
                pre = cur->right;
                while(pre->left != nullptr && pre->left != cur) {
                    pre = pre->left;
                }
                if(pre->left == nullptr) {
                    pre->left = cur;
                    ret.push_back(cur->val);
                    cur = cur->right;
                }else {
                    pre->left = nullptr;
                    cur = cur->left;
                }
            }else {
                ret.push_back(cur->val);
                cur = cur->left;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};