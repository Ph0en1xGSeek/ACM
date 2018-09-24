#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

long long toDeci(string num , int transFrom);
string toGoal(int deci , int transTo);
bool isFloat(string num);
int pointAt(string num);//where is the point in the float
int toDeciF(string num , int transFrom , int len);
double toDecimals(string num , int transFromm , int len);
string toGoalFlo(double flo , int transTo);

int main()
{
    int transFrom , transTo；
    long long deci ;
    double flo/* used if it is float */;
    string num , goal , goalFlo/* used if it is float */;
    cout << "~~ 数制转换 v2.0 ~~" << endl << endl;
    while(1)
    {
        cout << "----------------------------------------------------------------" << endl;

        cout << "\n请输入被转换数数制：";
        cin >> transFrom;
        cout << "\n请输入要转换的数字：" ;
        cin >> num;
        cout << "\n请输入目标数数制：";
        cin >> transTo;

        if(!isFloat(num))   //integer transform
        {
            deci = toDeci(num , transFrom);
            goal = toGoal(deci , transTo);
            cout << "\n目标数为：" << goal << endl;
        }
        else   //Float transform
        {
            int point = pointAt(num);
            deci = toDeciF(num , transFrom , point);
            int len = num.length();
            //int fLen = len - 1 - point;//the length of number after point
            flo = toDecimals(num , transFrom , len);//transform the number after point
            goal = toGoal(deci , transTo);
            goalFlo = toGoalFlo(flo , transTo);
            cout << "\n目标数为: ";

            cout << goal << '.' << goalFlo << "\n" << endl;
        }
    }

    system("pause");
    return 0;
}




long long toDeci(string num , int transFrom)
{
    int wei;
    long long deci = 0;
    int len = num.length();
    for (unsigned i = 0 ; i < len ; i++)
    {

        if(num[i] >= '0' && num[i] <= '9')
            wei = static_cast<int>(num[i] - '0');
        if(num[i] >= 'A' && num[i] <= 'Z')
            wei = static_cast<int>(num[i] - 'A' + 10);
        if(num[i] >= 'a' && num[i] <= 'z')
            wei = static_cast<int>(num[i] - 'a' + 36);
        deci = deci * transFrom + wei;


    }
    return deci;

}


string toGoal(int deci , int transTo)
{
    string goal;

    int i = 0;
    while(deci != 0)
    {
        int wei = deci % transTo;
        deci = deci / transTo;
        if(wei >= 0 && wei <= 9)
            goal += '0' + wei;
        if(wei >= 10 && wei <= 35)
            goal += 'A' + wei - 10;
        if(wei >= 36 && wei <= 64)
            goal += 'a' + wei - 36;
        i++;

    }
    for(int a = 0 ; a < i / 2 ; a++)//swap to get the real result
        {
            char temp;
            temp = goal[a];
            goal[a] = goal[i - 1 - a];
            goal[i - 1 - a] = temp;
        }
    return goal;
}



bool isFloat(string num)
{
    for(int i = 0 ; i < num.length() ; i++)
    {
        if(num[i] == '.')
            return true;
    }
    return false;
}

int pointAt(string num)
{
    for(int i = 0 ; i < num.length() ; i++)
    {
        if(num[i] == '.')
            return i;
    }
}



int toDeciF(string num , int transFrom , int len)
{
    int wei;
    int deci = 0;
    for (unsigned i = 0 ; i < len ; i++)
    {

        if(num[i] >= '0' && num[i] <= '9')
            wei = static_cast<int>(num[i] - '0');
        if(num[i] >= 'A' && num[i] <= 'Z')
            wei = static_cast<int>(num[i] - 'A' + 10);
        if(num[i] >= 'a' && num[i] <= 'z')
            wei = static_cast<int>(num[i] - 'a' + 36);
        deci = deci * transFrom + wei;


    }
    return deci;

}


double toDecimals(string num , int transFromm , int len)
{
    int wei;
    double flo = 0.0;
    int point = pointAt(num);
    int exp = -1;
    for (int i = point + 1 ; i <= len - 1 ; i++ )//from decimal point to the end
    {

        if(num[i] >= '0' && num[i] <= '9')
            wei = static_cast<int>(num[i] - '0');
        if(num[i] >= 'A' && num[i] <= 'Z')
            wei = static_cast<int>(num[i] - 'A' + 10);
        if(num[i] >= 'a' && num[i] <= 'z')
            wei = static_cast<int>(num[i] - 'a' + 36);
        flo = flo + wei * pow(transFromm , exp);
        exp--;

    }
    return flo;
}

string toGoalFlo(double flo , int transTo)
{
    string goalFlo;
    int i = 0;
    while(flo != 0 && i <= 32)
    {
        double d = flo * transTo;
        int wei = d;
        flo = d - static_cast<double>(wei);
        if(wei >= 0 && wei <= 9)
            goalFlo += '0' + wei;
        if(wei >= 10 && wei <= 35)
            goalFlo += 'A' + wei - 10;
        if(wei >= 36 && wei <= 64)
            goalFlo += 'a' + wei - 36;
        i++;
    }

    return goalFlo;
}
