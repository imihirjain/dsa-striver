#include<bits/stdc++.h>
using namespace std;

/* largest element in array
    arr[]={3,2,1,5,2};
*/
int getLargest(int a[], int n)
{
    int largest = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>largest)
        {
            largest=a[i];
        }
    }
    return largest;
}

/*
second smallest and second largest
arr[]={3,6,7,9,1};
*/

int secondLargest(int arr[], int n)
{
    int largest=arr[0];
    int sLargest=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            sLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>sLargest)
        {
            sLargest=arr[i];
        }
    }

    return sLargest;
}

int secondSmallest(int arr[], int n)
{
    int smallest = arr[0];
    int sSmallest = INT_MAX;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<smallest)
        {
            sSmallest = smallest;
            smallest = arr[i];
        }

        else if(arr[i]!=smallest && arr[i]<sSmallest)
        {
            sSmallest = arr[i];
        }
    }

    return sSmallest;
}

/*
    check if array is sorted
    arr[]={1,2,2,3,3,4};
*/

int isSorted(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1])
        {

        }
        else
        return false;
    }
    return true;
}


/*
    Remove Duplicates from array
    arr[]={1,1,2,2,2,3,3};
*/

int removeDupli(int arr[], int n)
{
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(arr[j]!=arr[i])
        {
            arr[i+1]=arr[j];
            i++;
        }
    }

    return i+1;
}


int main()
{
    int arr[]={1,2,2,3,3};
    // int arr[]={3,6,7,9,1};
    int n= sizeof(arr)/sizeof(int);
    // int result = getLargest(arr,n);
    // int result = secondLargest(arr,n);
    // int result = secondSmallest(arr,n);
    // int result = isSorted(arr,n);
    int result = removeDupli(arr,n);
    cout<<result;

}
