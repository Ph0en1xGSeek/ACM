/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) {
            return head;
        }
        duplicateList(head);
        constructRandom(head);
        RandomListNode *ret = splitList(head);
        return ret;
    }
    
    void duplicateList(RandomListNode *head) {
        RandomListNode *nex;
        while(head != nullptr) {
            nex = new RandomListNode(head->label);
            nex->next = head->next;
            head->next = nex;
            head = nex->next;
        }
    }
    
    void constructRandom(RandomListNode *head) {
        RandomListNode *nex;
        while(head != nullptr) {
            nex = head->next;
            if(head->random != nullptr)
                nex->random = head->random->next;
            head = nex->next;
        }
    }
    
    RandomListNode* splitList(RandomListNode *head) {
        RandomListNode *newHead = head->next;
        RandomListNode *cur, *nex;
        while(head != nullptr) {
            cur = head->next;
            nex = cur->next;
            if(nex == nullptr) {
                head->next = cur->next = nullptr;
            }else {
                head->next = nex;
                cur->next = nex->next;
            }
            head = head->next;
            cur = cur->next;
        }
        return newHead;
    }
};