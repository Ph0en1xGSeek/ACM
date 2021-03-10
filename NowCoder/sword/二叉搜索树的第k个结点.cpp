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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr) {
            return pRoot;
        }
        TreeNode *ans = nullptr;
        dfs(pRoot, k, ans);
        return ans;
    }

    void dfs(TreeNode *cur, int &k, TreeNode *&ans) {
        if(cur->left != nullptr) {
            dfs(cur->left, k, ans);
        }
        if(k == 0) {
            return;
        }
        --k;
        if(k == 0) {
            ans = cur;
            return;
        }
        if(cur->right != nullptr) {
            dfs(cur->right, k, ans);
        }
    }
};