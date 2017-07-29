#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n, a;
    while(cin >> n >> a)
    {
        int k = 0;
        int t = 1;
        for(int i = 1; i <= n; i++)
        {
            t *= i;
            while(t % a == 0)
            {
                t /= a;
                k++;
            }
            t %= a;
        }
        cout << k << endl;
    }
    return 0;
}
