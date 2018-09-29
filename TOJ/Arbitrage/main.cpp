#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
#include <string>

using namespace std;
double arr[31][31];

double max(double a, double b)
{
    return a > b ? a : b;
}

int main()
{
    map<string, int> name;
    int num , m;
    int a, b;
    double trans;
    string cash1, cash2;
    int ca = 1;
    while(cin >> num && num)
    {
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < num; i++)
        {
            cin >> cash1;
            name[cash1] = i;
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> cash1;
            a = name[cash1];
            cin >> trans;
            cin >> cash2;
            b = name[cash2];
            arr[a][b] = trans;
        }
        for(int k = 0; k < num; k++)
            for(int i = 0; i < num; i++)
                for(int j = 0; j < num; j++)
                    arr[i][j] = max(arr[i][j], arr[i][k]*arr[k][j]);
        bool flag = false;
        for(int i = 0; i < num; i++)
        {
            if(arr[i][i] > 1)
            {
                cout << "Case " << ca++ << ": Yes" <<endl;
                flag = true;
                break;
            }
        }
        if(!flag)
            printf("Case %d: No\n", ca++);
    }
    return 0;
}
