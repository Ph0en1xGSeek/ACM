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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr) {
            return pHead2;
        }
        if(pHead2 == nullptr) {
            return pHead1;
        }
        ListNode *mergedHead = nullptr, *mergedTail = nullptr;
        while(pHead1 != nullptr && pHead2 != nullptr) {
            if(pHead1->val < pHead2->val) {
                if(mergedHead == nullptr) {
                    mergedHead = mergedTail = pHead1;
                }else {
                    mergedTail->next = pHead1;
                    mergedTail = mergedTail->next;
                }
                pHead1 = pHead1->next;
                mergedTail->next = nullptr;
            }else {
                if(mergedHead == nullptr) {
                    mergedHead = mergedTail = pHead2;
                }else {
                    mergedTail->next = pHead2;
                    mergedTail = mergedTail->next;
                }
                pHead2 = pHead2->next;
                mergedTail->next = nullptr;
            }
        }
        if(pHead1 != nullptr) {
            mergedTail->next = pHead1;
        }else if(pHead2 != nullptr) {
            mergedTail->next = pHead2;
        }
        return mergedHead;
    }
};