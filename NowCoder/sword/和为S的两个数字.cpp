class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int sz = array.size();
        vector<int> ans;
        if(sz < 2) {
            return ans;
        }
        int l = 0, r = sz-1;
        while(l < r) {
            if(sum < array[l] + array[l]) {
                break;
            }
            if(array[l] + array[r] < sum) {
                ++l;
            }else if(array[l] + array[r] > sum) {
                --r;
            }else {
                if(0 == ans.size()) {
                    ans.resize(2);
                }
                ans[0] = array[l];
                ans[1] = array[r];
                break;
            }
        }
        return ans;
    }
};