#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > q;
    int num, score;
    char ch;
    while(cin >> num && num)
    {
        while(!q.empty())
            q.pop();
        while(num--)
        {
            cin >> ch;
            if(ch == 'B')
            {
                cin >> score;
                q.push(score);
            }
            else if(ch == 'G')
            {
                score = q.top();
                q.pop();
                cout << score << endl;
            }
        }
    }
    return 0;
}
