#include <iostream>
#include <algorithm>

using namespace std;

struct Time
{
    int kaishi;
    int jieshu;
};

int cmp(const void* a, const void* b)
{
    return (*(Time*)a).kaishi - (*(Time*)b).kaishi;
}

int main()
{
    int num;
    cin >> num;
    Time* range = new Time [num];
    for(int i = 0 ; i < num; i++)
        cin >> range[i].kaishi >> range[i].jieshu;
    qsort(range, num, sizeof(range[0]), cmp);
    int youren = range[0].jieshu - range[0].kaishi, meiren = 0;
    int from = range[0].kaishi, to = range[0].jieshu;
    for(int i = 1; i < num; i++)
    {
        if(range[i].kaishi <= to)
        {
            if(range[i].jieshu > to)
            {
                to = range[i].jieshu;
                youren = (to - from > youren)? to - from:youren;
            }

        }
        else
        {
            meiren = ((range[i].kaishi - to) > meiren)? range[i].kaishi - to:meiren;
            from = range[i].kaishi;
            to = range[i].jieshu;
        }
    }
    cout << youren << ' ' << meiren <<endl;
    return 0;
}



