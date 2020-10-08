class Solution {
    public int[] findClosedNumbers(int num) {
        int min_mask = 2;
        int max_mask = 1;
        int mask = 3;
        int cnt1 = 0;
        int suf1 = 0;
        int[] ans = new int[]{-1, -1};
        for(int i = 0; i < 30; ++i) {
            if((num & mask ^ min_mask) == 0) {
                ans[1] = (num ^ mask) - suf1 + (suf1 << (i - cnt1));
                break;
            }
            min_mask <<= 1;
            mask <<= 1;
            if((num & (1 << i)) != 0) {
                suf1 = ((suf1 << 1) | 1);
                ++cnt1;
            }
        }
        mask = 3;
        cnt1 = 0;
        suf1 = 0;
        for(int i = 0; i < 30; ++i) {
            if((num & mask ^ max_mask) == 0) {
                ans[0] = (num ^ mask) - (suf1 << (i - cnt1)) + suf1;
                break;
            }
            max_mask <<= 1;
            mask <<= 1;
            if((num & (1 << i)) != 0) {
                suf1 = ((suf1 << 1) | 1);
                ++cnt1;
            }
        }
        return ans;
    }
}