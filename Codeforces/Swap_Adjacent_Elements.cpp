#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 200001

using namespace std;

int arr[N];
char str[N];


int main()
{
    int num;
    bool flag = true;
    while(~scanf("%d", &num))
    {
        flag = true;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
        }
        scanf("%s", str);
        getchar();
        for(int i = 0; i < num; i++)
        {
            int l = i;
            while(str[i] == '1' && i < num-1)
                i++;
            int r = i;
            if(l == r && arr[l] != l+1)
            {
//                cout << "sdf: " << l << endl;
                flag = false;
                break;
            }
            for(int j = l; j <= r; j++)
            {
                if(arr[j] > r+1 || arr[j] < l+1)
                {
//                    cout << l << ' ' << r << endl;
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
