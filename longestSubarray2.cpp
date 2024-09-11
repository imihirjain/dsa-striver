#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubarray(vector<int>arr, int k)
{
    long long sum=arr[0];
    int maxLen=0;
    int left=0;
    int right=0;
    int n=arr.size();
    int start=-1;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k)
        {
            if(right-left+1>maxLen)
            {
                maxLen=right-left+1;
                start=left;
            }
        }
        right++;
        if(right<n) sum+=arr[right];
    }
    vector<int>result;
    if(start!=-1) result= vector<int>(arr.begin()+start, arr.begin()+start+maxLen);

    return (maxLen, result);
}

int main()
{
    vector<int> arr = {1,2,3,4,5,7};
    long long k=12;
    vector<int> result=longestSubarray(arr,k);
    for(auto x:result)
    cout<<x<<" ";
    return 0;
}
