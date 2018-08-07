class Solution {
public:
    void dfs(vector<vector<int> >& res, vector<int>& nums, int start){
        if(start == nums.size()-1)
            res.push_back(nums);
        map<int, int> mp;
        for(int i = start; i < nums.size(); i++){
            if(mp.count(nums[i]) > 0)
                continue;
            mp[nums[i]] = 1;
            swap(nums[start], nums[i]);
            dfs(res, nums, start+1);
            swap(nums[start], nums[i]);
        }

    }

    vector<vector<int> > permuteUnique(vector<int>& nums){
        vector<vector<int> > res;
        dfs(res, nums, 0);
        return res;
    }
};
