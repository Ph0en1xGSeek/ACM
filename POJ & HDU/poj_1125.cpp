#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 101
#define INF 1000000

using namespace std;

int arr[M][M];

int main(){
    int num, contact;
    int to, cost;
    while(scanf("%d", &num) && num != 0){
        for(int i = 1; i <= num; i++){
            for(int j = 1; j <= num; j++){
                if(i == j)
                    arr[i][j] = 0;
                else
                    arr[i][j] = INF;
            }
        }
        for(int i = 1; i <= num; i++){
            scanf("%d", &contact);
            for(int j = 0; j < contact; j++){
                scanf("%d%d", &to, &cost);
                arr[i][to] = cost;
            }

        }
        for(int k = 1; k <= num; k++){
            for(int i = 1; i <= num; i++){
                for(int j = 1; j <= num; j++){
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
        bool flag = false;
        int mi = INF;
        int pos;
        for(int i = 1; i <= num; i++){
            flag = false;
            int mx = -1;
            for(int j = 1; j <= num; j++){
                if(arr[i][j] >= INF){
                    flag = true;
                    break;
                }
                mx = max(mx, arr[i][j]);
            }
            if(flag == false && mi > mx){
                mi = mx;
                pos = i;
            }
        }
        if(mi == INF)
            printf("disjoint\n");
        else
            printf("%d %d\n", pos, mi);
    }
    return 0;
}
