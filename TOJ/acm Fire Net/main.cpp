#include <iostream>

using namespace std;
void isValid();
bool check(int x, int y);

char city[4][4];
int size = 0;
int counts = 0;
int num = 0;
int main()
{

    cin >> size;
    while(size)
    {
        counts = 0;
        num = 0;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size ; j++)
                cin >> city[i][j];
        }

        isValid();
        cout << num << endl;
        cin >> size;
    }




    return 0;
}

void isValid()
{
    if(counts > num)
        num = counts;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size ; j++)
        {
            if(check(i, j) && city[i][j] == '.')
            {
                counts++;
                city[i][j] = 'b';
                isValid();
                counts--;
                city[i][j] = '.';//有了这两行才可以做到从任意一个地方开始，并把所有排列可能都列出来
            }
        }
    }

}

bool check(int x, int y)
{
    for(int i = 1 ; x - i >= 0 && city[x - i][y] != 'X'; i++)
    {
        if(city[x - i][y] == 'b')
            return false;
    }
    for(int i = 1 ; x + i < size && city[x + i][y] != 'X'; i++)
    {
        if(city[x + i][y] == 'b')
            return false;
    }
    for(int i = 1 ; y - i >= 0 && city[x][y - i] != 'X'; i++)
    {
        if(city[x][y - i] == 'b')
            return false;
    }
    for(int i = 1 ; y + i < size && city[x][y + i] != 'X'; i++)
    {
        if(city[x][y + i] == 'b')
            return false;
    }
    return true;
}
