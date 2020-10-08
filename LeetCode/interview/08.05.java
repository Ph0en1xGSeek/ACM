class Solution {
    public int multiply(int A, int B) {
        int ans = 0;
        while(B > 0) {
            if((B & 1) == 1) {
                ans += A;
            }
            A <<= 1;
            B >>= 1;
        }
        return ans;
    }
}