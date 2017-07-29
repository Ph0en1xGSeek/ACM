#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int a1, b1, c1;
int a2, b2, c2;

void op(string str, int& a, int& b, int&c)
{
    int tmp = 0;
    int positive = 1;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '+')///有常数项要加上
        {
            c += positive * tmp;
            positive = 1;
            tmp = 0;
        }
        else if(str[i] == '-')
        {
            c += positive * tmp;
            positive = -1;
            tmp = 0;
        }
        else if(isdigit(str[i]))
        {
            tmp = tmp * 10 + (str[i] - '0');
        }
        else if(str[i] == 'x')
        {
            if(i+2 < str.length() && str[i+1] == '^' && str[i+2] == '2')///x^2
            {
                if(i != 0 && str[i-1] == '-')
                    a--;
                else if(i == 0 || str[i-1] == '+')///不写系数的情况
                    a++;
                else
                {
                    a += positive * (tmp);
                    tmp = 0;
                    positive = 1;
                }
                i += 2;
            }
            else///x
            {
                if(i != 0 && str[i-1] == '-')
                    b--;
                else if(i == 0 || str[i-1] == '+')///不写系数的情况
                    b++;
                else
                {
                    b += positive * (tmp);
                    tmp = 0;
                    positive = 1;
                }
            }
        }
    }
    c += positive * tmp;
}

int main()
{
    string str;
    while(cin >> str)
    {
        int pos = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '=')
            {
                pos = i;
                break;
            }
        }
        string leftStr = str.substr(0, pos);
        string rightStr = str.substr(pos+1);
        a1 = b1 = c1 = a2 = b2 = c2 = 0;
        op(leftStr, a1, b1, c1);
        op(rightStr, a2, b2, c2);
//        printf("%d %d %d\n", a1, b1, c1);
//        printf("%d %d %d\n", a2, b2, c2);
        double a = a1 - a2;
        double b = b1 - b2;
        double c = c1 - c2;
        double theta = b * b - 4 * a * c;
        if(theta < 0)
            printf("No Solution\n");
        else
        {
            double ans1 = (-b + sqrt(theta)) / (2 * a);
            double ans2 = (-b - sqrt(theta)) / (2 * a);
            if(ans2 < ans1) swap(ans1, ans2);
            printf("%.2lf %.2lf\n", ans1, ans2);
        }
    }
    return 0;
}

//4x^2+6x-7=x^2-2x+3
