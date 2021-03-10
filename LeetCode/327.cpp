class Solution {
public:
    int mergeSort(vector<long long> &sum, int lower, int upper, int left, int right) {
        if(left+1 >= right) {
            return 0;
        }
        int mid = (left + right) >> 1;
        int cnt = 0;
        cnt += mergeSort(sum, lower, upper, left, mid);
        cnt += mergeSort(sum, lower, upper, mid, right);
        int lower_pos = mid, upper_pos = mid;
        for(int i = left; i < mid; ++i) {
            while(lower_pos < right && sum[lower_pos] - sum[i] < lower) ++lower_pos;
            while(upper_pos < right && sum[upper_pos] - sum[i] <= upper) ++upper_pos;
            cnt += (upper_pos - lower_pos);
        }
        
        vector<long long> tmp(right - left);
        for(int i = left; i < right; ++i) {
            tmp[i - left] = sum[i];
        }
        int i = 0, j = mid - left;
        int pos = left;
        while(i < mid - left || j < right - left) {
            if(i >= mid - left) {
                sum[pos++] = tmp[j++];
            }else if(j >= right - left) {
                sum[pos++] = tmp[i++];
            }else if(tmp[i] < tmp[j]) {
                sum[pos++] = tmp[i++];
            }else {
                sum[pos++] = tmp[j++];
            }
        }
        // inplace_merge(sum.begin()+left, sum.begin()+mid, sum.begin()+right);
        return cnt;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int sz = nums.size();
        vector<long long> sum(sz + 1, 0);
        for(int i = 1; i < sz + 1; ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        int ans = mergeSort(sum, lower, upper, 0, sz + 1);
        return ans;
    }
};