#include <iostream>
#include <cmath>


using namespace std;
int zhengShuMi(int diShu , int zhiShu);

int main()
{

    int num1 ;
    int num2 ;
    cin >> num1;
    cin >> num2;
    int carry = 0 , remain = 0;
    int n1[10] = {0};
    int n2[10] = {0};


    for(int i = 0 ; i < 10 ; i++)
    {
           n1[i] = (num1 % zhengShuMi(10 , i + 1)) / zhengShuMi(10 , i);
           n2[i] = (num2 % zhengShuMi(10 , i + 1)) / zhengShuMi(10 , i);


    }


    for(int j = 0 ; j < 10 ; j++)
    {
            if(n1[j] + n2[j] + remain >= 10)
            {
                carry++;
                remain = 1;
            }
            else
                remain = 0;
    }

    cout << carry << " carries" << endl;



    return 0;
}

int zhengShuMi(int diShu , int zhiShu)
{
    int solu = 1;
    for(int i = 0 ; i < zhiShu ; i++)
        solu = solu * diShu;
    return solu;
}
