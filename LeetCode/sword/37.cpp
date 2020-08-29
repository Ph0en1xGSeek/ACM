/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        serialize_dfs(root, ans);
        return ans;
    }

    void serialize_dfs(TreeNode *cur, string &str) {
        if(str.size() != 0) {
            str += ',';
        }
        if(cur == nullptr) {
            str += '@';
        }else {
            str += num2str(cur->val);
            serialize_dfs(cur->left, str);
            serialize_dfs(cur->right, str);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        int size = data.size();
        if(size == 0) {
            return nullptr;
        }
        int pos = 0;
        TreeNode *root = nullptr;
        root = deserialize_dfs(data, pos);
        return root;
    }

    TreeNode* deserialize_dfs(string &str, int &pos) {
        if(pos > str.size()) {
            return nullptr;
        }else if(str[pos] == '@') {
            pos += 2;
            return nullptr;
        }else {
            TreeNode *cur = nullptr;
            cur = new TreeNode(str2num(str, pos));
            cur->left = deserialize_dfs(str, pos);
            cur->right = deserialize_dfs(str, pos);
            return cur;
        }
    }

    string num2str(int num) {
        if(num == 0) {
            return "0";
        }
        bool neg = false;
        if(num < 0) {
            neg = true;
            num = -num;
        }
        string ret;
        while(num > 0) {
            ret += (num % 10) + '0';
            num /= 10;
        }
        if(neg) {
            ret += '-';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    int str2num(string &str, int &pos) {
        int num = 0;
        int size = str.size();
        int sign = 1;
        if(pos < size && str[pos] == '-') {
            sign = -1;
            ++pos;
        }
        while(pos < size && str[pos] != ',') {
            num *= 10;
            num += str[pos] - '0';
            ++pos;
        }
        ++pos;
        num *= sign;
        return num;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));