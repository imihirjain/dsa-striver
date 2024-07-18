#include<bits/stdc++.h>
using namespace std;

/*
    Rearrange Array Elements by Sign
    Variety-1
    arr[] = {1,2,-4,-5}, N = 4
    Output:
    1 -4 2 -5

    Variety-2
    Input:
    arr[] = {1,2,-4,-5,3,4}, N = 6
    Output:
    1 -4 2 -5 3 4
*/

vector<int> rearrangeNumber(vector<int> &arr, int n)
{
    // VARIETY 1 SOLUTION
    // vector<int> ans;
    // int pos=0, neg=1;
    // for(int i=0;i<n;i++)
    // {
    //     if(arr[i]>0)
    //     {
    //         arr[pos]=arr[i];
    //         pos +=2;
    //     }
    //     else
    //     {
    //         arr[neg]=arr[i];
    //         neg +=2;
    //     }
    // }

    // return ans;
    
    // VARIETY 2 SOLUTION
    vector<int> pos, neg;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    if(pos.size()>neg.size())
    {
        for(int i=0;i<neg.size();i++)
        {
            arr[2*i]=pos[i];
            arr[2*i+1]= neg[i];
        }

        int index = neg.size()*2;
        for(int i = neg.size();i<pos.size();i++)
        {
            arr[index]=pos[i];
            index++;
        }
    }

    else
    {
        for(int i=0;i<pos.size();i++)
        {
            arr[2*i]=pos[i];
            arr[2*i+1]= neg[i];
        }

        int index = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++)
        {
            arr[index]=neg.size();
            index++;
        }
    }

    return arr;
}

/*
        Leaders in an Array
        Input:

 arr = [4, 7, 1, 0]
Output
:
 7 1 0
*/

vector<int> findLeaders(vector<int> arr, int n)
{
    vector<int> ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>=maxi)
        {
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

/*
    Longest Consecutive Sequence in an Array
    Example 1:
Input:
 [100, 200, 1, 3, 2, 4]

Output:
 4
*/

int findLongestSequence(vector<int> &arr, int n)
{
    if(n==0) 
    return n;
    unordered_set<int> st;
    int longest = 1;
    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }

    for(auto it: st)
    {
        if(st.find(it-1)==st.end())
        {
            int cnt=1;
            int x=it;
            while(st.find(x+1)!= st.end())
            {
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;

}

int main()
{
    return 0;
}

