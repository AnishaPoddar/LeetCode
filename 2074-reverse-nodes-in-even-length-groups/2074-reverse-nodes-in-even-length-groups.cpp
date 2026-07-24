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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL)
        {
        ListNode* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int i=1;
        int j;
        ListNode* temp=head;
        ListNode* prevh=NULL;
        ListNode* prevconn=NULL;
        ListNode* nh=NULL;
        ListNode* prev=NULL;
        while(temp!=NULL)
        {
            prevh=prev;
            nh=temp;
            for(j=1; j<=i && temp!=NULL; j++)
            {    
                prev=temp;
                temp=temp->next;
            }
            int len=j-1;
            if(len%2==0)
            {
                prev->next=NULL;
                ListNode* newHead = reverseList(nh);
                if(prevh==NULL)
                    head = newHead;         
                else
                    prevh->next = newHead;
                nh->next=temp;
                prev = nh;                  
            }
                i++;
    }
     return head;
}
};