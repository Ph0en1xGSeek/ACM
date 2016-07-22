#include <iostream>

using namespace std;

const int Max = 10010;
int father[Max];
int mov[Max];
int num[Max];
int ball;

void init()
{
    for(int i = 0; i < Max; i++)
    {
        father[i] = -1;
        mov[i] = 0;
        num[i] = 1;
    }
}

int getFather(int x)
{
    if(father[x] == -1)
        return x;


    int temp = father[x];
    father[x] = getFather(father[x]);
    mov[x] += mov[temp];
    return father[x];
}

void unions(int a, int b)
{
    int fa = getFather(a);
    int fb = getFather(b);
    if(fa != fb)
    {
        father[fa] = fb;
        num[fb] += num[fa];
        mov[fa] = 1;
    }
}

int main()
{
    int n;
    int line, a, b, q;
    char com;
    cin >> n;
    int round = 0;
    while(n--)
    {
        init();
        round++;
        cin >> ball >> line;
        cout << "Case " << round << ':' << endl;
        while(line--)
        {
            cin >> com;
            if(com == 'T')
            {
                cin >> a >> b;
                unions(a, b);
            }
            else
            {
                cin >> q;
                int h = getFather(q);

                cout << h << ' ' << num[h] << ' ' << mov[q] << endl;
            }
        }
    }
    return 0;
}
