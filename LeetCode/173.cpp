/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode*> path;
    
    BSTIterator(TreeNode* root) {
        TreeNode *cur = root;
        while(cur != NULL){
            path.push_back(cur);
            cur = cur->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *next_node = path.back();
        int res = next_node->val;
        path.pop_back();
        TreeNode *cur = next_node->right;
        while(cur != NULL){
            path.push_back(cur);
            cur = cur->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(path.size() != 0){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */