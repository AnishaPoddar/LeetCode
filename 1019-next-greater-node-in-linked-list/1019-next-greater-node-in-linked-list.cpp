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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* temp=head;
        int flag;
        while(temp!=NULL)
        {
            ListNode* cur=temp->next;
            while(cur!=NULL)
            {
                flag=1;
                if(cur->val > temp->val)
                {
                    flag=0;
                    ans.push_back(cur->val);
                    break;
                }
                cur=cur->next;
            }
            if(flag==1 || temp->next==NULL)
            {
                ans.push_back(0);
            }
            temp=temp->next;
        }
        return ans;
        
    }
};