#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

set<int>st;

int main()
{
    int ca;
    int n, tmp, sum;
    scanf("%d", &ca);
    while(ca--)
    {
        sum = 1;
        st.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if(st.count(tmp) != 0)
            {
                sum ++;
                st.clear();
            }
            st.insert(tmp);
        }
        printf("%d\n", sum);
    }
    return 0;
}
