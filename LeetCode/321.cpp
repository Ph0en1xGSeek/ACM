class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        vector<int> ret;
        for(int i = max(0, k - sz2); i <= min(k, sz1); ++i) {
            ret = max(ret, mergeVec(maxVec(nums1, sz1 - i), maxVec(nums2, sz2 - (k - i))));
        }
        return ret;
    }
    
    vector<int> maxVec(vector<int> &nums, int drop) {
        vector<int> ret;
        for(int i = 0; i < nums.size(); ++i) {
            while(!ret.empty() && drop > 0 && ret.back() < nums[i]) {
                ret.pop_back();
                --drop;
            }
            ret.push_back(nums[i]);
        }
        while(drop > 0) {
            ret.pop_back();
            --drop;
        }
        return ret;
    }
    
    vector<int> mergeVec(const vector<int> &v1, const vector<int> &v2) {
        vector<int> ret;
        int sz1 = v1.size();
        int sz2 = v2.size();
        int pos1 = 0, pos2 = 0;
        while(pos1 < sz1 || pos2 < sz2) {
            if(pos2 == sz2) {
                ret.push_back(v1[pos1++]);
            }else if(pos1 == sz1) {
                ret.push_back(v2[pos2++]);
            }else if(v1[pos1] < v2[pos2]) {
                ret.push_back(v2[pos2++]);
            }else if(v1[pos1] > v2[pos2]) {
                ret.push_back(v1[pos1++]);
            }else {
                ret.push_back(v1[pos1]);
                compare(v1, v2, pos1, pos2)? ++pos1: ++pos2;
            }
        }
        return ret;
    }
    
    bool compare(const vector<int> &v1, const vector<int> &v2, int pos1, int pos2) {
        for(int i = pos1, j = pos2; ;++i, ++j) {
            if(i == v1.size()) {
                return false;
            }else if(j == v2.size()) {
                return true;
            }else if(v1[i] < v2[j]) {
                return false;
            }else if(v1[i] > v2[j]) {
                return true;
            }
        }
        return false;
    }
};