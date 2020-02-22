/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) {
            return nullptr;
        }
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        mp[node] = newnode;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode *cur, *newcur, *nei, *newnei;
        while(!q.empty()) {
            cur = q.front();
            newcur = mp[cur];
            q.pop();
            for(int i = 0; i < cur->neighbors.size(); ++i) {
                nei = (cur->neighbors)[i];
                if(mp.find(nei) != mp.end()) {
                    newnei = mp[nei];
                }else {
                    newnei = new UndirectedGraphNode(nei->label);
                    mp[nei] = newnei;
                    q.push(nei);
                }
                newcur->neighbors.push_back(newnei);
            }
        }
        return newnode;
    }
};