#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int from;
    int to;
}game[10086];

int cmp(node a, node b)
{
    return a.to < b.to;
}

int main()
{
    int num, f, t;
    while(cin >> num, num)
    {
        for(int i = 0; i < num; i++)
        {
             cin >> f >> t;
             game[i].from = f;
             game[i].to = f + t;
        }
        sort(game, game+num, cmp);
        int m = 0, cnt = 1;
        for(int i = 1; i < num; i++)
        {
            if(game[i].from >= game[m].to)
            {
                m = i;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
