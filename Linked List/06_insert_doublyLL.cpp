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

Node* insertBeforeHead(Node* head, int val)
{
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int val)
{
    if(head->next==NULL) return insertBeforeHead(head, val);
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    
    return head;
}

Node* insertBeforeKth(Node* head, int val, int k)
{
    if(k==1) return insertBeforeHead(head, val);
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val, temp, prev);
    prev->next=newNode;
    temp->back=newNode;

    return head;
}

void insertBeforeNode(Node* node, int val)
{
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next=newNode;
    node->back=newNode;
}
int main()
{
    vector<int>arr = {12,5,6,8};
    Node* head = convertDLL(arr);
    // head=insertBeforeHead(head,100);
    // head=insertBeforeTail(head,100);
    // head=insertBeforeKth(head,50,3);
    insertBeforeNode(head->next->next,50);
    print(head);
    return 0;
}
