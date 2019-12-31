/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree2(TreeNode *pRoot1, TreeNode *pRoot2) {
        if(pRoot2 == nullptr) {
            return true;
        }
        if(pRoot1 == nullptr) {
            return false;
        }
        return pRoot1->val == pRoot2->val && HasSubtree2(pRoot1->left, pRoot2->left) && HasSubtree2(pRoot1->right, pRoot2->right);
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }
        bool result = false;
        if(pRoot1->val == pRoot2->val) {
            result = HasSubtree2(pRoot1, pRoot2);
        }
        if(!result) {
            result = HasSubtree(pRoot1->left, pRoot2);
        }
        if(!result) {
            result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
};