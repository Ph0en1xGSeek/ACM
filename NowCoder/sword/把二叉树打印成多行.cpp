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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > ans;
            if(pRoot == nullptr) {
                return ans;
            }
            queue<TreeNode *> q({pRoot});
            while(!q.empty()) {
                int sz = q.size();
                vector<int> tmp(sz);
                for(int i = 0; i < sz; ++i) {
                    TreeNode *ft = q.front();
                    q.pop();
                    tmp[i] = ft->val;
                    if(ft->left != nullptr) {
                        q.push(ft->left);
                    }
                    if(ft->right != nullptr) {
                        q.push(ft->right);
                    }
                }
                ans.push_back(tmp);
            }
            return ans;
        }
    
};