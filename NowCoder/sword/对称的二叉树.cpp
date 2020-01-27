/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool check(TreeNode *leftNode, TreeNode *rightNode) {
        if((leftNode == nullptr && rightNode != nullptr) || 
          (leftNode != nullptr && rightNode == nullptr)) {
            return false;
        }
        if(leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        if(leftNode->val != rightNode->val) {
            return false;
        }
        bool flag = check(leftNode->left, rightNode->right);
        if(!flag) {
            return false;
        }
        return check(leftNode->right, rightNode->left);
    }
    
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == nullptr) {
            return true;
        }
        return check(pRoot->left, pRoot->right);
    }

};