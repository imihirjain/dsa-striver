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
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* convertLL(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* insertHead(Node* head, int val)
{
    Node* temp=new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val)
{
    if(head==NULL) return new Node(val);
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    Node* newNode = new Node(val);
    temp->next=newNode;
    return head;
}

Node* insertPos(Node* head, int el, int k)
{
    if(head==NULL)
    {
        if(k==1) return new Node(el);
        else return head;
    }
    if(k==1) return new Node(el, head);

    Node* temp=head; 
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k-1)
        {
            Node* newNode=new Node(el,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeVal(Node* head, int el, int val)
{
    if(head==NULL) return NULL;
    if(head->data==val) return new Node(el, head);
    Node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->data==val)
        {
            Node* newNode = new Node(el,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {12,5,7,8};
    Node* head=convertLL(arr);
    // head=insertHead(head, 100);
    // head=insertTail(head, 500);
    // head=insertPos(head,400,3);
    head=insertBeforeVal(head,1000,5);
    print(head);
    return 0;
}
