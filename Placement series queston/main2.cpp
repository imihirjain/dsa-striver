#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return 0;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           
            fast = fast->next->next;     

            if (slow == fast) {
                return 1; 
            }
        }

        return 0; 
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = head2->next;  

    Solution solution;
    
    cout << solution.hasCycle(head1)<<" ";
    cout << solution.hasCycle(head2);
    
    delete head1->next->next;
    delete head1->next;
    delete head1;


    return 0;
}
