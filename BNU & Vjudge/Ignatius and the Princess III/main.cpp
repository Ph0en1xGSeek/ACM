#include<iostream>
using namespace std;

int main()
{
    int i, j ,n, a[125][125] = {0};
    for(i = 1; i < 125; i++)
        a[i][1]=a[1][i] = 1;
    for(i  = 2; i < 125; i++)
        for(j = 2; j < 125; j++)
        {
            if(i < j)
            a[i][j] = a[i][i];
            if(i == j)
                a[i][j] = a[i][j-1] + 1;
            if(i > j)
                a[i][j] = a[i-j][j] + a[i][j-1];
        }
    while(cin >> n)
        cout << a[n][n] << endl;
    return 0;
}
