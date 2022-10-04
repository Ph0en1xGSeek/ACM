class Solution {
public:
    int countSubstrings(string s) {
        int old_size = s.size();
        int size = ((old_size << 1) | 1);
        string new_s(size, '#');
        // new_s[0] = '$';
        for (int i = 0; i < old_size; ++i) {
            new_s[(i << 1) | 1] = s[i];
        }
        // cout << new_s << endl;
        vector<int> p(size, 0);
        int bound = 0;
        int d = 0;
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            int pos = 0;
            if (bound > i) {
                pos = min(bound - i, p[(d << 1) - i]);
            }
            while (i + pos + 1 < size && i - pos - 1 >= 0 && new_s[i + pos + 1] == new_s[i - pos - 1]) {
                ++pos;
            } 
            if (i + pos > bound) {
                bound = i + pos;
                d = i;
            }
            ans += ((pos + 1) >> 1);
        }
        return ans;
    }
};