/*

You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
*/

#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>> &arrs)
{
    int MIN = arrs[0].front();
    int MAX = arrs[0].back();
    int result=0;
    for(int i=1;i<arrs.size();i++)
    {
        int currMin = arrs[i].front();
        int currMax = arrs[i].back();

        result = max({result, abs(currMin-MAX), abs(currMax-MIN)});

        currMin = min(MIN, currMin);
        currMax = max(MAX, currMax);
    }

    return result;
}

int main()
{
    return 0;
}
