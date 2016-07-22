#include <iostream>

using namespace std;

long long C[65][65];
long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
void init()
{
    for(long long i = 1; i <= 64; i++)
    {
        C[i][i] = 1;
        C[i][0] = 1;
        C[i][1] = i;
    }
    for(long long i = 2; i <= 63; i++)
        for(long long j = 1; j+i <= 64; j++)
        {
            int g = gcd(C[i+j-1][j], (j+1));
            C[i+j][j+1] = C[i+j-1][j]/g *(i+j)/((j+1)/g);
        }
}



long long c(long long a, long long b)
{
   b = min(b, a-b);
   long long aa = 1, bb = 1;
   while(b >= 1)
   {
       aa = (aa * a);
       bb = (bb * b);
       long long d = gcd(aa, bb);
       aa/=d;
       bb/=d;
       a--;
       b--;
   }
   return aa/bb;
}

int main()
{
    long long a, b;
    init();
    int n, m;
    while(cin >> n >> m)
    cout << C[n][m] << endl;

    return 0;
}
