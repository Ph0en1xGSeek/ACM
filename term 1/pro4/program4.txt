// File Name:    prog4.cpp
// Author:       Pan Guosheng
// Student Number: 3014218157
// Assignment:   #2
// Description:  This program will let you input pound and ounce and show you what you input, then convert to
//               kilogram and gram and display the result.

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

const double POUND_TO_GRAM = 453.6;
const double OUNCE_TO_GRAM = 28.3495;



//Tell the users what is wanted and get in what users input
int promptAndGetInt(string promtMessage)
{
    cout << promtMessage << " : " ;
    char ch;
    do
    {
       cin >> ch;
    }

    while (isdigit(ch) == false);
    cin.putback(ch);

    int getIn;

    cin >> getIn;
    cout << endl;
    return getIn;
}





//Convert the pounds and ounces to grams
int onvertToGram(int pounds , int ounces)
{

    double gram1 = pounds * POUND_TO_GRAM;
    double gram2 = ounces * OUNCE_TO_GRAM;
    int grams = static_cast<int>(gram1 + gram2 + 0.5);
    return grams;
}




//Convert and display kilograms and gram
void outputResults(int pounds , int ounces , int grams)
{

    int kiloGram = grams / 1000;
    grams = grams % 1000;

    cout << "Result:\n\n" << pounds << " Poound(s) and " << ounces
        << " Ounce(s) converts to \n\n" << kiloGram << " kg and " << grams << " g \n";

}




int main()
{
    cout << "This progam will convert pounds and ounces to kilograms and grams\n"
        << "First I will prompt you for number of pounds and then the number of ounces\n\n\n";


    int pounds , ounces , grams;
    pounds = promptAndGetInt("Pounds");
    ounces = promptAndGetInt("Ounces");
    grams = onvertToGram(pounds , ounces);
    outputResults(pounds , ounces , grams);



    return 0;
}
