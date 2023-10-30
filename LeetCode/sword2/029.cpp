/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *newNode = new Node(insertVal, nullptr);
        if (head == nullptr) {
            newNode -> next = newNode;
            return newNode;
        }
        Node *cur = head -> next;
        Node *pre = head;
        Node *tail = nullptr;
        do {

            if (pre -> val > cur -> val) {
                tail = pre;
            }
            if ((pre -> val == insertVal || cur -> val == insertVal) || 
                (pre -> val < insertVal && cur -> val > insertVal)) {
                break;
            } 
            pre = cur;
            cur = cur -> next;
        } while (pre != head);


        if (pre == head && !((pre -> val == insertVal || cur -> val == insertVal) || (pre -> val < insertVal && cur -> val > insertVal)) && tail != nullptr) {
            // 循环一圈了没找到，全大于insertValue或者全小于insertValue且不都一样
            newNode -> next = tail -> next;
            tail -> next = newNode;
            return head;
        }
        newNode -> next = cur;
        pre -> next = newNode;

        return head;
    }
};