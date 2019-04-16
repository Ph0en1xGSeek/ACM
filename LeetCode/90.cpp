class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        if(nums.size() == 0){
            return result;
        }
        sort(nums.begin(), nums.end());
        int pre_size = 1;
        int last = nums[0];
        result.push_back(tmp);
        for(int i = 0; i < nums.size(); i++){
            if(last != nums[i]){
                last = nums[i];
                pre_size = result.size();
            }
            int cur_size = result.size();
            for(int j = cur_size - pre_size; j < cur_size; j++){
                result.push_back(result[j]);
                result[result.size()-1].push_back(nums[i]);
            }
        }
        return result;
    }
};