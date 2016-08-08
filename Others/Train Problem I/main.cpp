#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int num;

    string str1, str2;

    while(cin >> num >> str1 >> str2)
    {
        bool point = false;
        string stream;
        stack<char> s, s1;
        for(int i = num - 1; i >= 0; i--)
            s1.push(str1[i]);
        for(int i = 0; i < num; i++)
        {
            if(!s.empty() && str2[i] == s.top())
            {
                s.pop();
                stream += "out\n";
            }
            else if(!s1.empty() && str2[i] == s1.top())
            {
                s1.pop();
                stream += "in\nout\n" ;
            }
            else if (!s1.empty())
            {
                s.push(s1.top());
                s1.pop();
                i--;
                stream += "in\n";
            }
            else
            {
                point = true;
                cout << "No.\n";
                break;
            }
        }
        if(!point)
            cout << "Yes.\n" << stream;
        cout << "FINISH" << endl;
    }

    return 0;
}
