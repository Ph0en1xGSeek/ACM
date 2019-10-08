class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if(sz1 == 0 || sz2 == 0) {
            return ans;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < sz1 && j < sz2) {
            if(nums1[i] < nums2[j]) {
                ++i;
            }else if(nums1[i] > nums2[j]) {
                ++j;
            }else {
                ans.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return ans;
    }
};