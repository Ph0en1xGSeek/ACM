// Partition
class Solution {
public:
    int partition(vector<int> &numbers, int from, int to) {
        if(from >= to) {
            return from;
        }
        int pivot = numbers[from];
        int left = from, right = to;
        while(left < right) {
            while(left < right && numbers[right] >= pivot) --right;
            numbers[left] = numbers[right];
            while(left < right && numbers[left] <= pivot) ++left;
            numbers[right] = numbers[left];
        }
        numbers[left] = pivot;
        return left;
    }
    
    bool isValid(vector<int> &numbers, int number) {
        int sz = numbers.size();
        int times = 0;
        for(int elem : numbers) {
            if(elem == number) {
                ++times;
            }
        }
        if(times * 2 <= sz) {
            return false;
        }else {
            return true;
        }
    }
    
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int sz = numbers.size();
        if(sz == 0) {
            return 0;
        }
        int mid = sz / 2;
        int index;
        int left = 0, right = sz-1;
        while(1) {
            index = partition(numbers, left, right);
            if(index == mid) {
                break;
            }else if(index < mid) {
                left = index + 1;
                index = partition(numbers, left, right);
            }else {
                right = index - 1;
                index = partition(numbers, left, right);
            }
        }
        if(isValid(numbers, numbers[index])) {
            return numbers[index];
        }else {
            return 0;
        }
        
    }
};




// Accumulation
class Solution {
public:

    bool isValid(vector<int> &numbers, int number) {
        int sz = numbers.size();
        int times = 0;
        for(int elem : numbers) {
            if(elem == number) {
                ++times;
            }
        }
        if(times * 2 <= sz) {
            return false;
        }else {
            return true;
        }
    }
    
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int sz = numbers.size();
        if(sz == 0) {
            return 0;
        }
        int times = 1;
        int nums = numbers[0];
        for(int i = 1; i < sz; ++i) {
            if(times == 0) {
                nums = numbers[i];
                ++times;
            }else if(numbers[i] == nums) {
                ++times;
            }else {
                --times;
            }
        }
        if(isValid(numbers, nums)) {
            return nums;
        }else {
            return 0;
        }
    }
};