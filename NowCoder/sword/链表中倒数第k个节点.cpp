class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int cnt = 0;
		ListNode *cur = pListHead;
		for(cnt = 0; cnt < k; ++cnt) {
			if(cur != nullptr) {
				cur = cur->next;
			}else {
				break;
			}
		}
		if(cnt < k) {
			return nullptr;
		}
		ListNode *tail = cur;
		cur = pListHead;
		while(tail != nullptr) {
			tail = tail->next;
			cur = cur->next;
		}
		return cur;
	}
};