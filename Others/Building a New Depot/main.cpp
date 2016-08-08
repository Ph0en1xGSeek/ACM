#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct point
{
    int x;
    int y;
};

vector<point> p;
point temp;

bool cmpx(point p1, point p2)
{
    if(p1.x == p2.x)
        return p1.y < p2.y;
    else
        return p1.x < p2.x;
}

bool cmpy(point p1, point p2)
{
    if(p1.y == p2.y)
        return p1.x < p2.x;
    else
        return p1.y < p2.y;
}
int main()
{
    int sum;
    int num;
    while(cin >> num && num)
    {
        sum = 0;
        p.clear();
        for(int i = 0; i < num; i++)
        {
            cin >> temp.x >> temp.y;
            p.push_back(temp);
        }

        sort(p.begin(), p.end(), cmpx);
        for(int i = 0; i < num; i+=2)
        {
            sum += (p[i + 1].y - p[i].y);
        }

        sort(p.begin(), p.end(), cmpy);
        for(int i = 0; i < num; i+=2)
        {
            sum += (p[i + 1].x - p[i].x);
        }
        cout << "The length of the fence will be " << sum << " units." << endl;
    }

    return 0;
}
