class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int pos2 = 1, pos3 = 1, pos5 = 1;
        vector<int> ugly_number({0, 1});
        for(int i = 2; i <= index; ++i) {
            int mi = ugly_number[pos2] * 2;
            mi = min(mi, ugly_number[pos3] * 3);
            mi = min(mi, ugly_number[pos5] * 5);
            ugly_number.push_back(mi);
            if(mi == ugly_number[pos2] * 2) ++pos2;
            if(mi == ugly_number[pos3] * 3) ++pos3;
            if(mi == ugly_number[pos5] * 5) ++pos5;
        }
        return ugly_number[index];
    }
};