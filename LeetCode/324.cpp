class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = nums.size();
        nth_element(nums.begin(), nums.begin() + sz / 2, nums.end());
        auto index = [=](int pos) {return (pos * 2 + 1) % (sz | 1);};
        int mid = nums[sz/2];
        int low = 0, high = sz-1;
        int i = 0;
        while(i <= high) {
            if(nums[index(i)] < mid) {
                swap(nums[index(i)], nums[index(high--)]);
            }else if(nums[index(i)] > mid) {
                swap(nums[index(i++)], nums[index(low++)]);
            }else {
                ++i;
            }
        }
    }
};