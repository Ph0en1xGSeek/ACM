class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int sz = data.size();
        int l = 0, r = sz-1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(data[mid] < k) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        int left = l;
        l = 0, r = sz-1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(data[mid] <= k) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        int right = l;
        return right - left;
    }
};


class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto iter_left = lower_bound(data.begin(), data.end(), k);
        auto iter_right = upper_bound(data.begin(), data.end(), k);
        return iter_right - iter_left;
    }
};