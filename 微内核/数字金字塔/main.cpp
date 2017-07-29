#include <iostream>
#include <iomanip>

using namespace std;
void printFromN(int row);
void printFrom2(int row);

int row;
int total;

int main()
{
   cout << "Input a integer: ";
   cin >> total;
   for (row = 1 ; row <= total ; row++)
   {

       int p = 3 * total - 3 * row;
       cout << setw(p);
       if (row != total)
        cout << " ";
       printFromN(row);
       printFrom2(row);
       cout << endl;
   }
}


void printFromN(int row)
{
    for (int i = row ; i > 0 ; i--)
    {
      cout << setw(3) << i;
    }
}

void printFrom2(int row)
{
    for (int i =2 ; i <= row ; i++)
    {
        cout << setw(3) << i ;
    }
}
