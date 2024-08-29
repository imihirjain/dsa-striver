#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* back;

    Node()
    {
        data=0;
        next=nullptr;
        back=nullptr;
    }

    Node(int data1)
    {
        data=data1;
        next=nullptr;
        back=nullptr;
    }

    Node(int data1, Node* next1, Node* back1)
    {
        data=data1;
        next=next1;
        back=back1;
    }
};

void print(Node* head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* convertDLL(vector<int> &arr)
{
    Node* head= new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev=temp;
    }

    return head;
}

Node* middleLL(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main()
{
    return 0;
}
