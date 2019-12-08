class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long f = 0;
        long long sum = 0;
        int sz = A.size();
        for(int i = 0; i < sz; ++i) {
            f += i * A[i];
            sum += A[i];
        }
        long long ans = f;
        for(int i = 1; i < sz; ++i) {
            f = f + sum - (long long)sz * A[sz - i];
            ans = max(ans, f);
        }
        return (int)ans;
    }
};