#include<bits/stdc++.h>
using namespace std;

/*
    Find missing number
    a[] = {1,2,4,5};
*/

int findMissingNumber(vector<int> &a, int n)
{
    // Brute Force
    for(int i=1;i<=n;i++)
    {
        int flag=0;
        for(int j=0;j<n-1;j++)
        {
            if(a[j]==i)
            {
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }

    // Better using hashing
    int hash[n+1]={0};
    for(int i=0;i<n-1;i++)
    {
        hash[a[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(hash[a[i]]==0)
        return i;
    }

    // optimal solution using sum and xor
    // Sum
    int sum = (n*(n+1))/2;
    int s2=0;
    for(int i=0;i<n-1;i++)
    {
        s2 +=a[i];
    }
    return sum-s2;

    // xor
    int xor1=0;
    int xor2=0;
    for(int i=0;i<n-1;i++)
    {
        xor2=xor2^a[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;

    return xor1^xor2;
}


/*
    Max consecutive ones;
    a[] = {0,1,1,1,1,1,0,0,1};
*/

int maxConsecutiveOnes(vector<int> &arr, int n)
{
    int maxi=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            cnt++;
            maxi=max(maxi, cnt);
        }
        else
        cnt=0;
    }
    return maxi;
}
/*
    Find the number that appear once
    a[] = {4,1,2,1,2};

*/
int findSingle(vector<int> &arr, int n)
{
    // Brute Force
    for(int i=0;i<n;i++)
    {
        int num = arr[0];
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==num)
            {
                cnt++;
            }
        }
        if(cnt==1) return num;
    }

    // Optimal using xor
    int xor1 = 0;
    for(int i=0;i<n;i++)
    {
        xor1=xor1^arr[i];
    }
    return xor1;
}

/*
    Longest Sub array with given sum K (positive)\
    a[] = {1,4,20,3,10,5}, K = 33
*/

int longestSubarray(vector<int> &arr, long long k)
{
    // using two pointer
    int left =0;
    int right = 0;
    int n=arr.size();
    int maxLen=0;
    long long sum = arr[0];
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum -=arr[left];
            left++;
        }

        if(sum==k) 
        maxLen = max(maxLen, right-left+1);

        right++;
        if(right<n)
        sum += arr[right];
    }

    return maxLen;
}


/*
    Longest Sub array with given sum K (positive and negative)
    a[] = {15,-2,2,-8,1,7,10,23}, K = 5
*/

int longestSubArray(vector<int> &arr, long long k, int n)
{
    map<long long, int> preSumMap;
    long long sum =0;
    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        sum +=arr[i];
        if(sum==k)
        {
            maxLen = max(maxLen, i+1);
        }

        long long rem = sum -k;
        if(preSumMap.find(rem)!= preSumMap.end())
        {
            int len = i-preSumMap[rem];
            maxLen= max(maxLen, len);
        }

        if(preSumMap.find(sum)==preSumMap.end())
        {
            preSumMap[sum]=i;
        }
    }

    return maxLen;

}
int main()
{


}
