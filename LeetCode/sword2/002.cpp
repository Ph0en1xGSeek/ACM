class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int size_a = a.size();
        int size_b = b.size();
        int i, j;
        int tmp = 0;
        for (i = size_a - 1, j = size_b - 1; i >= 0 && j >= 0; --i, --j) {
            int tmp_a = a[i] - '0';
            int tmp_b = b[j] - '0';
            int tot = tmp_a + tmp_b + tmp;
            tmp = tot >> 1;
            ans.push_back((tot & 1) + '0');
        }
        while (i >= 0) {
            int tmp_a = a[i] - '0';
            int tot = tmp_a + tmp;
            tmp = tot >> 1;
            ans.push_back((tot & 1) + '0');
            --i;
        }
        while(j >= 0) {
            int tmp_b = b[j] - '0';
            int tot = tmp_b + tmp;
            tmp = tot >> 1;
            ans.push_back((tot & 1) + '0');
            --j;
        }
        if (tmp > 0) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};