/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if(root == nullptr) {
			return;
		}
		TreeLinkNode *next_layer_first = nullptr, *next_layer_last = nullptr, *cur = root;
		while(cur != nullptr) {
            next_layer_first = next_layer_last = nullptr;
			while(cur != nullptr) {
				if(cur->left != nullptr) {
					if(next_layer_first == nullptr) {
						next_layer_first = cur->left;
					}
					if(next_layer_last == nullptr) {
						next_layer_last = cur->left;
					}else {
						next_layer_last->next = cur->left;
						next_layer_last = cur->left;
					}
				}
				if(cur->right != nullptr) {
					if(next_layer_first == nullptr) {
						next_layer_first = cur->right;
					}
					if(next_layer_last == nullptr) {
						next_layer_last = cur->right;
					}else {
						next_layer_last->next = cur->right;
						next_layer_last = cur->right;
					}
				}
				cur = cur->next;
			}
			cur = next_layer_first;
		}
	}
};
