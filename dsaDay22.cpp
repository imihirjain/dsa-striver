#include<bits/stdc++.h>
using namespace std;

/*
    Rotate the string
    Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
*/

bool rotateString(string s, string goal)
{
    queue<char>q1,q2;
    for(int i=0;i<s.size();i++)
    q1.push(s[i]);
    for(int i=0;i<goal.size();i++)
    q2.push(goal[i]);
    if(q1==q2) return true;
    int k=goal.size()-1;
    while(k!=0)
    {
        char ch=q2.front();
        q2.pop();
        q2.push(ch);

        if(q1==q2) return true;
        
        k--;
    }
    return false;

    // Another method
    if(s.size()!=goal.size()) return false;

    string concat = s+s;
    return concat.find(goal)!=string::npos; 
}

/*
    check strings are anagram or not
    Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

bool isAnagram(string s, string t)
{
    int count[26]={0};
    for(auto x:s)
    count[x-'a']++;
    for(auto x:t) count[x-'a']--;
    for(auto res:count) 
    if(res!=0) return false;

    return true;
}


/*
    Roman to integer
*/

int value(char r)
{
    if(r=='I') return 1;
    if(r=='V') return 5;
    if(r=='X') return 10;
    if(r=='L') return 50;
    if(r=='C') return 100;
    if(r=='D') return 500;
    if(r=='M') return 1000;

    return -1;
}
int romToInt(string s)
{
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        int s1=value(s[i]);
        if(i+1<s.size())
        {
            int s2=value(s[i+1]);
            if(s1>=s2)
            res+=s1;
            else
            {res+=s2-s1;
            i++;
            }
        }
        else
        res+=s1;
    }
    return res;
}
int main()
{
    return 0;
}
