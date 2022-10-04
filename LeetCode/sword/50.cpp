class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> charMap;
        queue<char> q;
        for (int i = 0; i < s.length(); ++i) {
            if (charMap.find(s[i]) == charMap.end()) {
                charMap[s[i]] = i;
                q.push(s[i]);
            } else {
                charMap[s[i]] = -1;
                while(!q.empty() && charMap[q.front()] == -1) {
                    q.pop();
                }
            }
        }
        return q.empty()? ' ' : q.front();
    }
};