/****************************************************************************************
*  @author: kzvd4729                                         created: 07/13/2021 15:51                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 12 ms                                           memory_used: 14.9 MB                              
*  problem: https://leetcode.com/problems/merge-two-sorted-lists
****************************************************************************************/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
                ListNode* root=new ListNode(INT_MIN);
        ListNode* prv=root;
                while(true)
        {
            if(l1==NULL)
            {
                prv->next=l2;
                return root->next;
            }
            if(l2==NULL)
            {
                prv->next=l1;
                return root->next;
            }
                        if(l1->val < l2->val)
            {
                prv->next=l1;
                prv=l1;
                l1=l1->next;
            }
            else
            {
                prv->next=l2;
                prv=l2;
                l2=l2->next;
            }
        }
        return NULL;
    }
};