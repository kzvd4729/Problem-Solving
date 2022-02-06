/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 00:43                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 60 ms                                           memory_used: 71.5 MB                              
*  problem: https://leetcode.com/problems/add-two-numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int c=0) 
    {
                if(l1==NULL && l2==NULL && c==0)return NULL;
                if(l1!=NULL)
        {
            c+=l1->val;l1=l1->next;
        }
        if(l2!=NULL)
        {
            c+=l2->val;l2=l2->next;
        }
                ListNode* ret=new ListNode(c%10);
                ret->next=addTwoNumbers(l1, l2,c/10); 
                return ret;
    }
};