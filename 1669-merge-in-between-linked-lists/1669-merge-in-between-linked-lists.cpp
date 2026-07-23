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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        ListNode* temp2=list2;
        ListNode* aNode;
        ListNode* bNode;
        int c=0;
        while(c<=b && temp!=NULL)
        {
            c=c+1;
            if(c==a)
            {
                aNode=temp;
            }
            temp=temp->next;
            if(c==b)
            {
                bNode=temp;
            }
        }
        aNode->next=list2;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=bNode->next;
        bNode->next=NULL;
        return list1;   
    }
};