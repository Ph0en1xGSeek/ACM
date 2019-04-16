class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses == 0){
            return true;
        }
        vector<int> degree(numCourses, 0);
        unordered_map<int, vector<int>> mp;
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); i++){
            int from = prerequisites[i].first;
            int to = prerequisites[i].second;
            mp[from].push_back(to);
            degree[to]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            cnt++;
            for(int i = 0; i < mp[cur].size(); i++){
                degree[mp[cur][i]]--;
                if(degree[mp[cur][i]] == 0){
                    q.push(mp[cur][i]);
                }
            }
        }
        if(cnt != numCourses){
            return false;
        }
        return true;
    }
};