#include<bits/stdc++.h>
using namespace std;

/*
    Length of the longest subarray with zero Sum
    Input Format
: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result
: 5
*/

int maxLen(vector<int> &arr, int n)
{
    unordered_map<int,int> mpp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum +=arr[i];
        if(sum==0)
        maxi=i+1;
        else{
            if(mpp.find(sum)!=mpp.end())
            {
                maxi = max(maxi,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
    }

    return maxi;
}

/*
    Count the number of subarrays with given xor K
    Input Format:
 A = [4, 2, 2, 6, 4] , k = 6
Result:
 4
Explanation:
 The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
*/

int subarraySumK(vector<int> &arr, int k)
{
    map<int,int>mpp;
    int xr=0;
    mpp[xr]++;
    int cnt=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        xr ^=arr[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}


/*
    Maximum Product Subarray in an Array
    Input:

 Nums = [1,2,3,4,5,0]
Output:

 120
Explanation:

 In the given array, we can see 1×2×3×4×5 gives maximum product value.
*/

int subarrayWithMaxProduct(vector<int> &arr)
{
    long long pre=1;
    long long suf=1;
    int maxi = INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(pre==0) pre=1;
        if(suf==0) suf=1;
        pre *=arr[i];
        suf *=arr[n-i-1];
        maxi=max(maxi, max(pre,suf));
    }
    return maxi;
}

int main()
{

}