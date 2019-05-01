#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    while(~scanf("%d", &num)) {
        vector<int> arr(num, 0);
        for(int i = 0; i < num; ++i) {
            scanf("%d", &arr[i]);
        }
        sort(arr.begin(), arr.end());
        bool flag = true;
        int diff = arr[1] - arr[0];
        for(int i = 2; i < num; ++i) {
            if(arr[i] - arr[i-1] != diff) {
                flag = false;
                break;
            }
        }
        if(flag == true) {
            printf("Possible\n");
        }else {
            printf("Impossible\n");
        }
    }
    return 0;
}
