/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int sz1 = 0, sz2 = 0;
        if(pHead1 == nullptr || pHead2 == nullptr) {
            return nullptr;
        }
        ListNode *cur1 = pHead1, *cur2 = pHead2;
        while(cur1 != nullptr) {
            cur1 = cur1->next;
            ++sz1;
        }
        while(cur2 != nullptr) {
            cur2 = cur2->next;
            ++sz2;
        }
        if(sz1 < sz2) {
            swap(sz1, sz2);
            swap(pHead1, pHead2);
        }
        int diff = sz1 - sz2;
        cur1 = pHead1;
        cur2 = pHead2;
        while(diff--) {
            cur1 = cur1->next;
        }
        while(cur1 != nullptr && cur2 != nullptr && cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};