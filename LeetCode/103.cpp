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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        stack<TreeNode*> s1, s2;
        stack<TreeNode*> *s_ptr = &s1;
        (*s_ptr).push(root);
        while(!(*s_ptr).empty()){
            result.push_back(vector<int>(0));
            while(!(*s_ptr).empty()){
                TreeNode* cur = (*s_ptr).top();
                (*s_ptr).pop();
                result[result.size()-1].push_back(cur->val);
                if(s_ptr == &s1){
                    if(cur->left != NULL){
                        s2.push(cur->left);
                    }
                    if(cur->right != NULL){
                        s2.push(cur->right);
                    }
                }else{
                    if(cur->right != NULL){
                        s1.push(cur->right);
                    }
                    if(cur->left != NULL){
                        s1.push(cur->left);
                    }
                }
                
            }
            if(s_ptr == &s1){
                s_ptr = &s2;
            }else{
                s_ptr = &s1;
            }
        }
        return result;
    }
};