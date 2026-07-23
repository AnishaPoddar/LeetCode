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
        ListNode* aNode=nullptr;
        ListNode* bNode=nullptr;
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
        while(list2->next != NULL)
         {
         list2 = list2->next;
         }
         list2->next = bNode->next;
        bNode->next=NULL;
        return list1;   
    }
};