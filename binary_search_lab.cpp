#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int search1(int arr[],int x,int n)
{
    int l,r;
    l=0,r=n-1;
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else
        {
            if(arr[mid]<x)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
    }
    return -1;
}

int insert(int arr[],int n,int pos,int k) //pos is 1 indexed positon
{
    for(int i=n-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=k;
    return n+1;
}

int remove(int arr[],int n,int pos) //pos is 1 indexed position
{

    for(int i=pos-1;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    return n-1;
}

int search_op(int arr[],int n,int x)
{
    int pos=search1(arr,x,n);
    if(pos==-1)
    {
        n=insert(arr,n,1,x);
    }
    else
    {
        n=remove(arr,n,pos+1);
    }
    return n;
}

int main()
{
    int arr[100]={1,3,4,5,6,7,9,10};
    int n=8;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    n=search_op(arr,n,11);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    n=search_op(arr,n,10);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
//    int find=search1(arr,5,8);
//    cout<<"find="<<find;
//    n=insert(arr,8,4,11);
//    for(int i=0;i<n;i++)
//    {
//        cout<<arr[i]<<' ';
//    }
//    cout<<endl;
//    n=remove (arr,8,4);
//    for(int i=0;i<n;i++)
//    {
//        cout<<arr[i]<<' ';
//    }
//    cout<<endl;
    return 0;
}
