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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* h1=NULL;
        ListNode* h2=NULL;
        ListNode* h1_temp=NULL;
        ListNode* h2_temp=NULL;
        if(head==NULL)
        {
            return head;
        }
        while(temp!=NULL)
        {
            if(temp->val < x)
            {
                if(h1==NULL)
                {
                    h1=temp;
                    h1_temp=h1;
                }
                else
                {
                    h1_temp->next=temp;
                    h1_temp = h1_temp->next;
                }
            }
            else
            {
                if(h2==NULL)
                {
                    h2=temp;
                    h2_temp=h2;
                }
                else
                {
                    h2_temp->next=temp;
                    h2_temp = h2_temp->next;
                }
            }
            temp=temp->next;
        }
        if(h1==NULL)
        {
            return h2;
        }
        if(h2!=NULL)
        {
            h2_temp->next = NULL;
            h1_temp->next=h2;
        }
        return h1;
        
    }
};