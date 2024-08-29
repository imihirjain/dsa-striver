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
