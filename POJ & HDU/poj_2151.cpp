#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

#define M 32
#define T 1002

using namespace std;

double p[T][M]; // probability of team i solves problem j
double dp[T][M][M]; // probability of team i solves k of the first j problems
double s[T][M]; //probability of team i solves at most j problems
int main(){
    int m, t, n;
    while(scanf("%d%d%d", &m, &t, &n) && m != 0){
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));
        for(int i = 1; i <= t; i++){
            for(int j = 1; j <= m; j++){
                scanf("%lf", &p[i][j]);
            }
        }
        for(int i = 1 ; i <= t; i++){
            dp[i][0][0] = 1.0;
            for(int j = 1; j <= m; j++){
                dp[i][j][0] = dp[i][j-1][0] * (1 - p[i][j]);
                for(int k = 1; k <= j; k++){
                    dp[i][j][k] = dp[i][j-1][k-1] * p[i][j] + dp[i][j-1][k] * (1 - p[i][j]);
                }
            }
        }
        for(int i = 1; i <= t; i++){
            s[i][0] = dp[i][m][0];
            for(int j = 1; j <= m; j++){
                s[i][j] = s[i][j-1] + dp[i][m][j];
            }
        }
        double p1 = 1.0;
        for(int i = 1; i <= t; i++){
            p1 *= (1-s[i][0]);
        }
        double p2 = 1.0;
        for(int i = 1; i <= t; i++){
            p2 *= (s[i][n-1] - s[i][0]);
        }
        printf("%.3f\n", p1-p2);
    }
    return 0;
}
