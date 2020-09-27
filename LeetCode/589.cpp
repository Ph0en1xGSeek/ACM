/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
	vector<int> preorder(Node *root) {
		vector<int> ans;
		dfs(root, ans);
		return ans;
	}
	
	void dfs(Node *cur, vector<int> &ans) {
		if(cur == nullptr) {
            return;
        }
		ans.push_back(cur->val);
		int size = (cur->children).size();
		for(int i = 0; i < size; ++i) {
			dfs((cur->children)[i], ans);
		}
	}
};
