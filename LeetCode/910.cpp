class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int sz = A.size();
        if(sz == 0) {
            return 0;
        }
        sort(A.begin(), A.end());
        int mi = A[0];
        int mx = A[sz-1];
        int ans = mx - mi;
        for(int i = 0; i < sz-1; ++i) {
            int cur_mx = max(A[i] + K, mx - K);
            int cur_mi = min(A[i+1] - K, mi + K);
            ans = min(ans, cur_mx - cur_mi);
        }
        return ans;
    }
};