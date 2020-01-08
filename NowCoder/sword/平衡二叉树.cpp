class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth;
        return balance_depth(pRoot, depth);
    }
    
    bool balance_depth(TreeNode *cur, int &depth) {
        if(cur == nullptr) {
            depth = 0;
            return true;
        }
        int left, right;
        if(balance_depth(cur->left, left) && balance_depth(cur->right, right)) {
            if(left - right >= -1 && left - right <= 1) {
                depth = max(left, right) + 1;
                return true;
            }
        }
        return false;
    }
};