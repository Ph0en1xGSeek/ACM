class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](pair<int, int> &p1, pair<int, int> &p2){
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        int size1 = nums1.size();
        int size2 = nums2.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < min(k, size1); ++i) {
            q.emplace(i, 0);
        }
        vector<vector<int>> ans;
        while (k-- && !q.empty()) {
            auto [a, b] = q.top();
            q.pop();
            ans.push_back({nums1[a], nums2[b]});
            if (b + 1 < size2) {
                q.emplace(a, b + 1);
            }
        }
        return ans;
    }
};