class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(i < len && j <= len){
            if(i == j){
                sum += nums[j++];
            }
            if(sum >= s){
                ans = min(ans, j-i);
                sum -= nums[i++];
            }else if(j < len){
                sum += nums[j++];
            }else{
                break;
            }
        }
        if(ans == INT_MAX){
            return 0;
        }else{
            return ans;
        }
    }
};