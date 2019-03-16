#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    double num;
    while(~scanf("%lf", &num)){
        double tmp = sqrt(num);
        tmp = floor(tmp);
        if(tmp * (tmp + 1.0) > num){
            tmp -= 1;
        }
        printf("%.0lf\n", tmp);
    }
    return 0;
}
