#include<bits/stdc++.h>
using namespace std;

/*
    Reverse Words in a string
    input = i.like.this.program.very.much
    output = much.very.program.this.like.i
*/

string reverseWords(string s)
{
   string ans=s;
   int n=s.length();
   reverse(ans.begin(), ans.end());
   int j=0;
   for(int i=0;i<n;i++)
   {
    if(ans[i]=='.')
    {
        reverse(ans.begin()+j, ans.begin()+i);
        j=i+1;
    }
   }
   reverse(ans.begin()+j, ans.end());
   return ans;
}

/*
    Remove Outermost paranthesis
    input = (()())(())
    output = ()()()
*/

string removeParanthesis(string s)
{
    int n=s.length();
    int cnt=0;
    string ans;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            if(cnt>0)
            ans+=s[i];
            cnt++;
        }
        else{
            cnt--;
            if(cnt>0)
            ans+=s[i];
        }
    }
    return ans;
}


/*
    Reverse Word in string with space
    input=  the sky is blue
    output= blue is sky the
*/

string reverseWord(string s)
{
    int n=s.length();
    int i=0;
    string ans;
    while(i<n)
    {
        while(i<n && s[i]==' ')i++;
        if(i>=n) break;
        int j=i+1;
        while(j<n && s[i]!=' ')j++;
        string sub = s.substr(i,j-i);
        if(ans.length()==0) ans=sub;
        else ans = sub + " " + ans;
        i=j+1;
    }
    return ans;

}
int main()
{

}