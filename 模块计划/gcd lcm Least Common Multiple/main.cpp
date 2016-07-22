#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int small = (a < b)? a:b;
    int big = (a > b)? a:b;
    if(small == 0)
         return big;
    int remain = big % small;
    return gcd(small, remain);
}

int gcd2(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}


int main()
{
    int ca;
    cin >> ca;
    int num, a, b;
    while(ca--)
    {
        cin >> num;
        cin >> a;
        for(int i = 0; i < num - 1; i++)
        {
            cin >> b;
            a = a/gcd(a, b)*b;
        }
        cout << a << endl;
    }
    return 0;
}
