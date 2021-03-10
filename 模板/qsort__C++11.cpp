#include <iostream>
#include <algorithm>

using namespace std;

int cmp(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}

int main()
{
    cout << "Hello world!" << endl;
    int num{78};
    cout << num << endl;
    int arr[] {200, 100, 5, 8, 2, 1, 5};
    cout << *(arr + 6) <<endl;
    sort(arr + 1, arr + 7);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    char arr2[] {'a', 'r', '2', 'M', 'q', 'T', '?' };
    qsort(arr2, 7, sizeof(arr2[0]), cmp);
    for(auto ch : arr2)
        cout << ch << " ";
    cout << endl;
    return 0;
}
