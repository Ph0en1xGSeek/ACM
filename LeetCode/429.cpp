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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(root == nullptr) {
            return ans;
        }
        Node *cur = nullptr;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> layer(sz, 0);
            for(int i = 0; i < sz; ++i) {
                cur = q.front();
                q.pop();
                layer[i] = cur->val;
                int ch_sz = (cur->children).size();
                for(int j = 0; j < ch_sz; ++j) {
                    q.push((cur->children)[j]);
                }
            }
            ans.push_back(layer);
        }
        return ans;
    }
};


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
    void dfs(vector<vector<int>> &ans, int deep, Node *cur) {
        int sz = ans.size();
        if(deep == sz) {
            ans.push_back(vector<int>(1, cur->val));
            ++sz;
        }else {
            ans[deep].push_back(cur->val);
        }
        for(Node *ch : cur->children) {
            dfs(ans, deep+1, ch);
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == nullptr) {
            return ans;
        }
        dfs(ans, 0, root);
        return ans;
    }
};