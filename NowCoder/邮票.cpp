#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
    set<int> price_set;
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 4; j++){
            for(int k = 0; k <= 6; k++){
                if(i + j + k == 0){
                    continue;
                }
                price_set.insert(8 * i + 10 * j + 18 * k);
            }
        }
    }
    printf("%d\n", price_set.size());
    return 0;
}
