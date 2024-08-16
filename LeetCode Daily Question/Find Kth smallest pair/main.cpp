/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
*/

#include<bits/stdc++.h>
using namespace std;
bool ok(int mid, vector<int>&num, int k)
{
    int n=num.size();
    int j=1;
    int total=0;
    for(int i=0;i<n;i++)
    {
        while(j<n && num[j]-num[i]<=mid) j++;
        j--;
        int x=(j-i);
        total +=x;
    }
    return (total>=k);

}
int smallestDistance(vector<int>&nums, int k)
{
    int n=nums.size();
    sort(nums.begin(), nums.end());
    int diff = nums[n-1]-nums[0];
    int l=0;
    int r=diff;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(ok(mid,nums,k)) r=mid;
        else l=mid+1;
    }
    return l;
}

int main()
{
    return 0;
}

