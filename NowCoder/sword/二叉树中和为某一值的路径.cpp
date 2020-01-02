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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

        if(root == nullptr) {
            return ret;
        }
        dfs(root, expectNumber);
        sort(index.begin(), index.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            return a.second > b.second;
        });
        int sz = ret.size();
        for(int i = 0; i < sz; ++i) {
            sort_ret.push_back(ret[index[i].first]);
        }
        return sort_ret;
    }
    
    void dfs(TreeNode* root,int expectNumber) {

        curPath.push_back(root->val);
        int target = expectNumber - root->val;
        if(root->left == nullptr && root->right == nullptr && target == 0) {
            ret.push_back(curPath);
            index.push_back({(int)index.size(), (int)curPath.size()});
        }
        if(root->left != nullptr) {
            dfs(root->left, target);
        }
        if(root->right != nullptr) {
            dfs(root->right, target);
        }
        curPath.pop_back();
    }
private:
    vector<vector<int>> ret;
    vector<vector<int>> sort_ret;
    vector<int> curPath;
    vector<pair<int, int>> index;
};