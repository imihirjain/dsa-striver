#include <bits/stdc++.h>
using namespace std;

/*
    Two Sum : Check if a pair with given sum exists in Array
    Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
*/

vector<int> twoSum(vector<int> &arr, int n, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];
        if (mpp.count(complement))
        {
            return {mpp[complement], i + 1};
        }
        mpp[arr[i]] = i;
    }

    return {};
}

/*
    Sort an array of 0s, 1s and 2s
    Input:
    nums = [2,0,2,1,1,0]
    Output
    [0,0,1,1,2,2]
*/

void sort012(vector<int> &arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

/*
    Find the Majority Element that occurs more than N/2 times
    Input Format:
    N = 7, nums[] = {2,2,1,1,1,2,2}

    Result
    2
*/

int majorityElement(vector<int> &arr, int n)
{
    int cnt = 0;
    int el;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
            cnt++;
        else
            cnt--;
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
            cnt1++;
    }
    if (cnt1 > n / 2)
        return el;

    return -1;
}

/*
    Kadane's Algorithm : Maximum Subarray Sum in an Array
    Input:
    arr = [-2,1,-3,4,-1,2,1,-5,4]

    Output:
    6

    Explanation:
    [4,-1,2,1] has the largest sum = 6.
*/

int maxSubArray(vector<int> &arr, int n)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

/*
    Stock Buy And Sell
    Input:
 prices = [7,1,5,3,6,4]
Output:
 5
Explanation:
 Buy on day 2 (price = 1) and
sell on day 5 (price = 6), profit = 6-1 = 5.

*/

int maxProfit(vector<int> &arr, int n)
{
    int mini = arr[0];
    int profit=0;
    for(int i=0;i<n;i++)
    {
        int cost = arr[i]-mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }

    return profit;

    // Alternate solution of Leet code
    // vector<int> ans;
    // for(int i=1;i<n;i++)
    // {
    //     if(arr[i]>arr[i-1])
    //     {
    //         ans.push_back({i+1, i});
    //     }
    // }
    // return ans;

    // Another alternate solution of GFG
    // int profit=0;
    // for(int i=1;i<n;i++)
    // {
    //     if(arr[i]>arr[i-1])
    //     {
    //         profit += arr[i]-arr[i-1];
    //     }
    // }

    // return profit;

}


int main()
{
}