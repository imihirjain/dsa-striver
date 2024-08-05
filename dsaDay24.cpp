#include<bits/stdc++.h>
using namespace std;

/*
    String to Integer
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
*/

int myAtoi(string s)
{
    int n=s.length();
    if(n==0) return 0;
    int i=0;
    while(i<n && s[i]==' ') i++;
    int sign=1;
    if(i<n && (s[i]=='+' || s[i]=='-'))
    {
        sign=(s[i]=='-')?-1:1;
        i++;
    }
    long long ans=0;
    int Max=INT_MAX;
    int Min=INT_MIN;
    while(i<n && !isdigit(s[i]))
    {
        ans=ans*10+s[i]-'0';
        if(i<n && -ans<Min) return Min;
        if(i<n && ans>Max) return Max;

        i++;
    }
    return (int)sign*ans;
}


/*
    Sum of Beauty of All substrings
    The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
*/

int beautySum(string s)
{
    int n=s.length();
    int totalBeauty=0;
    for(int i=0;i<n;i++)
    {
        unordered_map<char, int>freq;
        for(int j=i;j<n;j++)
        {
            int maxFreq=0, minFreq=INT_MAX;
            freq[s[j]]++;
            for(auto res:freq)
            {
                maxFreq=max(maxFreq, res.second);
                minFreq=min(minFreq, res.second);
            }
            totalBeauty+=(maxFreq-minFreq);
        }
    }
    return totalBeauty;
}

/*
    Longest Palindromic Substring
    Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/

string longestPalindrome(string s)
{
    int n=s.length();
    if(n==0) return "";
    int start=0; 
    int maxi=1;
    auto expand = [&](int left, int right)
    {
        while(left>=0 && right<n && s[left]==s[right])
        {
            left--;
            right++;
        }
        int length=right-left-1;
        if(length>maxi)
        {
            start=left+1;
            maxi=length;
        }
    };  

    for(int i=0;i<n;i++)
    {
        expand(i,i);
        expand(i,i+1);
    }

    string ans = s.substr(start, maxi);

    return ans;
}

/*
    Count number of Substrings;
    Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Example 1:

Input: S = "aba", K = 2
Output:3
Explanation:The substrings are: "ab", "ba" and "aba".
Input: S = "abaaca", K = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a". 
*/
long long upto(string s, int k)
{
    int n = s.length();
    int left=0, right=0, cnt=0;
    long long ans=0;
    vector<int> mp(26,0);
    while(right<n)
    {
        mp[s[right]-'a']++;
        if(mp[s[right]-'a'==1]) cnt++;
        while(cnt>k)
        {
            mp[s[left]-'a']--;
            if(mp[s[left]-'a']<=0)cnt--;
            left++;
        }
        ans+=right-left+1;
        right++;
    }
    return ans;
}

long long int substrCount(string s, int k)
{
    return upto(s,k)-upto(s,k-1);
}
int main()
{
    return 0;
}

