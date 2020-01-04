class Solution {
public:
    int partition(vector<int> &input, int from, int to) {
        if(from >= to) {
            return from;
        }
        int left = from;
        int right = to;
        int pivot = input[left];
        while(left < right) {
            while(left < right && input[right] >= pivot) --right;
            input[left] = input[right];
            while(left < right && input[left] <= pivot) ++left;
            input[right] = input[left];
        }
        input[left] = pivot;
        return left;
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int sz = input.size();
        vector<int> ret(k);
        if(sz < k) {
            return vector<int>(0);
        }
        int left = 0;
        int right = sz - 1;
        int index;
        while(true) {
            index = partition(input, left, right);
            if(index == k) {
                copy(input.begin(), input.begin() + k, ret.begin());
                break;
            }else if(index > k) {
                right = index - 1;
            }else {
                left = index + 1;
            }
        }
        return ret;
    }
};