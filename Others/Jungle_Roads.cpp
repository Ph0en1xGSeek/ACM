#include <iostream>
#include <algorithm>

using namespace std;

int father[27];
bool isAdd;

struct edge
{
    int len;
    int from;
    int to;
}e[1000];

int cmp(const void* a, const void* b)
{
     return (*(edge *)a).len > (*(edge *)b).len ? 1 : -1;
}

void init()
{
    for(int i = 0; i < 27; i++)
        father[i] = -1;
    for(int i = 0; i < 1000; i++)
    {
        e[i].len = 0;
        e[i].from = 0;
        e[i].to = 0;
    }
}

int getFather(int n)
{
    if(father[n] == -1)
        return n;
    return father[n] = getFather(father[n]);
}

void unions(int a, int b)
{
    a = getFather(a);
    b = getFather(b);
    if(a != b)
    {
        father[b] = a;
        isAdd = true;
    }
    else
        isAdd = false;

}

int main()
{
    int num;
    char ch, ch2;
    int road;
    int lent;
    int total;
    cin >> num;
    while(num)
    {

        total = 0;
        init();
        int counts = 0;
        for(int i = 0; i < num - 1; i++)
        {
            cin >> ch;
            cin >> road;
            while(road--)
            {
                cin >> ch2 >> lent;
                e[counts].from = ch - 64;
                e[counts].to = ch2 - 64;
                e[counts].len = lent;
                counts++;
            }
        }
        qsort(e, counts, sizeof(e[0]), cmp);
        for(int i = 0; i < counts; i++)
        {
            unions(e[i].from, e[i].to);
            if(isAdd)
                total += e[i].len;
        }
        cout << total << endl;
        cin >> num;
    }


    return 0;
}
