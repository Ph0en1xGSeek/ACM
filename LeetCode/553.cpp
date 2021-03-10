class Solution {
public:
    string num2str(int num) {
        string ans;
        while(num > 0) {
            ans += num % 10 + '0';
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string optimalDivision(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) {
            return num2str(nums[0]);
        }else if(size == 2) {
            return num2str(nums[0]) + "/" + num2str(nums[1]);
        }else {
            string ret = num2str(nums[0]) + "/(" + num2str(nums[1]);
            for(int i = 2; i < size; ++i) {
                ret += "/" + num2str(nums[i]);
            }
            ret += ")";
            return ret;
        }
    }
};