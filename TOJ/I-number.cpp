#include <iostream>
#include <cstring>
#define Max 100003
#include <cstdio>

using namespace std;
char arr[Max];

int main()
{
    int from;
    int ca;
    int k;
    int tmp;
    cin >> ca;
    while(ca--)
    {
        from = 0;
        memset(arr, NULL, sizeof(arr));
        tmp = 0;
        scanf("%s", arr);
        k = strlen(arr);
        for(int i = 0; i < k; i++)
            tmp = (tmp + arr[i]-'0')%10;

        while(1)
        {
            tmp %= 10;
            if(tmp + '9' - arr[k-1] >= 10)
            {
                arr[k-1] += 10 - tmp;
                if(from)
                    cout << 1;
                printf("%s\n", arr);
                break;
            }
            else
            {
                tmp = tmp + 1 + '9' - arr[k-1];
                arr[k-1] = '0';
                if(k != 1)
                    arr[k-2]++;
                else
                    from = 1;
                for(int i = k-2; i >= 0; i--)
                    if(arr[i] > '9')
                    {
                        arr[i] = '0';
                        if(i != 0)
                            arr[i-1]++;
                        else
                            from = 1;
                        tmp += 1;
                    }
                    else
                        break;
                tmp++;
            }
        }

    }
    return 0;
}
