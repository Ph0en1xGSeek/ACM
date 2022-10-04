class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.count(endWord) == 0){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int len = beginWord.length();
        int step = 0;
        while(!q.empty()){
            step++;
            int cur_step = q.size();
            for(int s = 0; s < cur_step; s++){
                string cur = q.front();
                q.pop();
                for(int i = 0; i < len; i++){
                    char tmp = cur[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        cur[i] = c;
                        if(cur == endWord){
                            return step + 1;
                        }
                        if(wordSet.count(cur) != 0){
                            wordSet.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            }
        }
        return 0;
    }
};