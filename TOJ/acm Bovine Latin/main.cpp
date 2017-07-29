#include <iostream>
#include <string>

using namespace std;

int main()
{
    string letter;
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> letter;
        if(letter[0] == 'a' || letter[0] == 'e' || letter[0] == 'i' ||
           letter[0] == 'o' || letter[0] == 'u')
        {
            letter += "cow";
        }
        else
        {
            char ch = letter[0];
            for(int i = 0; i < letter.length() - 1; i++)
            {
                letter[i] = letter[i+1];
            }
            letter[letter.length() - 1] = ch;
            letter += "ow";
        }
        cout << letter << endl;
    }
    return 0;
}
