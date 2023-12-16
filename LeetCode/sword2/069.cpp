class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        int pos = 0;
        while (pos < size - 1 && arr[pos] < arr[pos + 1]) {
            ++pos;
        }
        return pos;
    }
};