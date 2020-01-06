class Solution {
public:
    void merge(vector<int> &data, int left, int right, int &sum) {
        if(left == right) {
            return;
        }
        int mid = left + ((right - left) >> 1);
        merge(data, left, mid, sum);
        merge(data, mid+1, right, sum);
        vector<int> tmp(right - left + 1);
        int i = left, j = mid+1, pos = 0;
        while(i <= mid && j <= right) {
            if(data[i] <= data[j]) {
                tmp[pos++] = data[i++];
            }else {
                tmp[pos++] = data[j++];
                sum = (sum + mid - i + 1) % 1000000007;
            }
        }
        while(i <= mid) tmp[pos++] = data[i++];
        while(j <= right) tmp[pos++] = data[j++];
        copy(tmp.begin(), tmp.end(), data.begin() + left);
    }
    
    int InversePairs(vector<int> data) {
        int ans = 0;
        int sz = data.size();
        if(sz <= 1) {
            return 0;
        }
        merge(data, 0, sz-1, ans);
        return ans;
    }
};