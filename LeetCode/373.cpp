class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz = nums1.size();
        int sz2 = nums2.size();
        if(sz == 0)
            return {};
        vector<vector<int>> ans;
        vector<int> pos(sz, 0);
        while(k--) {
            int mi_pos = 0;
            int mi = INT_MAX;
            for(int i = 0; i < sz; ++i) {
                if(pos[i] < sz2 && mi > nums1[i] + nums2[pos[i]]) {
                    mi = nums1[i] + nums2[pos[i]];
                    mi_pos = i;
                }
                if(pos[i] == 0) {
                    break;
                }
            }
            if(mi != INT_MAX) {
                ans.push_back({nums1[mi_pos], nums2[pos[mi_pos]]});
                ++pos[mi_pos];
            }else {
                break;
            }
        }
        return ans;
    }
};