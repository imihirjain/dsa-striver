#include<bits/stdc++.h>
using namespace std;
/*
    Subset
    Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

vector<vector<int>> subsets(vector<int> &nums)
{
    int n=nums.size();
    int subset=n-1;
    vector<vector<int>> ans;
    for(int i=0;i<subset;i++)
    {
        vector<int>list;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j)) list.push_back(nums[j]);
        }
        ans.push_back(list);
    }
    return ans;
}

/*
    Minimum bit flips to convert that number
    Example 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
*/

int minFlip(int start, int goal)
{
    long long ans=start^goal;
    int cnt=0;
    for(int i=0;i<32;i++)
    {
        if(ans&(1<<i)) cnt++;
    }
    return cnt;
}

/*
    Single number
    Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
*/

int singleNumber(vector<int> &nums)
{
    int n=nums.size();
    int xor1=0;
    for(int i=0;i<n;i++)
    {
        xor1=xor1^nums[i];
    }
    return xor1;
}
int main()
{
    return 0;
}

