class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    int pick(int target) {
        vector<int> tmp_arr;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] == target) {
                tmp_arr.push_back(i);
            }
        }
        int sz = tmp_arr.size();
        int r = rand() % sz;
        return tmp_arr[r];
    }
    
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */