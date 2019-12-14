class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int cnt_minute = 0;
        int cnt_hour = 0;
        vector<string> ans;
        for(int i = 0; i < 1024; ++i) {
            cnt_minute = 0;
            cnt_hour = 0;
            for(int j = 0; j < 6; ++j) {
                if(((1 << j) & i) != 0) {
                    ++cnt_minute;
                }
            }
            if(cnt_minute > num) {
                continue;
            }
            for(int j = 6; j < 10; ++j) {
                if(((1 << j) & i) != 0) {
                    ++cnt_hour;
                }
            }
            if(cnt_minute + cnt_hour != num) {
                continue;
            }
            int h = i >> 6;
            int m = i & ((1 << 6) - 1);
            if(h > 11 || m > 59) {
                continue;
            }
            ostringstream os;
            os << h << ":" << ((m < 10) ? "0": "") << m;
            ans.push_back(os.str());
        }
        return ans;
    }
};