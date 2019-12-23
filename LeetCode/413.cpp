class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz = A.size();
        if(sz <= 2) {
            return 0;
        }
        long long ans = 0;
        int dif = A[1] - A[0];
        long long cnt = 1;
        for(int i = 2; i < sz; ++i) {
            if(A[i] - A[i-1] == dif) {
                ++cnt;
            }else {
                ans += cnt * (cnt - 1) / 2;
                dif = A[i] - A[i-1];
                cnt = 1;
            }
        }
        ans += cnt * (cnt - 1) / 2;
        return (int) ans;
    }
};