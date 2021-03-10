#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;
    string word;
    for(int i = 0; i < num; i++)
    {
        while(cin >> word)
        {
            for(int j = 0; j < word.length() / 2; j++)
            {
                char temp = word[j];
                word[j] = word[word.length() - j - 1];
                word[word.length() - j - 1] = temp;
            }
            cout << word;
            char a = cin.get();
            if(a != ' ')
            {
                cout << endl;
                break;
            }

            else
                cout << ' ';
        }

    }
    return 0;
}
