/****************************************************************************************
*  @author: kzvd4729                                         created: 07/13/2021 17:35                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 12 ms                                           memory_used: 11.8 MB                              
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
        if(head==NULL)return head;
        if(head->next==NULL)return head;
                deleteDuplicates(head->next);
                        if(head->val==(head->next)->val)
        {
            ListNode* tmp=head->next;
            head->next=(head->next)->next;
                        delete tmp;
        }
        return head;
    }
};