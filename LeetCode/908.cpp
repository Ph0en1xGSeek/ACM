class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int sz = A.size();
        if(sz == 0) {
            return 0;
        }
        int mi = INT_MAX;
        int mx = INT_MIN;
        for(int i = 0; i < sz; ++i) {
            if(A[i] > mx) mx = A[i];
            if(A[i] < mi) mi = A[i];
        }
        if(mx - mi <= 2 * K) {
            return 0;
        }else {
            return mx - mi - 2 * K;
        }
    }
};