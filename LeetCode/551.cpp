class Solution {
public:
    bool checkRecord(string s) {
        int size = s.size();
        int cnt = 0;
        int cumulate = 0;
        bool reward = true;
        for(int i = 0; i < size; ++i) {
            if(s[i] == 'A') {
                ++cnt;
                cumulate = 0;
            }else if(s[i] == 'L') {
                ++cumulate;
            }else {
                cumulate = 0;
            }
            if(cnt > 1 || cumulate > 2) {
                reward = false;
                break;
            }
        }
        return reward;
    }
};