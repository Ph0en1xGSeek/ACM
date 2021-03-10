#include <iostream>

using namespace std;

int main()
{
    int ca, num, tmp, ans;
    cin >> ca;
    while(ca--)
    {
        ans = 0;
        cin >> num;
        for(int i = 0; i < num; i++)
        {
            cin >> tmp;
            ans += tmp;
        }
        ans = ans + 1 - num;
        cout << ans << endl;
    }
    return 0;
}
