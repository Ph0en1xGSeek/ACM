#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;
int main()
{
    string s1;
    m["Baltimore-Bullets"] = 1;
    m["Boston-Celtics"] = 17;
    m["Chicago-Bulls"] = 6;
    m["Cleveland-Cavaliers"] = 1;
    m["Dallas-Mavericks"] = 1;
    m["Detroit-Pistons"] = 3;
    m["Golden-State-Warriors"] = 2;
    m["Houston-Rockets"] = 2;
    m["L.A.-Lakers"] = 11;
    m["Miami-Heat"] = 3;
    m["Milwaukee-Bucks"] = 1;
    m["Minneapolis-Lakers"] = 5;
    m["New-York-Knicks"] = 2;
    m["Philadelphia-76ers"] = 2;
    m["Philadelphia-Warriors"] = 2;
    m["Portland-Trail-Blazers"] = 1;
    m["Rochester-Royals"] = 1;
    m["San-Antonio-Spurs"] = 5;
    m["Seattle-Sonics"] = 1;
    m["St.-Louis-Hawks"] = 1;
    m["Syracuse-Nats"] = 1;
    m["Washington-Bullets"] = 1;

    int ca;
    scanf("%d", &ca);
    getchar();
    for(int i = 1; i <= ca; i++)
    {
        getline(cin, s1);
        for(int i = 0 ; i < s1.length(); i++)
            if(s1[i] == ' ') s1[i] = '-';
        printf("Case #%d: %d\n", i, m[s1]);
    }
    return 0;
}
