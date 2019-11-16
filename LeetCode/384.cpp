class Solution {
public:
    Solution(vector<int>& nums) {
        int sz = nums.size();
        arr.resize(sz);
        copy(nums.begin(), nums.end(), arr.begin());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret = arr;
        int sz = arr.size();
        for(int i = 0; i < sz; ++i) {
            int r = rand() % sz;
            swap(ret[i], ret[r]);
        }
        return ret;
    }
private:
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */