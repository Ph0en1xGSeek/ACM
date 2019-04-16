#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int num;
    int mx_num = 0;
    int arr[55];
    memset(arr, 0, sizeof(arr));
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > mx_num){
            mx_num = arr[i];
        }
    }
    int h_pos = 0;
    while((1 << h_pos) < mx_num){
        h_pos++;
    }
    int row, col;
    for(row = 0, col = 0; row < num && col < h_pos; row++, col++){
        int k = row;
        while((arr[k] & (1<<col)) == 0 && k < num){
            k++;
        }
        if(k == num){
            row--;
            continue;
        }else if(k != row){
            swap(arr[k], arr[row]);
        }
        for(int r = 0; r < num; r++){
            if(r == row){
                continue;
            }
            if((arr[r] & (1 << col)) != 0){
                arr[r] ^= arr[row];
            }
        }
    }
    printf("%d\n", row);
    return 0;
}
