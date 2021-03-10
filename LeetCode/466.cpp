class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int, int> next_pos;
        next_pos[0] = 0;
        int sz1 = s1.size();
        int sz2 = s2.size();
        vector<int> finished(n1+1, 0);
        int j = 0, cnt = 0;
        for(int k = 1; k <= n1; ++k) {
            for(int i = 0; i < sz1; ++i) {
                if(s1[i] == s2[j]) {
                    ++j;
                    if(j == sz2) {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            finished[k] = cnt;
            
            if(next_pos.find(j) == next_pos.end()) {
                next_pos[j] = k;
            }else {
                int start = next_pos[j];
                int intervals = k - start;
                int repeat = (n1 - start) / intervals;
                int patternCnt = (finished[k] - finished[start]) * repeat;
                int remainCnt = finished[start + (n1 - start) % intervals];
                return (patternCnt + remainCnt) / n2;
            }
        }
        return cnt;
    }
};