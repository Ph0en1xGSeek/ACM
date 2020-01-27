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
    void dfs(string &str, TreeNode *cur) {
        if(cur == NULL) {
            str += '#';
            return;
        }
        string tmp = "";
        int val = cur->val;
        while(val) {
            tmp += char((val % 10) + '0');
            val /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        str = str + tmp + '!';
        dfs(str, cur->left);
        dfs(str, cur->right);
    }
    
    void dfs2(TreeNode *&cur, char *str, int &pos) {
        if(str[pos] == '\0') {
            cur = NULL;
            return;
        }
        if(str[pos] >= '0' && str[pos] <= '9') {
            int num = 0;
            while(str[pos] >= '0' && str[pos] <= '9') {
                num = num * 10 + (str[pos] - '0');
                ++pos;
            }
            ++pos;
            cur = new TreeNode(num);
            dfs2(cur->left, str, pos);
            dfs2(cur->right, str, pos);
        }else if(str[pos] == '#') {
            ++pos;
            cur = NULL;
            return;
        }
    }
    
    char* Serialize(TreeNode *root) {    
        string str;
        dfs(str, root);
        int sz = str.size();
        char *ret = new char[sz+1];
        for(int i = 0; i < sz; ++i) {
            ret[i] = str[i];
        }
        ret[sz] = '\0';
        return ret;
    }
    TreeNode* Deserialize(char *str) {
        TreeNode *root;
        int pos = 0;
        dfs2(root, str, pos);
        return root;
    }
};