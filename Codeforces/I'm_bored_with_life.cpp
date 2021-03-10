#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {

    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)
    {
        if(a > b)
            swap(a, b);
        for(int i = a-1; i >= 1; i--)
        {
            a *= i;
        }

        printf("%d\n", a);
    }
    return 0;
}