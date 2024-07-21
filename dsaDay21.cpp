#include<bits/stdc++.h>
using namespace std;

/*
    Largest odd number in string
    input="35427"
    output="35427"
*/

string largestOddNum(string num)
{
    int n=num.length();
    for(int i=n-1;i>=0;i--)
    {
        if(num[i]%2!=0)
        return num.substr(0,i+1);
    }

    return "";
}

/*
    Longest common prefix
    Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

string longestCommonPrefix(vector<string> &str)
{
    string ans="";
    int n=str.size();
    if(n==0) return ans;
    sort(str.begin(), str.end());
    string first=str[0], last=str[n-1];
    for(int i=0;i<min(first.size(), last.size());i++)
    {
        if(first[i]!=last[i]) return ans;

        ans+=last[i];
    }
    return ans;
}

/*
    Isomorphic strings
    Input: s = "egg", t = "add"
Output: true
t.length == s.length
*/

bool isIsomorphic(string s, string t)
{
    int m=s.length();
    unordered_map<char, char> map1, map2;
    for(int i=0;i<m;i++)
    {
        char ch1=s[i];
        char ch2=t[i];
        if(map1.find(ch1)!=map1.end() && map1[ch1]!=ch2 ||
           map2.find(ch2)!=map2.end() && map2[ch2]!=ch1)
           return false;
        
        map1[ch1]=ch2;
        map2[ch2]=ch1;
    }
    return true;

}
int main()
{
    string st1;
    cin>>st1;
    string st2;
    cin>>st2;
    cout<<isIsomorphic(st1, st2); 

    // vector<string> str = {"flower", "fake", "flow"};
    // cout<<longestCommonPrefix(str);

    // string number="35427";
    // cout<<largestOddNum(number);
    return 0;
}