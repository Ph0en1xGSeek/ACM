class Solution {
public:
    int min3(int a, int b, int c) {
        if(a < b) {
            if(a < c) return a;
            else return c;
        }else {
            if(b < c) return b;
            else return c;
        }
    }
    
    int nthUglyNumber(int n) {
        int *arr = new int[n];
        arr[0] = 1;
        int k = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        while(k < n) {
            arr[k] = min3(arr[index2] * 2, arr[index3] * 3, arr[index5] * 5);
            if(arr[k] == arr[index2] * 2)
                ++index2;
            if(arr[k] == arr[index3] * 3)
                ++index3;
            if(arr[k] == arr[index5] * 5)
                ++index5;
            ++k;
        }
        int ans = arr[k-1];
        delete [] arr;
        return ans;
    }
};