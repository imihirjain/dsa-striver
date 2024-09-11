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

Node* reverseLL(Node* head)
{
    if(head==NULL || head->next==NULL) return head;
    Node* newHead=reverseLL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

bool isPalindrome(Node* head)
{
    if(head==NULL || head->next==NULL) return true;
    // step 1 find middle
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    // step 2 reverse second half
    Node* newHead=reverseLL(slow->next);
    // step 3 compare first half and reversed second half
    Node* first=head;
    Node* second=newHead;
    while(second!=NULL)
    {
        if(first->data!=second->data)
        {
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newHead);
    return true;
}
int main()
{
    vector<int> arr = {1,2,3,4,2,1};
    Node* head=convertArrtoLL(arr);
    bool result=isPalindrome(head);
    cout<<result;
    return 0;
}
