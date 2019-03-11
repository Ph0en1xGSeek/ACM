#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

int arr[1000010];

struct endNode{
    int from;
    int to;
    endNode(int f, int t){
        from = f;
        to = t;
    }
};

int n, m;
stack<endNode> st;

///Quick Sort
void quickSort(int low, int high)
{
    if(low >= high)
        return;
    int tmp = arr[low];
    int l = low, h = high;
    while(l < h)
    {
        while(l < h && arr[h] > tmp)
            h--;
        arr[l] = arr[h];
        while(l < h && tmp > arr[l])
            l++;
        arr[h] = arr[l];
    }
    arr[l] = tmp;
    st.push(endNode(low, l-1));
    st.push(endNode(l+1, high));
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        while(!st.empty()){
            st.pop();
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        st.push(endNode(0, n-1));
        while(!st.empty()){
            endNode tmp = st.top();
            st.pop();
            quickSort(tmp.from, tmp.to);
        }
        printf("%d", arr[n-1]);
        for(int i = n-2; i >= n-m; i--)
            printf(" %d", arr[i]);
        printf("\n");
    }
    return 0;
}
