class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int sz = numbers.size();
        if(sz < 5) {
            return false;
        }
        int arr[14] = {0};
        for(int i = 0; i < 5; ++i) {
            ++arr[numbers[i]];
        }
        int pos = 1;
        int cnt = 0;
        while(pos < 14 && arr[pos] == 0) ++pos;
        for(pos; pos < 14; ++pos) {
            if(arr[pos] > 1) {
                return false;
            }else if(arr[pos] == 0) {
                if(arr[0] == 0) {
                    return false;
                }else {
                    --arr[0];
                    ++cnt;
                }
            }else {
                ++cnt;
            }
            if(cnt == 5) {
                return true;
            }
        }
        return true;
    }
};