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
    
    int search(vector<int>& arr, int from, int to, int val){
        if(to >= arr.size()){
            to = arr.size() - 1;
        }
        for(int i = from; i <= to; i++){
            if(arr[i] == val){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* build(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder, int post_left, int post_right){
        if(in_left > in_right){
            return NULL;
        }
        int val = postorder[post_right];
        TreeNode* cur = new TreeNode(val);
        int mid_pos = search(inorder, in_left, in_right, val);
        cur->left = build(inorder, in_left, mid_pos-1, postorder, post_left, post_left+mid_pos-in_left-1);
        cur->right = build(inorder, mid_pos+1, in_right, postorder, post_left+mid_pos-in_left, post_right-1);
        return cur;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return NULL;
        }
        int val = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(val);
        int mid_pos = search(inorder, 0, inorder.size()-1, val);
        root->left = build(inorder, 0, mid_pos-1, postorder, 0, mid_pos-1);
        root->right = build(inorder, mid_pos+1, inorder.size()-1, postorder, mid_pos, postorder.size()-2);
        return root;
    }
};