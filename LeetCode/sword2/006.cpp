class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        vector<int> res(2);
        int left = 0;
        int right = size - 1;
        while(left < right) {
            if (numbers[left] + numbers[right] < target) {
                ++left;
            } else if (numbers[left] + numbers[right] > target) {
                --right;
            } else {
                res[0] = left;
                res[1] = right;
                break;
            }
        }
        return res;
    }
};