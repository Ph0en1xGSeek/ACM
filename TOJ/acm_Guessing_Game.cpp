#include <iostream>
#include <string>

using namespace std;

int main()
{
    int guess;
    string judge;
    int num[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    string conclusion;
    cout << "Guessing Game" << endl;

    //do{

        int high = 10 , low = 1;
        cin >> guess;
        cin.get();

        getline(cin , judge);

        while (judge != "right on")
        {

            if (judge == "too high")
                high = guess - 1;
            else //(judge == "too low")
                low = guess + 1;

            cin >> guess;
            cin.get();
            getline(cin , judge);
        }

        if  (high < low)
            conclusion = "Stan is dishonestaaa";

       for(int i = low - 1 ; i <=  high - 1 ; i++)
       {
           if (num[i] = guess)
            {
                conclusion = "Stan may be honest" ;
                break;
            }

            conclusion = "\nStan is dishonest";
       }
        cout << conclusion << endl;



    //while (guess !=0);





    return 0;
}
