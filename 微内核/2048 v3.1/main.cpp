#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <conio.h>

struct Pane
{
    int num;
    bool isPlus;
};
using namespace std;
void initialPane();//begin or restart
void printPane();
bool isWin(Pane pane[][4]);
bool isGameOver(Pane pane[][4]);
void slideLeft();
void slideRight();
void slideUp();
void slideDown();
void newNum();
void forUndo();

int score = 0;
int highest = 0;
char choice , qOrN;
Pane pane[4][4];
Pane temp[4][4];
int tempScore = 0 ;

int main()
{
    fstream inout;
    inout.open("HIGHEST.txt" , ios::in);
    inout >> highest;
    inout.close();

    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            temp[i][j].num = 0;
            temp[i][j].isPlus = false;
        }
    }

    srand(time(0));
    initialPane();
    do
    {
        printPane();
        choice = getch();
        if(choice == 'w')
        {
            forUndo();
            slideUp();
        }
        else if(choice =='a')
        {
            forUndo();
            slideLeft();
        }
        else if(choice =='s')
        {
            forUndo();
            slideDown();
        }
        else if(choice =='d')
        {
            forUndo();
            slideRight();
        }
        else if(choice =='q')
        {
            cout << "Are you sure to quit (y or n)?";
            cin >> qOrN;
            if(qOrN == 'y')
            {
                if(score > highest)
                {
                    inout.open("HIGHEST.txt" , ios::out);
                    inout << score;
                    inout.close();
                }
                system("pause");
                return 0;
            }
        }
        else if(choice =='r')
        {
            initialPane();
            score = 0;
        }
        else if(choice == 'u')
        {
            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    pane[i][j] = temp[i][j];
                }
            }
            score = tempScore;
        }
        else
        {
            cout << "Please do the right input!" << endl;
            system("pause");
            continue;
        }

        for(int i = 0 ; i < 4 ; i++)
        {
            for(int j = 0 ; j < 4 ; j++)
                pane[i][j].isPlus = false;
        }
        if(choice != 'r' && choice != 'u' && choice != 'q')
            newNum();

    }
    while(!isWin(pane) && !isGameOver(pane));
    printPane();
    cout << "GAME OVER" << endl;
    if(score > highest)
    {
        inout.open("HIGHEST.txt" , ios::out);
        inout << score;
        inout.close();
    }

    system("pause");
    return 0;
}

void initialPane()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            pane[i][j].num = 0;
            pane[i][j].isPlus = false;
        }
    }
    int x1 , x2 , y1 , y2;//the position of the first two numbers

    x1 = rand() % 4;
    x2 = (x1 + rand() % 3 + 1) % 4;
    y1 = rand() % 4;
    y2 = (y1 + rand() % 3 + 1) % 4;

    int percent1 , percent2;//initialize the first two numbers
    percent1 = rand() % 5;
    percent2 = rand() % 5;
    if(percent1 == 0)
        pane[x1][y1].num = 4;
    else
        pane[x1][y1].num = 2;

    if(percent2 == 0)
        pane[x2][y2].num = 4;
    else
        pane[x2][y2].num = 2;
}

void printPane()
{
    system("CLS");
    cout << "2048 C++ version powered by Phoenix" << endl << endl;
    cout << " SCORE: " << setw(7) << left << score << "HIGHEST: " << setw(7) << left << max(score , highest) <<endl;
    cout << " ______ ______ ______ ______ " << endl ;
    for(int i = 0 ; i < 4 ; i++)
    {
        cout  << "|      |      |      |      |" << endl;
        for(int j = 0 ; j < 4 ; j++)
        {
            if(pane[i][j].num > 1000)
                cout << "| " <<  pane[i][j].num << " ";
            else if(pane[i][j].num > 100)
                cout << "| " <<  pane[i][j].num << "  ";
            else if(pane[i][j].num > 10)
                cout << "|  " <<  pane[i][j].num << "  ";
            else if(pane[i][j].num != 0)
                cout << "|  " << pane[i][j].num << "   ";
            else
                cout << setw(7) << left << '|' ;
        }
        cout << '|';
        cout << endl << "|______|______|______|______|" << endl ;
    }
    cout << endl << "input your choice "<< endl
    << "(w=up,s=down,a=left,d=right,r=reStart,u=undo,q=quit)" << endl
    << ": ";
}


bool isWin(Pane pane[][4])
{
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if(pane[i][j].num == 2048)
                return true;
        }
    }
    return false;
}

bool isGameOver(Pane pane[][4])
{
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if(pane[i][j].num == 0)
                return false;
        }
    }
    return true;
}

void slideLeft()
{
    int n[4] = {0};
    for(int i = 0 ; i < 4 ; i++)
    {
        int index = 1;
        for(int j = 0 ; j < 4 ; j++)
        {
            if(pane[i][j].num == 0);
            else
            {
                int a ;
                for(a = j - 1 ; a >= 0 && pane[i][a].num == 0 ; a--);
                if(a < 0)
                    n[0] = pane[i][j].num;
                else if(pane[i][a].num == pane[i][j].num && pane[i][a].isPlus != true)
                {
                    n[index - 1] = 2 * pane[i][j].num;
                    score += n[index - 1];
                    pane[i][j].isPlus = true;
                }
                else if(pane[i][a].num != pane[i][j].num || pane[i][a].isPlus == true)
                {
                    n[index] = pane[i][j].num;
                    index++;
                }
            }
        }
        for(int u = 0 ; u < 4 ; u++)
        {
            pane[i][u].num = n[u];
            n[u] = 0;
        }
    }
}

void slideRight()
{
    int n[4] = {0};
    for(int i = 0 ; i < 4 ; i++)
    {
        int index = 2;
        for(int j = 3 ; j >= 0 ; j--)
        {
            if(pane[i][j].num == 0);
            else
            {
                int a;
                for(a = j + 1 ; a < 4 && pane[i][a].num == 0 ; a++);
                if(a > 3)
                    n[3] = pane[i][j].num;
                else if(pane[i][a].num == pane[i][j].num && pane[i][a].isPlus != true)
                {
                    n[index + 1] = 2 * pane[i][j].num;
                    score += n[index + 1];
                    pane[i][j].isPlus = true;
                }
                else if(pane[i][a].num != pane[i][j].num || pane[i][a].isPlus == true)
                {
                    n[index] = pane[i][j].num;
                    index--;
                }
            }
        }
        for(int u = 0 ; u < 4 ; u++)
        {
            pane[i][u].num = n[u];
            n[u] = 0;
        }
    }
}

void newNum()
{
    int n = rand() % 16 + 1;
    int x = 0;
    while(1)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(pane[i][j].num == 0)
                {
                    x++;
                    if(x == n)
                    {
                        pane[i][j].num = 2;
                        return;
                    }
                }
            }
        }
    }
}

void slideUp()
{
    int n[4] = {0};
    for(int j = 0 ; j < 4 ; j++)
    {
        int index = 1;
        for(int i = 0 ; i < 4 ; i++)
        {
            if(pane[i][j].num == 0);
            else
            {
                int a ;
                for(a = i - 1 ; a >= 0 && pane[a][j].num == 0 ; a--);
                if(a < 0)
                    n[0] = pane[i][j].num;
                else if(pane[a][j].num == pane[i][j].num && pane[a][j].isPlus != true)
                {
                    n[index - 1] = 2 * pane[i][j].num;
                    score += n[index - 1];
                    pane[i][j].isPlus = true;
                }
                else if(pane[a][j].num != pane[i][j].num || pane[a][j].isPlus == true)
                {
                    n[index] = pane[i][j].num;
                    index++;
                }
            }
        }
        for(int u = 0 ; u < 4 ; u++)
        {
            pane[u][j].num = n[u];
            n[u] = 0;
        }
    }
}

void slideDown()
{
    int n[4] = {0};
    for(int j = 0 ; j < 4 ; j++)
    {
        int index = 2;
        for(int i = 3 ; i >= 0 ; i--)
        {
            if(pane[i][j].num == 0);
            else
            {
                int a;
                for(a = i + 1 ; a < 4 && pane[a][j].num == 0 ; a++);
                if(a > 3)
                    n[3] = pane[i][j].num;
                else if(pane[a][j].num == pane[i][j].num && pane[a][j].isPlus != true)
                {
                    n[index + 1] = 2 * pane[i][j].num;
                    score += n[index + 1];
                    pane[i][j].isPlus = true;
                }
                else if(pane[a][j].num != pane[i][j].num || pane[a][j].isPlus == true)
                {
                    n[index] = pane[i][j].num;
                    index--;
                }
            }
        }
        for(int u = 0 ; u < 4 ; u++)
        {
            pane[u][j].num = n[u];
            n[u] = 0;
        }
    }
}

void forUndo()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            temp[i][j] = pane[i][j];
        }
    }
    tempScore = score;
}


