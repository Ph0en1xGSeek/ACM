#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int arr[1003];
set<int> s;
int m, n, tmp;

bool bsearch(int x)
{
    int left = 0;
    int right = m-1;
    int mid;
    do
    {
        mid = (left + right) / 2;
        if(arr[mid] > x)
            right = mid;
        else if(arr[mid] < x)
            left = mid + 1;
        else
            return true;
    }while(left < right);
    return false;
}

int main()
{
    int ca;
    cin >> ca;
    int nn;
    while(ca--)
    {
        s.clear();
        nn = 0;
        cin >> m >> n;
        for(int i = 0; i < m; i++)
            cin >> arr[i];
        sort(arr, arr + m);
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            s.insert(tmp);
        }
        for(set<int>::iterator it = s.begin(); it != s.end(); it++)
        {
            if(bsearch(*it))
            {
                if(nn == 0)
                {
                    cout << *it;
                    nn++;
                }
                else
                    cout << ' ' << *it;
            }
        }
        cout << endl;
    }
    return 0;
}

