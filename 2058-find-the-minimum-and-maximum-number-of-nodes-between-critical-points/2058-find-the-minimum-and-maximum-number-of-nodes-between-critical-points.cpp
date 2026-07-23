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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        if(head==NULL || head->next==NULL)
        {
            return ans;
        }
        int min_dis=INT_MAX;
        int prev_index=-1;
        int first_index=-1;
        int max_dis=0;
        int c=0;
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* next=head->next;
        while(next!=NULL)
        {
            c=c+1;
            if((prev!=NULL && prev->val> temp->val && next->val> temp->val)|| (prev!=NULL && prev->val < temp->val && next->val < temp->val ))
            {
                if(first_index==-1)
                {
                    first_index = c;
                    prev_index = c;
                }
                else
                {
                    min_dis=min(min_dis, c-prev_index);
                    max_dis=max(max_dis, c-first_index);
                    prev_index=c;
                }
                
            }
            prev = temp;
            temp = next;
            if(next != NULL)
            {
                next = next->next;
            }
        }
        if(first_index == -1 || first_index == prev_index)
        return {-1,-1};
        ans[0]=min_dis;
        ans[1]=max_dis;
        return ans;

    }
};