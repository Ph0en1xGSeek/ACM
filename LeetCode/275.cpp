class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        if(sz == 0) {
            return 0;
        }
        int l = 0, r = sz;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(sz - mid < citations[mid]) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        if(l == 0) {
            if(sz > citations[0]) {
                return sz-1;
            }
            return sz;
        }
        if(sz - l + 1 == citations[l-1]) {
            return sz - l + 1;
        }else {
            return sz - l;
        }
    }
};