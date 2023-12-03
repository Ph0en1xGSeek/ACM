class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans = 0;
        int arr[128] = {};
        int left = 0;
        int right = 0;
        while (right < size) {
            ++arr[s[right]];
            if (arr[s[right]] > 1) {
                while (left < right && arr[s[right]] > 1) {
                    --arr[s[left++]];
                }
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        ans = max(ans, size - left);
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        vector<int> last_appear(128, -1);
        int left = 0;
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            if (last_appear[s[i]] >= left) {
                left = last_appear[s[i]] + 1;
            }
            last_appear[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};