#include <iostream>
#include <string>

using namespace std;
string cA(string dashes , int order);

int main()
{
    cout << "Hello world!" << endl;
    int order;
    cin >> order;
    cout << cA("-" , order) << endl;
    return 0;
}

string cA(string dashes , int order)
{
    string result = dashes;
    if(order == 0)
        return dashes;
    else
    {
        for(unsigned i = 0 ; i < dashes.length() ; i++)
            result = result + ' ';
        result = result + dashes;
    }
    return cA(result , order - 1);

}
