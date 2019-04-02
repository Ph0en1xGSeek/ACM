/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    queue<Node*> q;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        q.push(node);
        Node* new_head = new Node();
        mp[node] = new_head;
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            Node* new_node = mp[cur];
            new_node->val = cur->val;
            new_node->neighbors.resize((cur->neighbors).size());
            for(int i = 0; i < (cur->neighbors).size(); i++){
                if(mp.count((cur->neighbors)[i]) == 0){
                    (new_node->neighbors)[i] = new Node();
                    mp[(cur->neighbors)[i]] = (new_node->neighbors)[i];
                    q.push((cur->neighbors)[i]);
                }else{
                    (new_node->neighbors)[i] = mp[(cur->neighbors)[i]];
                }
            }
        }
        return new_head;
    }
};