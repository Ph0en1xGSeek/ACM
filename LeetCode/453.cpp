class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mi = INT_MAX;
        for(int item: nums) {
            mi = min(mi, item);
        }
        long long ans = 0;
        for(int item: nums) {
            ans += item - mi;
        }
        return ans;
    }
};