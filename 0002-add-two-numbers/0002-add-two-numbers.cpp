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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* output=new ListNode();
        ListNode* final=output;
        while(temp1!=NULL || temp2!=NULL)
        {
            ListNode* newnode=new ListNode();
            if(temp1!=NULL && temp2!=NULL)
            {
            newnode->val=(temp1->val+ temp2->val + carry)%10;
            carry=(temp1->val+ temp2->val + carry)/10;
            newnode->next=NULL;
            output->next=newnode;
            }
            else if(temp1==NULL)
            {newnode->val=( temp2->val + carry)%10;
            carry=(temp2->val + carry)/10;
            newnode->next=NULL;
            output->next=newnode;
            }
            else
            {
            newnode->val=( temp1->val + carry)%10;
            carry=(temp1->val + carry)/10;
            newnode->next=NULL;
            output->next=newnode;
            }
            
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
            output=newnode;  
        }
        if(carry==1)
        {
            ListNode* newnode = new ListNode(carry);;
            newnode->val=carry;
            newnode->next=NULL;
            output->next=newnode;
        }

        return final->next;
        
    }
};