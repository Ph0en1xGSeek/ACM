class Solution {
public:
	int run(TreeNode *root) {
		if(root == nullptr) {
			return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *cur = nullptr;
        int depth = 0;
        while(!q.empty()) {
            int sz = q.size();
            ++depth;
            for(int i = 0; i < sz; ++i) {
                cur = q.front();
                q.pop();
                if(cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
        }
        return -1;
    }
};