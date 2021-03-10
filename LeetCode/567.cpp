class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);
        int size1 = s1.size();
        int size2 = s2.size();
        for(int i = 0; i < size1; ++i) {
            ++arr1[s1[i] - 'a'];
        }
        int pos = 0;
        int left = 0;
        int cnt = 0;
        while(pos < size2) {
            if(arr2[s2[pos] - 'a'] >= arr1[s2[pos] - 'a']) {
                while(left <= pos && s2[pos] != s2[left]) {
                    --arr2[s2[left] - 'a'];
                    ++left;
                    --cnt;
                }
                ++left;
            }else {
                ++cnt;
                ++arr2[s2[pos] - 'a'];
                if(cnt == size1) {
                    return true;
                }
            }
            ++pos;
        }
        return false;
    }
};