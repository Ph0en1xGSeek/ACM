class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
            bool flag1 = false;
            bool flag2 = false;
            if(nums1[i] < nums2[j]) {
                ++i;
                flag1 = true;
            }else if(nums1[i] > nums2[j]) {
                ++j;
                flag2 = true;
            }else {
                ans.push_back(nums1[i]);
                ++i;
                ++j;
                flag1 = flag2 = true;
            }
            if(flag1 == true) {
                while(i < sz1 && nums1[i] == nums1[i-1]) {
                    ++i;
                }
            }
            if(flag2 == true) {
                while(j < sz2 && nums2[j] == nums2[j-1]) {
                    ++j;
                }
            }
        }
        return ans;
    }
};