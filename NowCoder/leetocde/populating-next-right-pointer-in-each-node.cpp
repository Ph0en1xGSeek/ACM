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
		TreeLinkNode *next_layer_first = nullptr, *cur = root;
		while(cur->left != nullptr) {
			next_layer_first = cur->left;
			while(cur != nullptr) {
				cur->left->next = cur->right;
				if(cur->next != nullptr) {
					cur->right->next = cur->next->left;
				}
				cur = cur->next;
			}
			cur = next_layer_first;
		}
	}
};