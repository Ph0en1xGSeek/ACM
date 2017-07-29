#include <iostream>
#include <cmath>

using namespace std;
int arr[2][10000];

int main()
{
    int u = 0;
    long long num, i = 1, j = 1, sum = 0;
    while(cin >> num)
    {
        i = 1;
        j = 1;
        sum = 0;
        u = 0;
        while(j * j <= num)
        {
            /*while(sum < num)
            {
                sum += j * j;
                j++;
            }
            while(sum > num)
            {
                sum -= i * i;
                i++;
            }
            if(sum == num)
            {
                arr[0][u] = i;
                arr[1][u] = j;
                u++;
            }*/
            while(j*j<=num)
        {
            sum+=j*j;
            if(sum>=num)
            {
                while(sum>num)
                {
                    sum-=i*i;
                    i++;
                }
                if(sum==num)
                {
                    arr[0][u]=i;
                    arr[1][u]=j;
                    u++;
                }
            }
            j++;

        }
        }
        cout << u << endl;
        for(int a = 0; a < u; a++)
        {
            cout << arr[1][a] - arr[0][a] + 1 ;
            for(int k = arr[0][a]; k <= arr[1][a]; k++)
                cout << ' ' << k;
            cout << endl;
        }
    }

    return 0;
}
