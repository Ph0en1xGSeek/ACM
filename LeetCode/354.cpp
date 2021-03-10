class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int sz = envelopes.size();
        if(sz == 0) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> arr;
        for(int i = 0; i < sz; ++i) {
            int height = envelopes[i][1];
            int l = 0, r = arr.size() - 1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(arr[mid] < height) {
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
            if(l >= arr.size()) {
                arr.push_back(height);
            }else {
                arr[l] = height;
            }
        }
        return arr.size();
    }
};