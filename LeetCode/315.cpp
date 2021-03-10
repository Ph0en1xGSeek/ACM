class Solution {
public:
    void merge_sort(vector<int> &nums, vector<int> &pos, vector<int> &smaller, int left, int right) {
        if(left >= right) {
            return;
        }
        int mid = (left + right) >> 1;
        merge_sort(nums, pos, smaller, left, mid);
        merge_sort(nums, pos, smaller, mid+1, right);
        int i = left, j = mid + 1, jump = 0, k = 0;
        vector<int> merged(right - left + 1);
        while(i <= mid || j <= right) {
            if(i > mid) {
                merged[k++] = pos[j++];
            }else if(j > right) {
                smaller[pos[i]] += jump;
                merged[k++] = pos[i++];
            }else if(nums[pos[i]] <= nums[pos[j]]) {
                smaller[pos[i]] += jump;
                merged[k++] = pos[i++];
            }else {
                ++jump;
                merged[k++] = pos[j++];
            }
        }

        for(int i = 0; i < right - left + 1; ++i) {
            pos[left + i] = merged[i];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<int> pos(sz, 0);
        vector<int> smaller(sz, 0);
        for(int i = 0; i < sz; ++i) {
            pos[i] = i;
        }
        merge_sort(nums, pos, smaller, 0, sz-1);
        return smaller;
    }
};


/// BST
struct Node {
    Node *left;
    Node *right;
    int val;
    int size;
    Node(int num) {
        val = num;
        size = 0;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int addAndCount(Node *node, int val) {
        ++(node->size);
        if(val > node->val) {
            if(node->right == nullptr) {
                node->right = new Node(val);
            }
            return node->size - 1 - node->right->size + addAndCount(node->right, val);
        }else if(val < node->val) {
            if(node->left == nullptr) {
                node->left = new Node(val);
            }
            return addAndCount(node->left, val);
        }else {
            if(node->left == nullptr) {
                return 0;
            }else {
                return node->left->size;
            }
        }
    }
    
    void freeNode(Node *node) {
        if(node == nullptr) 
            return;
        if(node->left != nullptr) {
            freeNode(node->left);
        }
        if(node->right != nullptr) {
            freeNode(node->right);
        }
        delete node;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) {
            return vector<int>(0);
        }
        vector<int> ret(sz, 0);
        Node *root = new Node(nums[sz-1]);
        ++(root->size);
        for(int i = sz-2; i >= 0; --i) {
            ret[i] = addAndCount(root, nums[i]);
        }
        freeNode(root);
        return ret;
    }
};
