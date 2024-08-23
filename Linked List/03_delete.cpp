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

Node* delHead(Node* head)
{
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* removeTail(Node* head)
{
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;

    return head;
}

void deleteNode(Node* node) {
    // Write your code here.
    if(node==NULL || node->next==NULL) return;
    node->data=node->next->data;
    Node* temp=node->next;
    node->next=node->next->next;
    delete temp;
}

Node* removeK(Node* head, int k)
{
    if(head==NULL) return head;
    if(k==1)
    {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k)
        {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

}

Node* removeEl(Node* head, int el)
{
    if(head==NULL) return head;
    if(head->data==el)
    {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==el)
        {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {12,5,7,8};
    Node* head=convertLL(arr);
    // head = delHead(head);
    // head=removeTail(head);
    // head= removeK(head,2);
    head=removeEl(head,12);
    print(head);

    return 0;
}
