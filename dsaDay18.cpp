#include<bits/stdc++.h>
using namespace std;

/*
    pascals triangle 
    n=4
    output:
    1
    1 1 
    1 2 1
    1 3 3 1
*/

vector<int> generateRow(int row)
{
    long long ans=1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1;col<row;col++)
    {
        ans=ans*(row-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int N)
{
    vector<vector<int>> ans;
    for(int i=0;i<N;i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

/*
    Majority Elements(&gt;N/3 times) | Find the elements that appears more than N/3 times in the array
    Input Format
: N = 5, array[] = {1,2,2,3,2}
Result
: 2
*/
vector<int> majorityElement(vector<int> &v)
{
    int n = v.size();
    int cnt1=0, cnt2=0;
    int el1, el2;
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && el2!=v[i])
        {
            cnt1=1;
            el1=v[i];
        }
        else if(cnt2==0 && el1!=v[i])
        {
            cnt2=1;
            el2=v[i];
        }
        else if(el1==v[i]) cnt1++;
        else if(el2==v[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ls;
    cnt1=0, cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(el1==v[i]) cnt1++;
        if(el2==v[i]) cnt2++;
    }
    int mini = (int)(n/3)+1;
    if(cnt1>=mini) ls.push_back(el1);
    if(cnt2>=mini) ls.push_back(el2);
    sort(ls.begin(), ls.end());
    return ls;
}

/*
    3 Sum : Find triplets that add up to a zero
    Input:
 nums = [-1,0,1,2,-1,-4]

Output:
 [[-1,-1,2],[-1,0,1]]

*/

vector<vector<int>> threeSum(vector<int> &arr, int n)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k)
        {
            int sum = arr[i]+arr[j]+arr[k];
            if(sum<0) j++;
            else if(sum>0) k--;
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while( j<k && arr[j]==arr[j-1]) j++;
                while( j<k && arr[k]==arr[k+1]) k--;
            }
            
        }
    }
    return ans;
}

/*
    4 Sum | Find Quads that add up to a target value
    Input Format:
 arr[] = [1,0,-1,0,-2,2], target = 0
Result:
 [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Explanation:
 We have to find unique quadruplets from the array such that the sum of those elements is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.
*/

vector<vector<int>> quadruplets(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1])continue;
            int k = j+1;
            int l=n-1;
            while(k<l)
            {
                long long sum = arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum==target){
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l]==arr[l+1])l--;
                }
                else if(sum>target)l--;
                else k++;
            }
        }
    }
    return ans;
}
int main()
{

}