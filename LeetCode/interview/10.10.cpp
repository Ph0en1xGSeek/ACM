class StreamRank {
private:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            int cnt;
            TreeNode(int x): val(x), left(nullptr), right(nullptr), cnt(1) {

            }
        };
        TreeNode *root;
public:
    StreamRank(): root(nullptr) {
    }
    
    void track(int x) {
        if(root == nullptr) {
            root = new TreeNode(x);
            return;
        }
        TreeNode *p = nullptr;
        TreeNode *cur = root;
        while(cur != nullptr) {
            p = cur;
            if(x == cur->val) {
                ++cur->cnt;
                break;
            }else if(x < cur->val) {
                ++(cur->cnt);
                cur = cur->left;
            }else {
                cur = cur->right;
            }
        }
        if(x < p->val) {
            p->left = new TreeNode(x);
        }else if(x > p->val) {
            p->right = new TreeNode(x);
        }
    }
    
    int getRankOfNumber(int x) {
        int ans = 0;
        TreeNode *cur = root;
        while(cur != nullptr) {
            if(cur->val == x) {
                ans += cur->cnt;
                break;
            }else if(cur->val < x) {
                ans += cur->cnt;
                cur = cur->right;
            }else {
                cur = cur->left;
            }
        }
        return ans;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */