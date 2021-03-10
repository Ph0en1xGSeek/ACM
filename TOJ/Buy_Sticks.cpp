#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int ca, ans;
    cin >> ca;
    for(int i = 1; i <= ca; i++)
    {
        cin >> a >> b >> c;
        if(a <= (b+c) * 2)
            ans = a/2 + (b+c-a/2 + a%2 + 1)/2;
        else
            ans = b + c + (a - 2*(b+c) + 2)/3;
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
