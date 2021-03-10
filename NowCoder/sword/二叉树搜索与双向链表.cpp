/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void dfs(TreeNode *cur, TreeNode* &last) {
        if(cur->left != nullptr) {
            dfs(cur->left, last);
        }
        if(last != nullptr)
            last->right = cur;
        cur->left = last;
        last = cur;
        if(cur->right != nullptr) {
            dfs(cur->right, last);
        }
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) {
            return nullptr;
        }
        TreeNode* last = nullptr;
        dfs(pRootOfTree, last);
        TreeNode* head = last;
        while(head->left != nullptr) {
            head = head->left;
        }
        return head;
    }
};


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	TreeNode* Convert(TreeNode *pRootOfTree) {
		if(pRootOfTree == nullptr) {
			return nullptr;
		}
		TreeNode *cur = pRootOfTree, *last = nullptr;
		while(cur != nullptr) {
			if(cur->left != nullptr) {
				TreeNode *tmp = cur->left;
				while(tmp->right != nullptr && tmp->right != cur) {
					tmp = tmp->right;
				}
				if(tmp->right == cur) {
					cur->left = last;
                    last = cur;
					cur = cur->right;
				}else {
                    tmp->right = cur;
					cur = cur->left;
				}
			}else {
				if(last != nullptr)
					last->right = cur;
				cur->left = last;
                last = cur;
				cur = cur->right;
			}
		}
		TreeNode *head = last;
		while(head->left != nullptr) {
			head = head->left;
		}
		return head;
	}
};
