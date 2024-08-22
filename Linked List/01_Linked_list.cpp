#include<bits/stdc++.h>
using namespace std;

// struct Node
class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1)
    {
        data=data1;
        next=next1;
    }

    public:
    Node(int data2)
    {
        data=data2;
        next=nullptr;
    }
};

int main()
{
    vector<int> arr={1,3,2,5};
    // Node* y = new Node(arr[2], nullptr);
    Node* z = new Node(arr[1]);
    // cout<<z->data;
    cout<<z->next;
    // cout<<y;
    // cout<<y->data;
    // cout<<y->next;
    return 0;
}
