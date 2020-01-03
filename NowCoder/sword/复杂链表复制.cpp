/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    void cloneNode(RandomListNode *pHead) {
        RandomListNode *cur = pHead;
        while(cur != nullptr) {
            RandomListNode *nex = new RandomListNode(cur->label);
            nex->next = cur->next;
            cur->next = nex;
            cur = cur->next->next;
        }
    }
    
    void connectRandom(RandomListNode *pHead) {
        RandomListNode *cur = pHead, *nex;
        while(cur != nullptr) {
            nex = cur->next;
            if(cur->random != nullptr) {
                nex->random = cur->random->next;
            }
            cur = cur->next->next;
        }
    }
    
    RandomListNode* reConnect(RandomListNode *pHead) {
        RandomListNode *cur = pHead, *nex, *newHead = cur->next;
        while(cur != nullptr) {
            nex = cur->next;
            cur->next = nex->next;
            cur = nex->next;
            if(nex->next != nullptr) {
                nex->next = nex->next->next;
            }else {
                nex->next = nullptr;
            }
        }

        return newHead;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr) {
            return nullptr;
        }
        cloneNode(pHead);
        connectRandom(pHead);
        return reConnect(pHead);
    }
};