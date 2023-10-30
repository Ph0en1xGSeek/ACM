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
        string ret;
        if (root == nullptr) {
            return "None";
        }
        TreeNode *cur = root, *pre;
        while (cur != nullptr) {
            if (cur -> left != nullptr) {
                pre = cur -> left;
                while (pre -> right != nullptr && pre -> right != cur) {
                    pre = pre -> right;
                }
                if (pre -> right == nullptr) {
                    pre -> right = cur;
                    ret += to_string(cur -> val) + ",";
                    cur = cur -> left;
                } else {
                    pre -> right = nullptr;
                    ret += "None,";
                    cur = cur -> right;
                }
            } else {
                ret += to_string(cur -> val) + ",None,";
                cur = cur -> right;
            }
        }
        ret += "None";
        return ret;
        
    }


    TreeNode* deserialize(list<string> &dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root -> left = deserialize(dataArray);
        root -> right = deserialize(dataArray);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (char &ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return deserialize(dataArray);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));