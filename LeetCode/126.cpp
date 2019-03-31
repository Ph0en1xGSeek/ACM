class Solution {
public:
    
    void dfs(unordered_map<string, vector<string>>& pre, vector<vector<string>>& res, vector<string>& path, string beginWord, string cur){
        path.push_back(cur);
        if(cur == beginWord){
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        for(int i = 0; i < pre[cur].size(); i++){
            dfs(pre, res, path, beginWord, pre[cur][i]);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<vector<string>> res;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.count(endWord) == 0){
            return res;
        }
        wordSet.erase(endWord);
        wordSet.erase(beginWord);
        unordered_map<string, vector<string>> pre;
        unordered_map<string, int> step;
        queue<string> q;
        step[beginWord] = 1;
        int step_cnt = 0;
        q.push(beginWord);
        int len = beginWord.length();
        bool found = false;
        while(!q.empty() && found == false){
            step_cnt++;
            int cur_step = q.size();
            for(int s = 0; s < cur_step; s++){
                string cur = q.front();
                string cur_word = cur;
                q.pop();
                for(int i = 0; i < len; i++){
                    char tmp = cur[i];
                    for(int c = 'a'; c <= 'z'; c++){
                        cur[i] = c;
                        if(cur == endWord){
                            found = true;
                            pre[cur].push_back(cur_word);
                        }else if(step.count(cur) != 0 && step_cnt < step[cur]){
                            pre[cur].push_back(cur_word);
                        }
                        if(wordSet.count(cur) != 0){
                            wordSet.erase(cur);
                            q.push(cur);
                            step[cur] = step_cnt+1;
                            pre[cur].push_back(cur_word);
                        }
                    }
                    cur[i] = tmp;
                }

            }
        }
        
        if(found == false){
            return res;
        }else{
            vector<vector<string>> res;
            vector<string> path;
            dfs(pre, res, path, beginWord, endWord);
            return res;
        }
    }
};