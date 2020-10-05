#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

map<string, int> m;
queue<string> q;

int bfs(string str, int n)
{
    q.push(str);
    int ret = 0;
    while(!q.empty())
    {
        int siz = q.size();
        while(siz--)
        {
            string str2 = q.front();
            q.pop();
            if(m.count(str2) == 0)
            {
                m[str2] = 1;
                if (str2.find("2012",0)!=string::npos) return ret;
                for(int i = 0; i < n-1; i++)
                {
                    string str3 = str2;
                    swap(str3[i], str3[i+1]);
                    q.push(str3);
                }
            }

        }
        ret++;
    }
    return -1;
}

int main()
{
    int n;
    string str;
    while(scanf("%d", &n) != EOF)
    {
        m.clear();
        while(!q.empty()) q.pop();
        cin >> str;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '0') cnt0++;
            else if(str[i] == '1') cnt1++;
            else if(str[i] == '2') cnt2++;
        }
        if(cnt0 < 1 || cnt1 < 1 || cnt2 < 2) printf("-1\n");
        else printf("%d\n", bfs(str, n));

    }
    return 0;
}
