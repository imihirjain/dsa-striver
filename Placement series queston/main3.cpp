#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int mini=i;
        for(int j=1;j<=n-1;j++)
        {
            if(arr[j]<arr[mini]) mini=j;
        }
        swap()
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    bubbleSort(arr, n);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}
