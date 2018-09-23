#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int ca;
    int num;
    int diff[25];
    int arr[25];
    arr[0] = 0;
    scanf("%d", &ca);
    while(ca--){
        memset(diff, 0, sizeof(diff));
        scanf("%d", &num);
        for(int i = 1; i <= num; i++){
            scanf("%d", &arr[i]);
            diff[i] = arr[i] - arr[i-1];
        }
        for(int i = 1; i <= num; i++){
            int j = i;
            /*number of right parentheses between (j-1)th and (i)th right parentheses, including (i)th*/
            int num_right = 1;
            /*number of left parentheses between (j-1)th and (i)th right parentheses*/
            int num_left = diff[j];
            while(num_right > num_left){
                num_right += 1;
                j--;
                num_left += diff[j];
            }
            printf("%d ", num_right);
        }
        printf("\n");
    }
    return 0;
}
