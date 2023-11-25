/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode *cur, int deep, int &max_deep, int &cnt){
        if(cur->left == nullptr && cur->right == nullptr){
            if(max_deep == -1){
                max_deep = deep;
            }else if(deep < max_deep){
                return false;
            }
            cnt++;
            return true;
        }
        if(dfs(cur->left, deep+1, max_deep, cnt) == false){
            return false;
        }
        if(cur->right != nullptr){
            if(dfs(cur->right, deep+1, max_deep, cnt) == false){
                return false;
            }
        }else{
            return false;
        }
        return true;
    }
    
    int countNodes(TreeNode* root) {
        int max_deep = -1;
        int cnt = 0;
        if(root == nullptr){
            return 0;
        }
        dfs(root, 0, max_deep, cnt);
        return ((1<<(max_deep)) - 1 + cnt);
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root -> left == nullptr) {
            return 1;
        }
        int deep = 0;
        TreeNode *cur = root;
        while (cur -> left != nullptr) {
            cur = cur -> left;
            ++deep;
        }
        int low = (1 << deep);
        int high = (1 << (deep + 1));
        while (low < high) {
            int mid = ((high - low) >> 1) + low;
            if (exists(root, deep, mid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low - 1;
    }

    bool exists(TreeNode *root, const int &deep, int node) {
        int bit = (1 << (deep - 1));
        TreeNode *cur = root;
        while (cur != nullptr && bit > 0) {
            if (node & bit) {
                cur = cur -> right;
            } else {
                cur = cur -> left;
            }
            bit >>= 1;
        }
        return cur != nullptr;
    }
};