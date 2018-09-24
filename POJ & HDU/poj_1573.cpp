#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char arr[500][500];
int flags[500][500];

int main(){
    int n, m, start;
    while(~scanf("%d%d%d", &n, &m, &start) && n != 0){
        memset(flags, -1, sizeof(flags));
        for(int i = 1; i <= n; i++){
            scanf("%s", &arr[i][1]);
        }
        int x = 1;
        int y = start;
        int cnt = 0;
        while(x >= 1 && x <= n && y >= 1 && y <= m){

            if(flags[x][y] != -1){
                printf("%d step(s) before a loop of %d step(s)\n", flags[x][y], cnt-flags[x][y]);
                break;
            }else{
                flags[x][y] = cnt++;
            }
            if(arr[x][y] == 'W')
                y-=1;
            else if(arr[x][y] == 'E')
                y+=1;
            else if(arr[x][y] == 'N')
                x-=1;
            else if(arr[x][y] == 'S')
                x+=1;
        }
        if(!(x >= 1 && x <= n && y >= 1 && y <= m))
            printf("%d step(s) to exit\n", cnt);
    }
    return 0;
}
