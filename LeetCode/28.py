class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        return haystack.find(needle)


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> nex(m);
        nex[0] = -1;
        int i = 0;
        int j = -1;
        while (i < m - 1) {
            if (j < 0 || needle[i] == needle[j]) {
                ++j;
                ++i;
                nex[i] = j;
            } else if (j >= 0 && needle[i] != needle[j]) {
                j = nex[j];
            }
        }

        for (i = 0, j = 0; i < n && j < m; ++i, ++j) {
            while (j >= 0 && haystack[i] != needle[j]) {
                j = nex[j];
            }
        }
        if (j < m) {
            return -1;
        }
        return i - m;
    }
};