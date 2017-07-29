#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char ch;
    int ca, ans, mx;
    cin >> ca;
    getchar();
    for(int i = 1; i <= ca; i++)
    {
        ans = 0;
        mx = 0;
        while(1)
        {
            ch = getchar();
            if(ch == '\n')
            {
                cout << i << ' ' << (1<<mx) << endl;
                break;
            }
            if(ch == '[')
            {
                ans++;
                mx = max(mx, ans);
            }
            else
                ans--;
        }

    }
    return 0;
}
