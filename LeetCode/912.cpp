class Solution {
private:
    int partition(vector<int> &arr, int left, int right) {
        int random = rand() % (right - left + 1) + left;
        swap(arr[right], arr[random]);
        int pivot = arr[right];
        int i = left;
        for (int j = left; j <= right - 1; ++j) {
            if (arr[j] <= pivot) {
                swap(arr[i++], arr[j]);
            }
        }
        swap(arr[i], arr[right]);
        return i;
    }

    void quickSort(vector<int> &arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int pos = partition(arr, left, right);
        quickSort(arr, left, pos - 1);
        quickSort(arr, pos + 1, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
        // int size = nums.size();
        // bool ll = false;
        // for (int i = 0; i < size - 1; ++i) {
        //     if (nums[i + 1] < nums[i]) {
        //         ll = true;
        //         break;
        //     }
        // }
        // if (!ll) {
        //     return nums;
        // }
        // srand((unsigned)time(NULL));
        // quickSort(nums, 0, size - 1);
        // return nums;
    }
};