class Solution {
public:
    Solution(vector<vector<int>>& rects): arr(rects) {
        area = 0;
        int size = rects.size();
        area_accu.resize(size);
        for(int i = 0; i < size; ++i) {
            area += (arr[i][2] - arr[i][0] + 1) * (arr[i][3] - arr[i][1] + 1);
            area_accu[i] = area;
        }
    }
    
    vector<int> pick() {
        int rand_rect = rand() % area + 1;
        auto iter = lower_bound(area_accu.begin(), area_accu.end(), rand_rect);
        int index = iter - area_accu.begin();
        int rand_x = rand() % (arr[index][2] - arr[index][0] + 1) + arr[index][0];
        int rand_y = rand() % (arr[index][3] - arr[index][1] + 1) + arr[index][1];
        return {rand_x, rand_y};
    }
private:
    vector<int> area_accu;
    vector<vector<int>> arr;
    int area;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */