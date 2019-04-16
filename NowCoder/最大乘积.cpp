#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 0x7f7f7f7f

using namespace std;

int main(){
    int num;
    vector<long long> arr;
    long long tmp = 0;
    long long mi = MAX;
    long long mx = -MAX;
    int mx_pos = 0, mi_pos = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        cin >> tmp;
        arr.push_back(tmp);
        if(tmp < mi){
            mi = tmp;
            mi_pos = arr.size()-1;
        }
        if(tmp > mx){
            mx = tmp;
            mx_pos = arr.size()-1;
        }
    }

    vector<int> is_mx;
    vector<int> is_mi;
    is_mx.push_back(mx_pos);
    is_mi.push_back(mi_pos);
    for(int i = 0; i < 2; i++){
        long long cur_mx = -MAX;
        long long cur_mi = MAX;
        mx_pos = 0, mi_pos = 0;
        for(int j = 0; j < arr.size(); j++){
            bool flag1 = false;
            bool flag2 = false;
            for(int k = 0; k < is_mx.size(); k++){
                if(is_mx[k] == j){
                    flag1 = true;
                    break;
                }
            }
            for(int k = 0; k < is_mi.size(); k++){
                if(is_mi[k] == j){
                    flag2 = true;
                    break;
                }
            }
            if(arr[j] >= 0){
                if(!flag1 && arr[j] * mx > cur_mx){
                    cur_mx = arr[j] * mx;
                    mx_pos = j;
                }
                if(!flag2 && arr[j] * mi < cur_mi){
                    cur_mi = arr[j] * mi;
                    mi_pos = j;
                }
            }else{
                if(!flag2 && arr[j] * mi > cur_mx){
                    cur_mx = arr[j] * mi;
                    mx_pos = j;
                }
                if(!flag1 && arr[j] * mx < cur_mi){
                    cur_mi = arr[j] * mx;
                    mi_pos = j;
                }
            }
        }
        vector<int> tmp1;
        vector<int> tmp2;
        if(arr[mx_pos] < 0){
            for(int j = 0; j < is_mi.size(); j++){
                tmp1.push_back(is_mi[j]);
            }
        }
        if(arr[mi_pos] < 0){
            for(int j = 0; j < is_mx.size(); j++){
                tmp2.push_back(is_mx[j]);
            }
        }
        if(arr[mx_pos] < 0){
            is_mx = tmp1;
        }
        if(arr[mi_pos] < 0){
            is_mi = tmp2;
        }
        mx = cur_mx;
        mi = cur_mi;
        is_mx.push_back(mx_pos);
        is_mi.push_back(mi_pos);
    }
    cout << mx << endl;
    return 0;
}
