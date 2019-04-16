class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int pre = nums[0];
        int cnt = 0;
        int len = nums.size();
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++){
            if(*iter == pre){
                cnt++;
                if(cnt > 2){
                    iter = nums.erase(iter);
                    iter--;
                    len--;
                }
            }else{
                cnt = 1;
                pre = *iter;
            }
        }
        return len;
    }
};