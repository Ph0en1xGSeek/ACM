#include <iostream>
#include <string>

using namespace std;

int main()
{

    string isCorrect;
    int num;
    cin >> num;


    for(int j = 0 ; j < num ; j++)
    {
        cin >> isCorrect;
        int score = 0 , total = 0;
        for(int i = 0 ; i < isCorrect.length() ; i++)
        {
            char choice = isCorrect[i];
            if(choice == 'O')
            {
                score++;
                total += score;
            }
            else if(choice == 'X')
                score = 0;
        }
        cout << total << endl;

    }

   return 0;
}
