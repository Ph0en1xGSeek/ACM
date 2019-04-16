class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx = 0;
        unordered_map<int, int> len;
        for(int i = 0; i < nums.size(); i++){
            if(len.count(nums[i]) != 0) continue;
            int left_len = 0, right_len = 0;
            if(len.count(nums[i] - 1)){
                left_len = len[nums[i] - 1];
            }
            if(len.count(nums[i] + 1)){
                right_len = len[nums[i] + 1];
            }
            int sum =  left_len + right_len + 1;
            len[nums[i]] = sum;
            len[nums[i]-left_len] = sum;
            len[nums[i]+right_len] = sum;
            mx = max(mx, sum);
        }
        return mx;
    }
};