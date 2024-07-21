#include<bits/stdc++.h>
using namespace std;

int getLength(char arr[], int size)
{
    int cnt=0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]=='\0') break;
        else cnt++;
    }     
    
    return cnt;
}

void replaceCharacter(char original, char newchar, char arr[], int size)
{
    int len=getLength(arr, size);
    for(int i=0;i<len;i++)
    {
        if(arr[i]==original)
        {
            arr[i]=newchar;
        }
    }
}

void convertIntoUpper(char arr[], int size)
{
    int len = getLength(arr,size);
    for(int i=0;i<len;i++)
    {
       char ch=arr[i];
       if(ch>='a' && ch<='z')
       {
        ch = ch-'a'+'A';
       }
        arr[i]=ch;
    }
}

void convertIntoLower(char arr[], int size)
{
    int len=getLength(arr,size);
    for(int i=0;i<len;i++)
    {
        char ch=arr[i];
        if(ch>='A' && ch<='Z')
        {
            ch = ch-'A'+'a';
        }
        arr[i]=ch;
    }
}

void reverseCharArray(char arr[], int size)
{
    int len = getLength(arr,size);
    int i=0;
    int j=len-1;
    while(i<=j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

bool checkPalindrome(char arr[], int size)
{
    int len = getLength(arr,size);
    int i=0;
    int j=len-1;
    while(i<=j)
    {
        if(arr[i]==arr[j])
        {
            i++;
            j--;
        }
        else return false;
    }
    return true;
}
int main()
{

    string str1="I am mihir jain and i am full stack web developer";
    string str2 = "full stack";
    cout<<str1.find(str2);

    // string name = "Mihir Jain";
    // auto it = name.begin();

    // while(it!= name.end())
    // {
    //     cout<<*it;
    //     it++;
    // }

    // char arr[100];
    // cin>>arr;
    // cout<< checkPalindrome(arr,100)<<endl;
    // cout<<arr<<endl;
    // reverseCharArray(arr,100);
    // convertIntoLower(arr,100);
    // converIntoUpper(arr,100);
    // replaceCharacter('@',' ', arr, 100);
    // cout<<getLength(arr,100)<<endl;
    return 0;
}
