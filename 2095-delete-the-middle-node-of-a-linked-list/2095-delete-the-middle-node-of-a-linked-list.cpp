/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c=c+1;
            temp=temp->next;
        }
        int mid=c/2+1;
        temp=head;
        for(int i=1; i<=(mid-2); i++)
        {
        temp=temp->next;
        }
        ListNode* n=temp->next;
        temp->next=n->next;
        delete(n);

        return head;
        
    }
};