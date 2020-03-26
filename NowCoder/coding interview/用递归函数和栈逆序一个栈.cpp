#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &arr, int pos, int num) {
    if(pos == num-1) {
        cout << arr[pos];
        return;
    }
    print(arr, pos+1, num);
    cout << " " << arr[pos];
}

int main() {
    int num;
    while(cin >> num) {
        vector<int> arr(num, 0);
        for(int i = 0; i < num; ++i) {
            cin >> arr[i];
        }
        print(arr, 0, num);
        cout << endl;
    }
    return 0;
}