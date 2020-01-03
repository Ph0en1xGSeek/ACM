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
    void dfs(TreeNode *cur, TreeNode* &last) {
        if(cur->left != nullptr) {
            dfs(cur->left, last);
        }
        if(last != nullptr)
            last->right = cur;
        cur->left = last;
        last = cur;
        if(cur->right != nullptr) {
            dfs(cur->right, last);
        }
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) {
            return nullptr;
        }
        TreeNode* last = nullptr;
        dfs(pRootOfTree, last);
        TreeNode* head = last;
        while(head->left != nullptr) {
            head = head->left;
        }
        return head;
    }
};