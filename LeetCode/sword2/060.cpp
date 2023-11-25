class Solution {
private:
    int partition(vector<pair<int, int>> &arr, int left, int right) {
        while (left < right) {
            while (left < right && arr[left].second <= arr[right].second) {
                ++left;
            }
            swap(arr[left], arr[right]);
            while (left < right && arr[left].second <= arr[right].second) {
                --right;
            }
            swap(arr[left], arr[right]);
        }
        return left;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            cnt[nums[i]]++;
        }
        vector<pair<int, int>> values;
        for (auto &entry : cnt) {
            values.push_back(entry);
        }
        size = values.size();
        int left = 0, right = size - 1;
        while (true) {
            int pos = partition(values, left, right);
            if (pos < size - k) {
                left = pos + 1;
            } else if (pos > size - k) {
                right = pos - 1;
            } else {
                break;
            }
        }
        vector<int> ret(k);
        for (int i = size - k; i < size; ++i) {
            ret[i - size  + k] = values[i].first;
        }
        return ret;
    }
};