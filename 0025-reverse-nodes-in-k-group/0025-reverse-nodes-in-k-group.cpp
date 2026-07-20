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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* new_head=head;
        ListNode* t2=head;
        ListNode* rt;
        ListNode* prevTail = NULL; 

        int count=0;
        while(temp!=NULL)
        {
            count+=1;
            if(count%k==0)
            {
                ListNode* prevNode=temp;
                 ListNode* nextNode=prevNode->next;
                prevNode->next=NULL;
                rt=reverseList(t2);
                
                if(count==k)
                {
                    new_head=rt;
                }
                else
                {
                   prevTail->next=rt;
                }
                prevTail = t2;                   
                prevTail->next = nextNode;        

                t2 = nextNode;
                temp = nextNode;         
            }
            else
            {
                temp = temp->next;
            }

        }
        return new_head;   
    }
};