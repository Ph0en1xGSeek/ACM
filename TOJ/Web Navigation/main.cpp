#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> s1, s2;//back forward
    while(!s1.empty())
        s1.pop();
    while(!s2.empty())
        s2.pop();
    string cmd, now = "http://www.acm.org/";
    while(cin >> cmd && cmd != "QUIT")
    {
        if(cmd == "VISIT")
        {
            s1.push(now);
            while(!s2.empty())
                s2.pop();
            cin >> now;
            cout << now << endl;
        }
        else if(cmd == "BACK")
        {
            if(s1.empty())
            {
                cout << "Ignored" << endl;
                continue;
            }
            s2.push(now);
            now = s1.top();
            s1.pop();
            cout << now << endl;
        }
        else
        {
            if(s2.empty())
            {
                cout << "Ignored" << endl;
                continue;
            }
            s1.push(now);
            now = s2.top();
            s2.pop();
            cout << now << endl;
        }
    }
    return 0;
}
