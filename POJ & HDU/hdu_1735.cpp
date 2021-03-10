#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;


int main() {
    int n, l, m;
    int tot_zero = 0;
    int tmp_zero = 0;
    int first, second;
    vector<int> para;
    while(~scanf("%d%d%d", &n, &l, &m)) {
        tot_zero = 0;
        tmp_zero = 0;
        para.clear();
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &first, &second);
            if(first == 0 && second == 0) {
                para.push_back(tmp_zero + 2);
            }
            if(first == 0) {
                ++tot_zero;
            }
            if(second == 0) {
                ++tot_zero;
            }
            tmp_zero = 0;
            for(int j = 2; j < l; ++j) {
                scanf("%d", &first);
                if(first == 0) {
                    ++tmp_zero;
                    ++tot_zero;
                }else {
                    tmp_zero = 0;
                }
            }
        }
        sort(para.begin(), para.end(), greater<int>());
        int num_paras = para.size();
        for(int i = 0; i < m-1; ++i) {
            tot_zero -= para[i];
        }
        tot_zero -= tmp_zero;
        tot_zero -= 2;
        printf("%d\n", tot_zero);
    }
    
    return 0;
}