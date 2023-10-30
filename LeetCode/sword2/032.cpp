class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length() || s == t) {
            return false;
        }
        int size = s.length();
        int arr[26] = {0};
        for (int i = 0; i < size; ++i) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }
};