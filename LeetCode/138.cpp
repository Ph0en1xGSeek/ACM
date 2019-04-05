/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        Node *new_head;
        if(head == NULL){
            return new_head;
        }
        
        Node *cur = head;
        new_head = new Node();
        mp[head] = new_head;
        while(cur != NULL){
            Node *new_cur = mp[cur];
            new_cur->val = cur->val;
            
            if(cur->next != NULL && mp.count(cur->next) == 0){
                Node *tmp = new Node();
                mp[cur->next] = tmp;
                new_cur->next = tmp;
            }else if(cur->next != NULL){
                new_cur->next = mp[cur->next];
            }else{
                new_cur->next = NULL;
            }
            
            if(cur->random != NULL && mp.count(cur->random) == 0){
                Node *tmp = new Node();
                mp[cur->random] = tmp;
                new_cur->random = tmp;
            }else if(cur->random != NULL){
                new_cur->random = mp[cur->random];
            }else{
                new_cur->random = NULL;
            }
            cur = cur->next;
        }
        return new_head;
    }
};