#include<bits/stdc++.h>
using namespace std;

/*
    Set matrix zero
*/

vector<vector<int>> setMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int row[n]={0};
    int col[m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i]||col[j])
            {
                matrix[i][j]=0;
            }
        }
    }

    return matrix;
}

// Set matrix solution 2 of leetcode
void setMatrix2(vector<vector<int>> &matrix)
{
    int col0=1, rows=matrix.size(), cols = matrix[0].size();

    for(int i=0;i<rows;i++)
    {
        if(matrix[i][0]==0) col0=0;
        for(int j=1;j<cols;j++)
        {
            if(matrix[i][j]==0)
            matrix[i][0] = matrix[0][j]=0;
        }
    }

    for(int i=rows-1;i>=0;i--)
    {
        for(int j=cols-1;j>=1;j--)
        {
            if(matrix[i][0]==0||matrix[0][j]==0)
            {
                matrix[i][j]=0;
            }
        }
        if(col0==0) matrix[i][0]=0;
    }
}

/*
    Rotate Image/Matrix by 90 degree
    Input:
 [[1,2,3],[4,5,6],[7,8,9]]

Output
: [[7,4,1],[8,5,2],[9,6,3]]
*/

vector<vector<int>> rotate(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

/*
    Spiral Traversal of Matrix
    Input: Matrix[][] = { { 1, 2, 3, 4 },
		      { 5, 6, 7, 8 },
		      { 9, 10, 11, 12 },
	              { 13, 14, 15, 16 } }

Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.
*/

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int left = 0, right=m-1;
    int top = 0, bottom = n-1;
    vector<int> ans;
    while(left<=right && top<=bottom)
    {
        // Traverse right
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Traverse bottom
        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Traverse left
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse top
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
}

/*
    Count Subarray sum Equals K
    Input Format:
 N = 4, array[] = {3, 1, 2, 4}, k = 6
Result:
 2
*/

int subarraySum(vector<int> &nums, int k)
{
    int n=nums.size();
    unordered_map<int, int> mpp;
    mpp[0]=1;
    int cnt=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum +=nums[i];
        int remove = sum-k;
        cnt +=mpp[remove];
        mpp[sum] +=1;
    }
    return cnt;
}

int main()
{
    return 0;
}

