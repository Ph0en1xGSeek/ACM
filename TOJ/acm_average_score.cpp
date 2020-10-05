#include <iostream>
#include <cmath>

using namespace std;
double average(int clss[] , int sizeOfArr);
double averageAfter(int clss[] , int sizeOfArr , int xiaoMing);


int main()
{
    cout << "Hello world!" << endl;
    int clss1 , clss2;
    cin >> clss1;
    cin >> clss2;
    int c1[50] = {0};
    int c2[50] = {0};
    double low , high;

    for(int i = 0 ; i < clss1 - 1 ; i++)
        cin >> c1[i];
    for(int j = 0 ; j < clss2 ; j++)
        cin >> c2[j];
    double average1 = average(c1  , clss1 - 1);//average if there is no xiaoming
    double average2 = average(c2  , clss2);

    if(average1 - static_cast<int>(average1) == 0)
        high = average1 - 1;
    else
        high = floor(average1);


    if(average2 - static_cast<int>(average2) == 0)
        low = average2 + 1;
    else
        low = ceil(average2);

    cout << low << " " << high;

    return 0;
}



double average(int clss[] , int sizeOfArr)
{
    int total = 0;
    double average;
    for(int i = 0 ; i < sizeOfArr ; i++)
        total += clss[i];
    average = total / (sizeOfArr + 0.0);
    return average;

}

double averageAfter(int clss[] , int sizeOfArr , int xiaoMing)
{
    int total = 0;
    double average;
    for(int i = 0 ; i < sizeOfArr ; i++)
        total += clss[i];
    total += xiaoMing;
    average = total / (sizeOfArr + 0.0);
    return average;

}

