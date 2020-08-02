/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }
        Node *cur = head;
        Node *nex;
        while(cur != nullptr) {
            Node *tmp = new Node(cur->val) ;
            tmp -> next = cur -> next;
            cur -> next = tmp;
            cur = tmp -> next;
        }
        
        cur = head;
        while(cur != nullptr) {
            nex = cur -> next;
            if(cur -> random != nullptr)
                nex -> random = cur -> random -> next;
            cur = nex -> next;
        }

        cur = head;
        Node * ret = head -> next;
        while(cur != nullptr) {
            nex = cur -> next;
            Node * tmp = nex -> next;
            cur -> next = tmp;
            if(tmp != nullptr)
                nex -> next = tmp -> next;
            cur = tmp;
        }
        return ret;
    }
};
