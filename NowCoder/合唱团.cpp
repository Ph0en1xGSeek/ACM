#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int num, k, d;
    int arr[55];
    double dp_max[55][12];
    double dp_min[55][12];
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &k, &d);
    for(int i = 0; i < num; i++){
        dp_max[i][1] = arr[i];
        dp_min[i][1] = arr[i];
    }
    double ans = -1e17;
    for(int j = 2; j <= k; j++){
        for(int i = j-1; i < num; i++){
            dp_max[i][j] = -1e17;
            dp_min[i][j] = 1e17;
            if(arr[i] > 0){
                for(int m = 1; m <= d && i-m >= j-2; m++){
                    dp_max[i][j] = max(dp_max[i-m][j-1] * arr[i], dp_max[i][j]);
                    dp_min[i][j] = min(dp_min[i-m][j-1] * arr[i], dp_min[i][j]);
                }
            }else{
                for(int m = 1; m <= d && i-m >= j-2; m++){
                    dp_min[i][j] = min(dp_max[i-m][j-1] * arr[i], dp_min[i][j]);
                    dp_max[i][j] = max(dp_min[i-m][j-1] * arr[i], dp_max[i][j]);
                }
            }
            
        }
    }
    for(int i = k-1; i < num; i++){
        ans = max(ans, dp_max[i][k]);
    }
    printf("%.0lf\n", ans);
    return 0;
}