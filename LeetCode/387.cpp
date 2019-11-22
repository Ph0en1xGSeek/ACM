class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        int sz = s.size();
        for(int i = 0; i < sz; ++i) {
            ++arr[s[i] - 'a'];
        }
        for(int i = 0; i < sz; ++i) {
            if(arr[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};