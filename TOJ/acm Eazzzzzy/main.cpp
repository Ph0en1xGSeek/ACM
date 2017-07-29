#include <iostream>

using namespace std;
void triangle(int a);
void parallelogram(int a , int h);
void rectangle(int a , int h);
void space(int a);

int main()
{
    int what;
    int a;
    int h;
    while(cin >> what && what > 0)
    {
        switch(what)
        {
            case 1:
                cin >> a ;
                triangle(a);
            break;

            case 2:
                cin >> a >> h;
                parallelogram(a , h);
            break;

            case 3:
                cin >> a >> h;
                rectangle(a , h);
            break;
            default:;
        }
        cout << endl;
    }


    return 0;
}


void triangle(int a)
{
    int b;
    for(int q = 1 ; q <= a ; q++)
    {
        space(a - q);
        b = q;


        for(int i = 1 ; i <= 2 * b - 1 ; i++)
        cout << '*';
        cout << endl;
    }

}

void parallelogram(int a , int h)
{
    for(int i = 1 ; i <= h ; i++)
    {
        space(h - i);
        for(int c = 1 ; c <= a ; c++)
            cout  << '*';
        cout << endl;
    }
}

void rectangle(int a , int h)
{
    for(int i = 1 ; i <= h ; i++)
    {
        for(int c = 1 ; c <= a ; c++)
            cout << '*';
        cout << endl;
    }
}

void space(int a)//print a spaces
{
    for(int i = 0 ; i < a ; i++)
        cout << ' ' ;
}
