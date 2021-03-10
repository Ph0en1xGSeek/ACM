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
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int sz_pre = pre.size();
        int sz_in = vin.size();
        int sz = sz_pre;
        TreeNode* root = nullptr;
        if(sz_pre == 0 || sz_in == 0 || sz_pre != sz_in) {
            return root;
        }
        root = recons(pre, 0, sz-1, vin, 0, sz-1);
        return root;
    }
    
    TreeNode* recons(vector<int> &pre, int p_l, int p_r,
                    vector<int> &in, int i_l, int i_r) {
        if(p_l > p_r) {
            return nullptr;
        }
        if(p_l == p_r) {
            return new TreeNode(pre[p_l]);
        }
        TreeNode *cur = new TreeNode(pre[p_l]);
        int pos = i_l;
        while(in[pos] != pre[p_l]) ++pos;
        cur->left = recons(pre, p_l + 1, pos - i_l + p_l,
                         in, i_l, pos-1);
        cur->right = recons(pre, pos - i_l + p_l + 1, p_r,
                          in, pos+1, i_r);
        return cur;
    }
};