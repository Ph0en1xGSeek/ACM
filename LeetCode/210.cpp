class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        if(numCourses == 0)
            return order;
        unordered_map<int, vector<int>> mp;
        vector<int> degree(numCourses, 0);
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); i++){
            int to = prerequisites[i].first;
            int from = prerequisites[i].second;
            mp[from].push_back(to);
            degree[to]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            order.push_back(cur);
            for(int i = 0; i < mp[cur].size(); i++){
                degree[mp[cur][i]]--;
                if(degree[mp[cur][i]] == 0){
                    q.push(mp[cur][i]);
                }
            }
        }
        if(order.size() < numCourses){
            order.clear();
        }
        return order;
    }
};