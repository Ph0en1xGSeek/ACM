class Solution {
public:
	TreeNode* construct(vector<int> &num, int left, int right) {
		if(left > right) {
			return nullptr;
		}else if(left == right) {
			return new TreeNode(num[left]);
		}
		int mid = left + ((right - left) >> 1);
		TreeNode *node = new TreeNode(num[mid]);
		node->left = construct(num, left, mid-1);
		node->right = construct(num, mid+1, right);
		return node;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {
		int sz = num.size();
		TreeNode *head = nullptr;
		if(sz == 0) {
			return head;
		}
		head = construct(num, 0, sz-1);
		return head;
	}
};