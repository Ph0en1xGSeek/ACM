class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int size = nums.size();
        if(size == 0 || k == 0) {
            return vector<int>();
        }
        for(int i = 0; i < k - 1; ++i) {
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans(size - k + 1);
        for(int i = k - 1; i < size; ++i) {
            if(!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans[i - k + 1] = nums[dq.front()];
        }
        return ans;
    }
};