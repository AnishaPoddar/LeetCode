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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* t;
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        if(list1->val <= list2->val)
        {
            head=temp1;
            t=temp1;
            temp1=temp1->next;   
        }
        else
        {
            head=temp2;
            t=temp2;
            temp2=temp2->next;
        }
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val>= temp2->val)
            {
                t->next=temp2;
                temp2=temp2->next;
            }
            else
            {
                t->next=temp1;
                temp1=temp1->next;
            }
            t=t->next;
        }
        while(temp1!=NULL)
        {
            t->next=temp1;
            temp1=temp1->next;
            t=t->next;
        }
        while(temp2!=NULL)
        {
            t->next=temp2;
            temp2=temp2->next;
            t=t->next;
        }
        t->next=NULL;
        return head;   
    }
};