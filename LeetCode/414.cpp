class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int sz = nums.size();
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        int flag1 = false, flag2 = false, flag3 = false;
        for(int i = 0; i < sz; ++i) {
            if(nums[i] >= first) {
                if(nums[i] > first) {
                    third = second;
                    second = first;
                    first = nums[i];
                    flag3 = flag2;
                    flag2 = flag1;
                }
                flag1 = true;
                
            }else if(nums[i] >= second) {
                if(nums[i] > second) {
                    third = second;
                    second = nums[i];
                    flag3 = flag2;
                }
                flag2 = true;
                
            }else if(nums[i] >= third){
                third = nums[i];
                flag3 = true;
            }
        }
        if(flag3 == false) {
            return first;
        }else {
            return third;
        }
    }
};