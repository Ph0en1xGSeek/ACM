class Solution {
public:
    int minArray(vector<int>& numbers) {
        int size = numbers.size();
        if(size == 0) {
            return 0;
        }else if(size == 1) {
            return numbers[0];
        }
        int left = 0, right = size - 1;
        if(numbers[left] < numbers[right]) {
            return numbers[left];
        }
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            if(numbers[mid] > numbers[right]) {
                left = mid + 1;
            }else if(numbers[mid] < numbers[left]) {
                right = mid;
            }else {
                --right;
            }
        }
        return numbers[left];
    }
};