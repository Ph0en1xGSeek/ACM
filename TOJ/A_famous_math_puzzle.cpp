#include <iostream>

using namespace std;
int col[101];

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int num, w;
    int mx, tmp;
    while(cin >> num >> w, num)
    {
        mx = 0;
        for(int i = 0; i < num; i++)
        {
            cin >> col[i];
            mx = max(col[i], mx);
        }
        if(mx < w)
        {
            cout << "NO\n";
            continue;
        }
        if(num == 1)
        {
            if(col[0] == w)
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        else
        {
            tmp = gcd(col[num-1], col[num-2]);
            for(int i = num-3; i >= 0; i--)
                tmp = gcd(tmp, col[i]);
            if(w % tmp == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }



    }
    return 0;
}
