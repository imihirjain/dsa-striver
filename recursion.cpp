#include<bits/stdc++.h>
using namespace std;

void printName(int i, int n)
{
    if(i>n) return;
    cout<<"Mihir Jain"<<endl;
    printName(i+1,n);
}

void print1toN(int i, int n)
{
    if(i>n) return;
    cout<<i<<endl;
    print1toN(i+1,n);
}

void printNto1(int n, int i)
{
    if(n<i) return; 
    cout<<n<<endl;
    printNto1(n-1,i);
}

void sumofN(int i, int sum)
{
    if(i<1)
    {
        cout<<sum;
        return;
    }
    sumofN(i-1,sum+i);
    
}

int factorial(int n)
{
    if(n==1)
    return 1;
    return n * factorial(n-1);
}

void printArray(int arr[], int n)
{
    cout<<"Printing the array:- "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void reverseArray(int  arr[], int start, int end)
{
    if(start<end)
    {
        swap(arr[start], arr[end]);
        reverseArray(arr,start+1, end-1);
    }

}

int fibo(int n)
{
    if(n<=1)
    return n;
    int last = fibo(n-1);
    int first = fibo(n-2);
    return last + first;
}

int main()
{
    int n = 5;
    cout<<fibo(n)<<" ";
    // printName(1,n);
    // print1toN(1,n);
    // printNto1(n,1);
    // sumofN(n,0);
    // int s = factorial(n);
    // cout<<s;

    // int arr[]={10,20,30,40};
    // int size = sizeof(arr)/sizeof(int);
    // reverseArray(arr,0,size-1);
    // printArray(arr,size);

}