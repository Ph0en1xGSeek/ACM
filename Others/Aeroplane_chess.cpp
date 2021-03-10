#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int father[100000];
double e[100000];

int main()
{
    int n, m;
    int a, b;
    while(cin >> n >> m && n != 0)
    {
        memset(father, -1, sizeof(father));
        memset(e, 0, sizeof(e));
        while(m--)
        {
            cin >> a >> b;
            father[a] = b;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(father[i] != -1)
                e[i] = e[father[i]];
            else
            {
                for(int j = 1; j <= 6; j++)
                {
                    if(j + i <= n)
                        e[i] += (1.0/6) * e[i+j];
                }
                e[i] += 1;
            }
        }
        cout << setprecision(4) << fixed << e[0] <<endl;
    }
    return 0;
}
