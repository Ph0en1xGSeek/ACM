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
    bool dfs(TreeNode *cur, int deep, int &max_deep, int &cnt){
        if(cur->left == nullptr && cur->right == nullptr){
            if(max_deep == -1){
                max_deep = deep;
            }else if(deep < max_deep){
                return false;
            }
            cnt++;
            return true;
        }
        if(dfs(cur->left, deep+1, max_deep, cnt) == false){
            return false;
        }
        if(cur->right != nullptr){
            if(dfs(cur->right, deep+1, max_deep, cnt) == false){
                return false;
            }
        }else{
            return false;
        }
        return true;
    }
    
    int countNodes(TreeNode* root) {
        int max_deep = -1;
        int cnt = 0;
        if(root == nullptr){
            return 0;
        }
        dfs(root, 0, max_deep, cnt);
        return ((1<<(max_deep)) - 1 + cnt);
    }
};