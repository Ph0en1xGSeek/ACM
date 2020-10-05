#include <stdio.h>
#include <iostream>


using namespace std;
long long  a[105][105];
long long row[105];
int n;

int main()
{
    while(scanf("%d",&n)!= EOF)
    {
        long long sum=0;
        int i, j;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cin >> a[i][j];
                row[i]+=a[i][j];
            }
        }
        for(i=0; i<n; i++)
            sum+=row[i];
        sum /= (n-1);
        for(i=0; i<n; i++)
            a[i][i]=sum-row[i];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-1; j++)
                cout << a[i][j] << ' ';
            cout << a[i][n-1] << endl;
        }
    }
}
