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

Node* removeHead(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    temp->next=nullptr;
    head->back=nullptr;
    free(temp);

    return head;
}

Node* removeTail(Node* head)
{
    if(head==NULL || head->next==NULL) return NULL;
    Node* tail=head;
    while(tail->next!=NULL) tail=tail->next;
    Node* prev = tail->back;
    prev->next=nullptr;
    tail->back=nullptr;
    delete tail;

    return head;
}

Node* removeKth(Node* head, int k)
{
    if(head==NULL) return NULL;
    Node* kNode= head;
    int cnt=0;
    while(kNode!=NULL)
    {
        cnt++;
        if(cnt==k) break;
        kNode=kNode->next;
    }

    Node* prev = kNode->back;
    Node* front= kNode->next;
    if(prev==NULL && front==NULL) return NULL;
    else if(prev==NULL) return removeHead(head);
    else if(front == NULL) return removeTail(head);
    prev->next=front;
    front->back=prev;
    kNode->next=nullptr;
    kNode->back=nullptr;
    delete kNode;
    return head;
}

void deleteNode(Node* temp)
{
    Node*prev=temp->back;
    Node*front=temp->next;

    if(front==NULL)
    {
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return;
    }

    prev->next=front;
    front->back=prev;
    temp->next=temp->back=nullptr;
    delete temp;
}

int main()
    {   vector<int>arr = {12,5,6,8};
        Node* head = convertDLL(arr);
    // head = removeHead(head);
    // head=removeTail(head);
    // head=removeKth(head,4);
    deleteNode(head->next->next->next);
    print(head);
    return 0;
}