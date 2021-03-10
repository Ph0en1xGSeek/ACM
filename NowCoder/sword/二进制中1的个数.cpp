class Solution {
public:
     int  NumberOf1(int n) {
         int cnt;
         for(cnt = 0; n != 0; ++cnt) {
             n = (n - 1) & n;
         }
         return cnt;
     }
};