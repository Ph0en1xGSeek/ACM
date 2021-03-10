#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, f, d, p;
    while(cin >> x >> f >> d >> p) {
        if(d / x < f) {
            cout << d / x <<endl;
        }else {
            cout << f + (d - x * f) / (p + x);
        }
    }
    return 0;
}
