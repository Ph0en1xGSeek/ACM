#include <iostream>

using namespace std;
string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int num[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{

    int d, m;
    while(cin >> d >> m)
    {
        int ans = 3;
        for(int i = 1; i < m; i++)
            ans += num[i];
        ans += d;
        ans %= 7;
        cout << week[ans] << endl;
    }
    return 0;
}
