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
private:
    string num2str(int num) {
        if(num == 0) {
            return "0";
        }
        string str = "";
        int sign = 1;
        if(num < 0) {
            str.append("-");
            sign = -1;
            num = -num;
        }
        while(num > 0) {
            str.append(1, num % 10 + '0');
            num /= 10;
        }
        if(sign == 1)
            reverse(str.begin(), str.end());
        else 
            reverse(str.begin() + 1, str.end());
        return str;
    }
    
    int str2num(string str) {
        int num = 0;
        int i = 0;
        int sign = 1;
        if(str[i] == '-') {
            sign = -1;
            ++i;
        }
        for(; i < str.size(); ++i) {
            num *= 10;
            num += (str[i] - '0');
        }
        return sign * num;
    }
    
    void dfs(vector<string> &code, TreeNode *node) {
        if(node == nullptr) {
            code.push_back("#");
            return;
        }
        code.push_back(num2str(node->val));
        dfs(code, node->left);
        dfs(code, node->right);
    }
    
    TreeNode* construct(vector<string> &code, int &pos) {
        if(pos >= code.size() || code[pos] == "#") {
            return nullptr;
        }
        TreeNode *node = new TreeNode(str2num(code[pos]));
        ++pos;
        node->left = construct(code, pos);
        ++pos;
        node->right = construct(code, pos);
        return node;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> code;
        dfs(code, root);
        string output = "";
        if(code.size() > 0) {
            output.append(code[0]);
            for(int i = 1; i < code.size(); ++i) {
                output += " ";
                output.append(code[i]);
            }
        }
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        string tmp;
        vector<string> code;
        while(is >> tmp) {
            code.push_back(tmp);
        }
        TreeNode *root = nullptr;
        if(code.size() > 0) {
            int pos = 0;
            root = construct(code, pos);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));