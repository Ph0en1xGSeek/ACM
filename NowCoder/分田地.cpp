#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int sum[100][100];
int n, m;

int count_value(int left, int right, int up, int down){
    return sum[down][right] - sum[down][left] - sum[up][right] + sum[up][left];
}

bool solve(int mid){
    for(int i = 1; i <= n-3; i++){
        for(int j = i+1; j <= n-2; j++){
            for(int k = j+1; k <= n-1; k++){
                int pre = 0;
                int cnt = 0;
                for(int y = 1; y <= m; y++){
                    int sum_a = count_value(pre, y, 0, i);
                    int sum_b = count_value(pre, y, i, j);
                    int sum_c = count_value(pre, y, j, k);
                    int sum_d = count_value(pre, y, k, n);
                    if(sum_a >= mid && sum_b >= mid && sum_c >= mid && sum_d >= mid){
                        cnt++;
                        pre = y;
                        if(cnt == 4)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    char tmp[100];
    memset(sum, 0, sizeof(sum));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%s", &tmp[1]);
        for(int j = 1; j <= m; j++){
            sum[i][j] = tmp[j] - '0';
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + sum[i][j];
        }
    }


    int left = 0;
    int right = sum[n][m];
    int ans = 0;
    if(n >= 4 && m >= 4){
        while(left <= right){
            int mid = (left + right) >> 1;
            if(solve(mid)){
                left = mid + 1;
                ans = mid;
            }else{
                right = mid - 1;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
