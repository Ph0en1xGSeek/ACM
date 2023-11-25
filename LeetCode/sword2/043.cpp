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
class CBTInserter {

private:
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

    int getMaxPow2(int num) {
        if (num == 0) {
            return 0;
        }
        while (num >= 1) {
            if ((num & (num - 1)) == 0) {
                return num;
            } else {
                num &= (num - 1);
            }
        }
        return num;
    }

    int size;
    TreeNode *_root;

public:
    CBTInserter(TreeNode* root) : _root(root) {
        size = countNodes(root);
    }
    
    int insert(int v) {
        ++size;
        int deep = getMaxPow2(size);
        deep >>= 1;
        TreeNode *cur = _root;
        TreeNode *child = new TreeNode(v);
        while (deep > 1) {
            if (size & deep) {
                cur = cur -> right;
            } else {
                cur = cur -> left;
            }
            deep >>= 1;
        }
        if ((size & deep) == 1) {
            cur -> right = child;
        } else {
            cur -> left = child;
        }
        return cur -> val;
    }
    
    TreeNode* get_root() {
        return _root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */