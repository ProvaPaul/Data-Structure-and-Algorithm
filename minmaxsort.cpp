#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Swap(int &a,int &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}

void findminmax(int arr[], int st, int en, int& min_i, int& max_i)
{
    min_i = st;
    max_i = st;
    int minn = arr[st];
    int maxx = arr[st];
    for (int ptr = st + 1; ptr < en; ptr++)
    {
        if (arr[ptr] < minn)
        {
            min_i = ptr;
            minn = arr[ptr];
        }
        else if (arr[ptr] > maxx)
        {
            max_i = ptr;
            maxx = arr[ptr];
        }
    }
}

void minmaxsort(int arr[], int n)
{
    int min_i, max_i;
    for(int i = 0,j=n-1; i < j; i++,j--)
    {
        findminmax(arr, i, n - i, min_i, max_i);
        Swap(arr[i], arr[min_i]);
        if(max_i == i)
        {
            max_i = min_i;
        }
        Swap(arr[j], arr[max_i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    minmaxsort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}