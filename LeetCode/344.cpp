class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        int i = 0, j = sz-1;
        while(i < j) {
            swap(s[i++], s[j--]);
        }
    }
};