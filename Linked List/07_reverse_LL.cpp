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
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* convert2LL(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node* reverse2LL(Node* head)
{
    if(head==NULL || head->next==NULL) return head;
    Node* last = NULL;
    Node* current=head;
    while(current!=NULL)
    {
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    Node* newNode = last->back;
    return newNode;

}

int main()
{   
    vector<int>arr={12,4,5,8};
    Node* head = convert2LL(arr);
    head = reverse2LL(head);
    print(head);
    return 0;
}
