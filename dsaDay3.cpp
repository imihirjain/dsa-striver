#include<bits/stdc++.h>
using namespace std;

/*
    Left rotate the array by one place
    a[]={1,2,3,4,5}
*/
vector<int> leftRotate(vector<int> &arr, int n)
{
    int temp=arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }

    arr[n-1]=temp;

    return arr;
}

/*
    Left rotate array by D place
    arr[]={1,2,3,4,5,6,7};
*/
vector<int> rotate(vector<int> &arr, int n, int d)
{
    vector<int> temp;
    for(int i=0;i<d;i++)
    {
        temp.push_back(arr[i]);
    }

    for(int i=d;i<temp.size();i++)
    {
        arr[i-d]=arr[i];
    }

    for(int i=n-d;i<n;i++)
    {
        arr[i]=temp[i-(n-d)];
    }

    return arr;
}   


/*
    Move Zero to End
    a[]={1,0,2,3,2,0,0,4,5,1}
*/
void moveZero(vector<int> &arr, int n)
{
    int j=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }

    for(int i=j+1;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

/*
    Linear Search
    a[]={1,2,3,4}
*/

int linearSearch(int arr[], int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}

/*
    Union of Two sorted Array
    a[]={1,1,2,3,4,5}
    b[]={2,3,4,4,5};
*/

vector<int> unionArray(vector<int>&a, vector<int> &b)
{
    int n=a.size();
    int m=b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n && j<m)
    {
        if(a[i]<=b[j])
        {
            if(unionArr.size()==0||unionArr.back()!=a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }

        else
        {
            if(unionArr.size()==0 || unionArr.back()!=b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while(i<n)
    {
        if(unionArr.size()==0 || unionArr.back()!=a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    while(j<m)
    {
        if(unionArr.size()==0 || unionArr.back()!=b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}


/*
    intersection of two sorted array
    a[]={1,2,2,3,4,5}
    b[]={2,3,4,4,5};
*/

vector<int> intersectionArr(vector<int>&a, vector<int> &b)
{
    int n=a.size();
    int m=b.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m)
    {
        if(a[i]<b[j]) i++;
        else if(b[j]<a[i]) j++;
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    
}