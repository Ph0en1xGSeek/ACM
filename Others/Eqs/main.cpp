#include <iostream>
#include <cstring>

using namespace std;
short hash[25000001];
int main()
{
    int a1, a2, a3, a4, a5;

    int sum;
    int total = 0;
    while(cin >> a1 >> a2 >> a3 >> a4 >> a5)
    {
        memset(hash,0,sizeof(hash));
            for(int x1 = -50; x1 <= 50; x1++)
            {
                if(x1 == 0)
                    continue;
                for(int x2 = -50; x2 <= 50; x2++)
                {
                    if(x2 == 0)
                        continue;
                    sum = (-1)*(a1*x1*x1*x1 + a2*x2*x2*x2);
                    if(sum < 0)
                        sum += 25000000;
                    hash[sum]++;
                }
            }

            for(int x3 = -50; x3 <= 50; x3++)
            {
                if(x3 == 0)
                    continue;
                for(int x4 = -50; x4 <= 50; x4++)
                {
                    if(x4 == 0)
                        continue;
                    for(int x5 = -50; x5 <= 50; x5++)
                    {
                        if(x5 == 0)
                            continue;
                        sum = a3*x3*x3*x3 + a4*x4*x4*x4 + a5*x5*x5*x5;
                        if(sum < 0)
                            sum += 25000000;
                        if(hash[sum])
                            total += hash[sum];
                    }
                }
            }
            cout << total << endl;

    }
    return 0;
}
