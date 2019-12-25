class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size();
        int sz2 = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int mx, mx_sz, mi_sz;
        if(sz1 > sz2) {
            mx = 1;
            mx_sz = sz1;
            mi_sz = sz2;
        }else {
            mx = 2;
            mx_sz = sz2;
            mi_sz = sz1;
        }
        string ans = string(mx_sz, '0');
        int ad = 0;
        for(int i = 0; i < mi_sz; ++i) {
            ans[i] = num1[i] - '0' + num2[i] + ad;
            if(ans[i] > '9') {
                ans[i] -= 10;
                ad = 1;
            }else {
                ad = 0;
            }
        }
        for(int i = mi_sz; i < mx_sz; ++i) {
            if(mx == 1) {
                ans[i] = num1[i] + ad;
            }else {
                ans[i] = num2[i] + ad;
            }
            if(ans[i] > '9') {
                ans[i] -= 10;
                ad = 1;
            }else {
                ad = 0;
            }
        }
        if(ad == 1) {
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};