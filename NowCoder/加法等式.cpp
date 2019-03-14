#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    for(int a = 0; a <= 5; a++){
        for(int b = 0; a+b <= 5; b++){
            for(int c = 1; c <= 6; c += 5){
                if(a*100 + b * 110 + c * 12 == 532){
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}
