#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        data=0;
        next=nullptr;
    }
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
    Node(int data1, Node* next1)
    {
        data=data1;
        next=next1;
    }
};

Node* convertArrtoLL(vector<int>&arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int lengthOfLL(Node* head)
{
    int cnt=0;
    Node* temp = head;
    while(temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int search(Node* head, int val)
{
    Node* temp=head;
    while(temp)
    {
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
}
int main()
{
    vector<int>arr={1,3,2,5};
    Node* head = convertArrtoLL(arr);
    // cout<<lengthOfLL(head);
    cout<<search(head,2);
    // Traversal in Linked List
    // Node* temp=head;
    // while(temp)
    // {
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    // cout<<head->data;
    return 0;
}

