#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool lesss(int a, int b)
{
    return a < b;
}
bool greaterr(int a, int b)
{
    return a > b;
}

int mid, tmp, ca, num;
char op[5];
vector<int> mx, mi;

void add(int t)
{
    if(t <= mid)
    {
        mx.push_back(t);
        push_heap(mx.begin(), mx.end(), lesss);
    }
    else
    {
        mi.push_back(t);
        push_heap(mi.begin(), mi.end(), greaterr);
    }
    if((mx.size()) >= 2 + mi.size())
    {
        mi.push_back(mid);
        push_heap(mi.begin(), mi.end(), greaterr);
        mid = mx.front();
        pop_heap(mx.begin(), mx.end(), lesss);
        mx.pop_back();
    }
    else if((mi.size()) >= 2 + (mx.size()))
    {


        mx.push_back(mid);
        push_heap(mx.begin(), mx.end(), lesss);
        mid = mi.front();
        pop_heap(mi.begin(), mi.end(), greaterr);
        mi.pop_back();
    }

}

int main()
{
    mi.clear();
    mx.clear();
    scanf("%d%d", &num, &mid);
    for(int i = 1; i < num; i++)
    {
        scanf("%d", &tmp);
        add(tmp);
    }
    if(mx.size() > mi.size())
        printf("%d\n", mx.front());
    else
        printf("%d\n", mid);
    return 0;
}
