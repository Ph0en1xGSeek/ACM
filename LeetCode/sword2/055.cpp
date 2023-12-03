/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *cur;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        int ret;
        while (cur != nullptr) {
            TreeNode *tmp = cur -> left;
            if (tmp != nullptr) {
                while (tmp -> right != nullptr && tmp -> right != cur) {
                    tmp = tmp -> right;
                }
                if (tmp -> right == cur) {
                    tmp -> right = nullptr;
                    ret = cur -> val;
                    cur = cur -> right;
                    break;
                } else {
                    tmp -> right = cur;
                    cur = cur -> left;
                }
            } else {
                ret = cur -> val;
                cur = cur -> right;
                break;
            }
        }
        return ret;
    }
    
    bool hasNext() {
        return cur != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */