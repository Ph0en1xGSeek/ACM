#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
            long long n;
            scanf("%I64d",&n);
            int cnt=0;
            while(n%2==0)
            {
                cnt++;
                n/=2;
            }
            if(cnt%2)
                cout<<"Second Box"<<endl;
            else
                cout<<"First Box"<<endl;
    }
    return 0;
}
