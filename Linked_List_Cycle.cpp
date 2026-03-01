#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow , *fast;
        slow=head;
        fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            // fast=fast->next;
            if(fast==slow)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    head->next->next->next->next->next=head->next->next;

    Solution sol;
    bool cycle = sol.hasCycle(head);
    if(cycle)
    {
        cout<<"Cycle Present"<<endl;
    }
    else
    {
        cout<<"Cycle is not present"<<endl;
    }
}