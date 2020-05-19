class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int size = a.size();
        vector<int> ans;
        if(size == 0) {
            return ans;
        }
        ans.resize(size, 1);
        for(int i = 1; i < size; ++i) {
            ans[i] = ans[i-1] * a[i-1];
        }
        int tmp = a[size - 1];
        for(int i = size - 2; i >= 0; --i) {
            ans[i] *= tmp;
            tmp *= a[i];
        }
        return ans;
    }
};