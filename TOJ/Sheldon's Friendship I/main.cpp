#include <iostream>
#include <map>
#define INF 100000

using namespace std;

map<int, string> m;
int main()
{
    int ca;
    cin >> ca;
    string str;
    int num;
    int tmp;
    while(ca--)
    {
        tmp = INF;
        for(int i = 0; i < 4; i++)
        {
            cin >> str >> num;
            m[num] = str;
            tmp = min(tmp, num);
        }
        cout << "Poor " << m[tmp] << endl;

    }
    return 0;
}
