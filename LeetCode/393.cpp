class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int sz = data.size();
        if(sz == 0) {
            return false;
        }
        for(int i = 0; i < sz; ++i) {
            data[i] %= 256;
        }
        int i = 0;
        int cnt = 0;
        while(i < sz) {
            if(data[i] >= 248) {
                return false;
            }else if(data[i] >= 240) {
                cnt = 3;
            }else if(data[i] >= 224) {
                cnt = 2;
            }else if(data[i] >= 192) {
                cnt = 1;
            }else if(data[i] >= 128) {
                return false;
            }else {
                cnt = 0;
            }
            ++i;
            if(sz - i < cnt) {
                return false;
            }else {
                int ran = i + cnt;
                for(; i < ran; ++i) {
                    if(data[i] >= 192 || data[i] < 128) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};