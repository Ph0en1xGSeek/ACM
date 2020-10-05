#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char arr[120][120];

int main() {

    int n, m;

    int mix = 103;
    int miy = 103;
    int mxx = -1;
    int mxy = -1;
    int cnt = 0;
    memset(arr, 0, sizeof(arr));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        getchar();
        scanf("%s", &arr[i][1]);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(arr[i][j] == 'B')
            {
                mix = min(mix, i);
                mxx = max(mxx, i);
                miy = min(miy, j);
                mxy = max(mxy, j);
                cnt++;
            }
        }
    }
//
//    printf("%d %d %d %d\n\n", mix, mxx, miy, mxy);
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= m; j++)
//            cout << arr[i][j];
//        cout << endl;
//    }

    if(mxx - mix + 1 > m || mxy - miy + 1 > n)
        printf("-1\n");
    else if(cnt == 0)
        printf("1\n");
    else if(mxx - mix >  mxy - miy)
        printf("%d\n", (mxx - mix + 1)*(mxx - mix + 1) - cnt);
    else
        printf("%d\n", (mxy - miy + 1)*(mxy - miy + 1) - cnt);

    return 0;
}