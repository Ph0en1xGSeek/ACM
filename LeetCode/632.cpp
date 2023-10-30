class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int range_left = 0, range_right = INT_MAX;
        int size = nums.size();
        vector<int> pos(size, 0);

        auto cmp = [&nums, &pos](const int& u, const int& v) {
            return nums[u][pos[u]] > nums[v][pos[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        
        int min_value = 0, max_value = INT_MIN;
        for (int i = 0; i < size; ++i) {
            q.push(i);
            max_value = max(max_value, nums[i][0]);
        }
        
        while (1) {
            int left_row = q.top();
            q.pop();
            min_value = nums[left_row][pos[left_row]++];
            if (max_value - min_value < range_right - range_left) {
                range_left = min_value;
                range_right = max_value;
            }
            if (pos[left_row] == nums[left_row].size()) {
                break;
            }

            max_value = max(max_value, nums[left_row][pos[left_row]]);
            q.push(left_row);
        }
        return {range_left, range_right};
        
    }
};