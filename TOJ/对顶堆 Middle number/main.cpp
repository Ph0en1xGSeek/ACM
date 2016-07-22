#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int mid, tmp, ca, num;
char op[5];
vector<int> mx, mi;

void add(int t)
{
    if(t <= mid)
    {
        mx.push_back(t);
        push_heap(mx.begin(), mx.end(), less<int>());
    }
    else
    {
        mi.push_back(t);
        push_heap(mi.begin(), mi.end(), greater<int>());
    }
    if((mx.size()) >= 2 + mi.size())
    {
        mi.push_back(mid);
        push_heap(mi.begin(), mi.end(), greater<int>());
        mid = mx.front();
        pop_heap(mx.begin(), mx.end(), less<int>());
        mx.pop_back();
    }
    else if((mi.size()) >= 2 + (mx.size()))
    {


        mx.push_back(mid);
        push_heap(mx.begin(), mx.end(), less<int>());
        mid = mi.front();
        pop_heap(mi.begin(), mi.end(), greater<int>());
        mi.pop_back();
    }

}

int main()
{
    scanf("%d", &ca);
    while(ca--)
    {
        mi.clear();
        mx.clear();
        scanf("%d%d", &num, &mid);
        for(int i = 1; i < num; i++)
        {
            scanf("%d", &tmp);
            add(tmp);
        }
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%s", op);
            if(op[0] == 'a')
            {
                scanf("%d", &tmp);
                add(tmp);
            }
            else
            {
                if(mx.size() > mi.size())
                    printf("%d\n", mx.front());
                else
                    printf("%d\n", mid);
            }
        }
    }
    return 0;
}
