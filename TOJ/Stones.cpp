#include <iostream>

using namespace std;

int main()
{
    int ca;
    cin >> ca;
    int ans;
    int mx = 0;
    int num, n;
    while(ca--)
    {
        ans = 0;
        cin >> num;
        while(num--)
        {
            cin >> n;
            mx = max(mx, n);
            ans += n;
        }
        ans -= mx;
        cout << ans << endl;
    }
    return 0;
}
