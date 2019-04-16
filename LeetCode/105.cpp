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
    
    int search(vector<int>& arr, int target, int from, int to){
        if(to >= arr.size()){
            to = arr.size() - 1;
        }
        for(int i = from; i <= to; i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* build(vector<int>& preorder, int pre_left, int pre_right, vector<int>& inorder, int in_left, int in_right){
        if(pre_left > pre_right){
            return NULL;
        }
        int val = preorder[pre_left];
        TreeNode* cur = new TreeNode(val);
        int mid_pos = search(inorder, val, in_left, in_right);
        cur->left = build(preorder, pre_left+1, pre_left+mid_pos-in_left, inorder, in_left, mid_pos-1);
        cur->right = build(preorder, pre_left+mid_pos-in_left+1, pre_right, inorder, mid_pos+1, in_right);
        return cur;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        int val = preorder[0];
        TreeNode* root = new TreeNode(val);
        int mid_pos = search(inorder, val, 0, inorder.size()-1);
        root->left = build(preorder, 1, mid_pos, inorder, 0, mid_pos-1);
        root->right = build(preorder, mid_pos+1, preorder.size()-1, inorder, mid_pos+1, inorder.size()-1);
        return root;
    }
};