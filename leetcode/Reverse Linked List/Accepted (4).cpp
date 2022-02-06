/****************************************************************************************
*  @author: kzvd4729                                         created: 04/13/2021 14:19                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 8 ms                                            memory_used: 8.4 MB                               
*  problem: https://leetcode.com/problems/reverse-linked-list
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
    ListNode* reverseList(ListNode* head) {
                ListNode *prv= NULL;
        while(head!=NULL)
        {
            ListNode* nxt= head->next;
            head->next=prv;
                        prv=head;
            head=nxt;
        }
        return prv;
    }
};