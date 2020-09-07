#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    int k = 0;

    int cnt[30] = {0};

    cin >> s >> t;
    int lens = s.length();
    int lent = t.length();

    for(int i = 0; i < lens; i++)
    {
        if(s[i] != '?')
            cnt[s[i] - 'a']++;
    }

    for(int i = 0; i < lens; i++)
    {
        if(s[i] == '?')
        {
            k++;
            k %= lent;
            if(cnt[t[k] - 'a'] > 0)
            {
                cnt[t[k] - 'a']--;
                i--;
            }
            else
            {
                s[i] = t[k];
            }
        }
    }

    cout << s << endl;

    return 0;
}