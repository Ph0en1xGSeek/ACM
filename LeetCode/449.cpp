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
        TreeNode *cur = root, *tmp = nullptr;
        ostringstream os;
        while(cur != nullptr) {
            tmp = cur->left;
            if(tmp == nullptr) {
                os << cur->val << " ";
                cur = cur->right;
            }else {
                while(tmp->right != nullptr && tmp->right != cur) {
                    tmp = tmp->right;
                }
                if(tmp->right == cur) {
                    tmp->right = nullptr;
                    cur = cur->right;
                }else {
                    os << cur->val << " ";
                    tmp->right = cur;
                    cur = cur->left;
                }
            }
        }
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        int cur_val;
        if(!(is >> cur_val)) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(cur_val);
        TreeNode *cur, *pre;
        while(is >> cur_val) {
            cur = root;
            while(cur != nullptr) {
                pre = cur;
                if(cur_val < cur->val) {
                    cur = cur->left;
                }else if(cur_val > cur->val) {
                    cur = cur ->right;
                }
            }
            if(cur_val < pre->val) {
                pre->left = new TreeNode(cur_val);
            }else if(cur_val > pre->val){
                pre->right = new TreeNode(cur_val);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));