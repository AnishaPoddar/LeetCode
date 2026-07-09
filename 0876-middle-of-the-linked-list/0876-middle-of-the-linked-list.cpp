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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c=c+1;
            temp=temp->next;
        }
        int p=c/2 +1 ;
        temp=head;
        for(int i=1 ; i<=p-1 ; i++)
        {
            temp=temp->next;
        }
        return temp;
        
    }
};