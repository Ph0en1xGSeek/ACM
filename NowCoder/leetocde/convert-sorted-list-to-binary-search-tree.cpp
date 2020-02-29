class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if(head == nullptr) {
			return nullptr;
		}
        ListNode *tail = head;
        while(tail->next != nullptr) {
            tail = tail->next;
        }
		return genBST(head, tail);
	}
	
	TreeNode *genBST(ListNode *from, ListNode *to) {
		if(from == to) {
			return new TreeNode(from->val);
		}
		if(to == from->next) {
			TreeNode *node = new TreeNode(from->val);
			node->right = genBST(to, to);
			return node;
		}
		ListNode *fast = from, *slow = from, *pre = nullptr;
		while(fast != to && fast->next != to) {
			fast = fast->next->next;
			pre = slow;
			slow = slow->next;
		}
		TreeNode *node = new TreeNode(slow->val);
		node->left = genBST(from, pre);
		node->right = genBST(slow->next, to);
		return node;
	}
};