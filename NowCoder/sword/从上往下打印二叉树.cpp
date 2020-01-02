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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) {
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            ret.push_back(cur->val);
            if(cur->left != nullptr) {
                q.push(cur->left);
            }
            if(cur->right != nullptr) {
                q.push(cur->right);
            }
        }
        return ret;
    }
};