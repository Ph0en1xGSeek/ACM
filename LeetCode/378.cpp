class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int sz = matrix.size();
        if(sz == 0) {
            return 0;
        } 
        vector<int> arr(sz * sz);
        for(int i = 0; i < sz; ++i) {
            copy(matrix[i].begin(), matrix[i].end(), arr.begin() + i * sz);
        }
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
        return *(arr.begin() + k - 1);
    }
};