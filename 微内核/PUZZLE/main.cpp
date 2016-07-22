#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <conio.h>

using namespace std;
void print(int num);
bool isWin(int arr[][5] , int num);
void shuffle(int arr[][5]);
void up(int arr[][5] , int num , int& x , int& y);
void down(int arr[][5] , int num , int& x , int& y);
void left(int arr[][5] , int num , int& x , int& y);
void right(int arr[][5] , int num , int& x , int& y);


int num = 0 , highest = 999 , x = 0 , y = 0;
int puzzleSize[5][5] = {{0}};

ofstream output;
ifstream input;
int main()
{
    srand(time(0));
    int startTime = time(0);
    char level , action;
    cout << "Puzzle powered by Ph0en1x" << endl;
    cout << "Please select the level(e, n, h stands for easy, normal, hard ): " ;
    level = getch();
    while(level != 'e' && level != 'n' && level != 'h')
    {
        cout << "Error! Please input again." << endl;
        cout << "Please select the level(e, n, h stands for easy, normal, hard ): " ;
        level = getch();
    }

    switch(level)
    {
        case 'e': num = 3;
        input.open("easyHIGHEST.txt");
        input >> highest;
        input.close();
        output.open("easyHIGHEST.txt");
        break;
        case 'n': num = 4;
        input.open("normalHIGHEST.txt");
        input >> highest;
        input.close();
        output.open("normalHIGHEST.txt");
        break;
        case 'h': num = 5;
        input.open("hardHIGHEST.txt");
        input >> highest;
        input.close();
        output.open("hardHIGHEST.txt");
    }

    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            puzzleSize[i][j] = i * num + j + 1;
        }
    }
    x = num - 1;
    y = num - 1;
    shuffle(puzzleSize);

    do
    {
        print(num);
        action = getch();
        if(action == 'w')
        {
            up(puzzleSize , num , x , y);
        }
        else if(action == 's')
        {
            down(puzzleSize , num , x , y);
        }
        else if(action == 'a')
        {
            left(puzzleSize , num , x , y);
        }
        else if(action == 'd')
        {
            right(puzzleSize , num , x , y);
        }
        else if(action == 'e')
        {
            break;
        }
        else
        {
            cout << "Make sure your input is right!" << endl;
            cin >> action;
        }
    }
    while(!isWin(puzzleSize , num));
    print(num);
    int overTime = time(0);
    cout << endl << "Win" << endl << "Total Time is " << overTime - startTime << " s" << endl;
    output << overTime - startTime;
    output.close();

    system("pause");
    return 0;
}

void print(int num)
{
    system("CLS");
    cout << "Puzzle powered by Ph0en1x" << endl << endl;
    cout << " HIGHEST: " << highest << " s" << endl;
    for(int j = 0 ; j < num ; ++j)
    {
        cout << " ______";
    }
    for(int i = 0 ; i < num ; ++i)
    {
        cout << endl;
        for(int j = 0 ; j < num ; ++j)
        {
            cout << "|      ";
        }
        cout << '|' << endl;
        for(int j = 0 ; j < num ; ++j)
        {
            cout << setw(3) << left << '|';
            if(puzzleSize[i][j] >= num * num || puzzleSize[i][j] == 0)
            {
                cout << setw(4) << ' ';
            }
            else
            cout << setw(4) << puzzleSize[i][j];
        }
        cout << '|' << endl;
        for(int j = 0 ; j < num ; ++j)
        {
            cout << "|______";
        }
        cout << '|';
    }
    cout << endl << endl <<"Input your next step(w = up, s = down, a = left, d = right, e = exit):";
}

bool isWin(int arr[][5] , int num)
{
     for(int i = 0 ; i < num ; ++i)
     {
         for(int j = 0 ; j < num ; ++j)
         {
             if(i == num - 1 && j == num - 1)
                return true;
             else if(arr[i][j] != (i * num + j + 1))
                return false;
         }
     }
}

void shuffle(int arr[][5]) //xi Pai
{
    for(int i = 0 ; i < 500 ; i++)
    {
        int a = rand() % 4;
        switch(a)
        {
            case 0 : up(puzzleSize , num , x , y);
            break;
            case 1 : down(puzzleSize , num , x , y);
            break;
            case 2 : left(puzzleSize , num , x , y);
            break;
            case 3 : right(puzzleSize , num , x , y);
        }
    }
}

void up(int arr[][5] , int num , int& x , int& y)
{
    if(y < num - 1)
    {
        swap(arr[y][x] , arr[y + 1][x]);
        y++;
    }
}

void down(int arr[][5] , int num , int& x , int& y)
{
    if(y > 0)
    {
        swap(arr[y][x] , arr[y - 1][x]);
        y--;
    }
}

void left(int arr[][5] , int num , int& x , int& y)
{
    if(x < num - 1)
    {
        swap(arr[y][x] , arr[y][x + 1]);
        x++;
    }
}

void right(int arr[][5] , int num , int& x , int& y)
{
    if(x > 0)
    {
        swap(arr[y][x] , arr[y][x - 1]);
        x--;
    }
}

