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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=NULL)
        {
         ListNode* next = temp->next;
         temp->next = prev;  
         prev=temp;
         temp=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(left == right)
            return head;
        ListNode* l=nullptr;
        ListNode* prev_left=nullptr;
        ListNode* r=nullptr;
        ListNode* next_right=nullptr;
        ListNode* temp=head;
        int c=0;
        while(c<right)
        {
            c=c+1;
            if(c == left)
            {
                l = temp;
            }
            if(c == left - 1)
            {
                prev_left = temp;
            }
            if(c==right)
            {
                r=temp;
                next_right=temp->next;

            }
            temp=temp->next;
        }
        r->next=NULL;
        ListNode* newHead = reverseList(l);
        if(prev_left!=NULL)
        {
            prev_left->next=newHead;
        }
        else
        {
            head=newHead;
        }
        l->next=next_right;
        return head;
    }
};