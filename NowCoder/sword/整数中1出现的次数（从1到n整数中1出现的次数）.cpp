class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        char num[11];
        int sz = 0;
        while(n > 0) {
            num[sz++] = (n % 10) + '0';
            n /= 10;
        }
        reverse(begin(num), begin(num) + sz);
        num[sz] = '\0';
        int ans = numberOf1(num);
        return ans;
    }
    
    int numberOf1(char *num) {
        if(num == nullptr || *num == '\0') {
            return 0;
        }
        int sz = strlen(num);
        int first = *num - '0';
        if(sz == 1 && first == 0) {
            return 0;
        }
        if(sz == 1 && first >= 1) {
            return 1;
        }
        int numFirst = 0;
        if(first > 1) {
            numFirst = powerBased10(sz-1);
        }else if(first == 1) {
            numFirst = stoi(num+1) + 1;
        }
        
        int numOthers = first * (sz - 1) * powerBased10(sz - 2);
        int numRecursion = numberOf1(num+1);
        return numFirst + numOthers + numRecursion;
    }
    
    int powerBased10(int n) {
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            ans *= 10;
        }
        return ans;
    }
};