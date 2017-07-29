#include <iostream>

using namespace std;

bool one(char arr[][10], char arr2[][10], int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(arr[i][j] != arr2[j][num - 1 - i])
                return false;
        }
    }
    return true;
}

bool two(char arr[][10], char arr2[][10], int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(arr[i][j] != arr2[num - i - 1][num - j - i])
                return false;
        }
    }
    return true;
}

bool three(char arr[][10], char arr2[][10], int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(arr[i][j] != arr2[num - j - 1][i])
                return false;
        }
    }
    return true;
}

bool four(char arr[][10], char arr2[][10], int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(arr[i][j] != arr2[i][num - j - 1])
                return false;
        }
    }
    return true;
}

bool five(char arr[][10], char arr2[][10], int num)
{
    char temp[10][10];
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            temp[i][j] = arr[i][num - j - 1];
        }
    }
    if(!one(temp, arr2, num) && !two(temp, arr2, num) && !three(temp, arr2, num))
        return false;
    else
        return true;
}


bool six(char arr[][10], char arr2[][10], int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(arr[i][j] != arr2[i][j])
                return false;
        }
    }
    return true;
}
int main()
{
    int num;
    cin >> num;
    char arr[10][10];
    char arr2[10][10];
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            cin >> arr2[i][j];
        }
    }
    if(one(arr, arr2, num))
        cout << 1 << endl;
    else if(two(arr, arr2, num))
        cout << 2 << endl;
    else if(three(arr, arr2, num))
        cout << 3 << endl;
    else if(four(arr, arr2, num))
        cout << 4 << endl;
    else if(six(arr, arr2, num))
        cout << 6 << endl;
    else
        cout << 7 << endl;
    return 0;
}

