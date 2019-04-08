class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int i = 0, j = 0;
        int ans = -5;
        while(1){
            if(i == len1 && j == len2){
                ans = 0;
                break;
            }else if(i == len1){
                while(j < len2){
                    if(version2[j] != '0' && version2[j] != '.'){
                        ans = -1;
                    }
                    j++;
                }
                if(ans != -1){
                    ans = 0;
                }
                break;
            }else if(j == len2){
                while(i < len1){
                    if(version1[i] != '0' && version1[i] != '.'){
                        ans = 1;
                    }
                    i++;
                }
                if(ans != 1){
                    ans = 0;
                }
                break;
            }
            int num1 = 0, num2 = 0;
            while(i < len1 && version1[i] != '.'){
                num1 *= 10;
                num1 += version1[i] - '0';
                i++;
            }
            
            while(j < len2 && version2[j] != '.'){
                num2 *= 10;
                num2 += version2[j] - '0';
                j++;
            }
            if(num1 < num2){
                ans = -1;
                break;
            }else if(num1 > num2){
                ans = 1;
                break;
            }
            if(version1[i] == '.'){
                i++;
            }
            if(version2[j] == '.'){
                j++;
            }
        }
        return ans;
    }
};