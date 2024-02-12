#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int insertion(int arr[], int n, int data, int pos)
{
    for (int i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = data;
    return n + 1;
}

int delation(int arr[], int n, int pos)
{
    for (int i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int search(int arr[], int n, int data)
{
    int b = 0, e = n - 1;
    while (b <= e)
    {
        int mid = (b + e) / 2;

        if (arr[mid] == data)
        {
            return mid;
        }
        else
        {
            if (arr[mid] < data)
            {
                e = mid - 1;
            }
            else
            {
                b = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[100] = {7, 4, 11, 6, 7, 9};
    int n = 6;
    int i = search(arr, 6, 5);
    if (i == -1)
    {
        n = insertion(arr, n, 9, 2);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }
    }
    else
    {
        n = delation(arr, 6, i);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }
    }
    return 0;
}