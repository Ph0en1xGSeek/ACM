class Solution {
public:
    vector<int> printNumbers(int n) {
        int size = 1;
        for (int i = 0; i < n; ++i) {
            size *= 10;
        }
        vector<int> result(size - 1);
        for (int i = 1; i <= size - 1; ++i) {
            result[i - 1] = i;
        }
        return result;
    }
};