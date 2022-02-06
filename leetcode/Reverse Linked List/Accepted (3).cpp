/****************************************************************************************
*  @author: kzvd4729                                         created: 04/13/2021 14:20                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 8.3 MB                               
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
        ListNode *nxt;
        while(head!=NULL)
        {
            nxt= head->next;
            head->next=prv;
                        prv=head;
            head=nxt;
                        //delete nxt;
        }
        return prv;
    }
};