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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        return recons(preorder, 0, size - 1, inorder, 0, size - 1);
    }

    TreeNode* recons(vector<int> &preorder, int pre_l, int pre_r, vector<int> &inorder, int in_l, int in_r) {
        if(pre_l == pre_r) {
            return new TreeNode(preorder[pre_l]);
        }
        if(pre_l > pre_r) {
            return nullptr;
        }
        int cur_val = preorder[pre_l];
        int in_pos = in_l;
        while(in_pos <= in_r && inorder[in_pos] != cur_val) {
            ++in_pos;
        }
        TreeNode *node = new TreeNode(cur_val);
        node->left = recons(preorder, pre_l + 1, pre_l + in_pos - in_l,
                            inorder, in_l, in_pos - 1);
        node->right = recons(preorder, pre_l + 1 + in_pos - in_l, pre_r,
                            inorder, in_pos + 1, in_r);
        return node;
    }
};