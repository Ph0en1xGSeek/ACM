class Solution {
public:
    string i2a(int num) {
        string ret;
        do {
            ret.push_back(num % 10 + '0');
            num /= 10;
        } while(num);
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string minNumber(vector<int>& nums) {
        int size = nums.size();
        vector<string> arr;
        for (int i = 0; i < size; ++i) {
            arr.push_back(i2a(nums[i]));
        }
        sort(arr.begin(), arr.end(), [](string &a, string &b) {
            string strA = a + b;
            string strB = b + a;
            return strA < strB;
        });
        string result;
        for (int i = 0; i < size; ++i) {
            result += arr[i];
        }
        return result;
    }
};