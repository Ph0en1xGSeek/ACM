#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {

    long long n, k;
    while (scanf("%lld%lld", &n, &k) != EOF)
    {
        long long diplomas = n / 2 / (k+1);
        long long certification = k * diplomas;
        long long loser = n - diplomas - certification;

        printf("%lld %lld %lld\n", diplomas, certification, loser);

    }
    return 0;
}