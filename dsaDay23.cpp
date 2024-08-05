#include<bits/stdc++.h>
using namespace std;

/*
    Sort character by frequency
    Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/
typedef pair<char, int>P;
string frequency(string s)
{
    vector<P>v(123);
    for(auto ch:s)
    {
        int freq = v[ch].second;
        v[ch]={ch, freq++};
    }

    auto lambda = [&](P&p1, P&p2)
    {
        return p1.second > p2.second;
    };

    sort(v.begin(), v.end(), lambda);

    string res="";
    for(int i=0;i<123;i++)
    {
        if(v[i].second>0)
        {
            char ch=v[i].first;
            int freq = v[i].second;
            string temp = string(freq,ch);
            res+=temp;
        }
    }
    return res;
}


/*
    Maximum nesting depth of paranthesis
    Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.
*/

int maxDepth(string s)
{   int result=0;
    stack<int>st;
    for(auto ch:s)
    {
        if(s[ch]=='(') st.push(s[ch]);
        else if(s[ch]==')') st.pop();

        result = max(result, (int)st.size());
    }
    return result;

    // Second method;
    int openBr=0;
    int result=0;
    for(auto ch:s)
    {
        if(s[ch]=='(') openBr++;
        else if(s[ch]==')')openBr--;

        result=max(result, openBr);
    }
    return result;
}



int main()
{
    return 0;
}
