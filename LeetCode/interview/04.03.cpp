/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
	public:
		vector<ListNode*> listOfDepth(TreeNode* tree) {
			vector<ListNode*> ans;
			if(tree == nullptr) {
				return ans;
			}
			queue<TreeNode*> q;
			q.push(tree);
			while(!q.empty()) {
				int size = q.size();
				ListNode *tail;
				for(int i = 0; i < size; ++i) {
					TreeNode *cur = q.front();
					q.pop();
					if(i == 0) {
						tail = new ListNode(cur->val);
						ans.push_back(tail);
					}else {
						tail->next = new ListNode(cur->val);
						tail = tail->next;
					}
					if(cur->left != nullptr) {
						q.push(cur->left);
					}
					if(cur->right != nullptr) {
						q.push(cur->right);
					}
				}
			}
			return ans;
		}
	};