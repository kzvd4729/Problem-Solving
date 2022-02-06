/****************************************************************************************
*  @author: kzvd4729                                         created: 07/13/2021 17:39                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* tmp=head;
                while(tmp && tmp->next)
        {
            if(tmp->val==(tmp->next)->val)tmp->next=(tmp->next)->next;
            tmp=tmp->next;
        }
                return head;
            }
};